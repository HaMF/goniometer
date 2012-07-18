/*Copyright (C) 2012 Hannes Maier-Flaig

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/* 
This is a simple script that is intended to be used with the tinkerforge (http://tinkerforge.com) stepper brick and the IO4 bricklet.

Purpose of the setup is to let a stepper motor advance a certain amount of steps everytime a TTL pulse is registered at pin 0 of the IO4 bricklet. In addition to that the current position is registered as No. of steps and angle (using a specified gear ratio). Furthermore, one can set and return to a "home" position.

This (and some mechanical parts) form an automatic goinometer for an Brucker EPR spectrometer.

ROADMAP:
  + Record positions for every TTL pulse in sensible file format
  + Add commandline parameters to set gear ratio, step size, …
  + Use sensible folder structure and improve makefile
  + Use time of TTL pulse to determine step width
  + Regain platform independance (move away from ncurses)
  + Add and LCD, pysical buttons for home and step size and implement a stand-alone solution (maybe…)
*/

#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

#include "ip_connection.h"
#include "bricklet_io4.h"
#include "brick_stepper.h"

#define HOST "localhost"
#define PORT 4223
#define IO4_UID "XYZ" // IO4 UID
#define STEPPER_UID "XYZ" // Stepper UID

Stepper stepper;
IO4 io;
int nSteps = 0;
int nStepsPerInterrupt = 10;
double gearRatio = 2; // gear ratio > 1 means motor gear has less teeth

void print_stats() {
    printw("\rNumber of steps performed: %3d (%6.2fdeg)", nSteps, ((float)nSteps)/gearRatio);
    fflush(stdout);
}

bool is_motor_ready() {
    int32_t rem_steps = 0;
    stepper_get_remaining_steps(&stepper, &rem_steps) ;
    if(rem_steps != 0) {
        printw("\rInterrupt request ignored because motor was still running\n");
        print_stats();
        return false;
    } else {
        return true;
    }
}


void advance() {
    if( ! is_motor_ready())
      return;
      
    stepper_set_steps(&stepper, nStepsPerInterrupt); // Drive 100 steps forward
    nSteps += nStepsPerInterrupt;
    
    print_stats();
}


void go_home() {
    if( ! is_motor_ready())
      return;
      
    printw("\rGoing home from position %.2fdeg ...\n", ((float)nSteps)/gearRatio);
    stepper_set_steps(&stepper, -nSteps);
    nSteps = 0;
    
    print_stats();
}


void set_home() { 
    printw("\rSet current position (%.2fdeg) as new home ...\n", ((float)nSteps)/gearRatio);
    nSteps = 0;
    
    print_stats();
}


void dispatch_interrupts(uint8_t interrupt_mask, uint8_t value_mask) {
    if((1<<0) & interrupt_mask) {
        // interrupt on pin 0 -> advance if pin is high
        if(interrupt_mask & value_mask == 1) {
            advance();
        }
    }
    // Add interrupt handling for home and step size button here.
}

int main() {
    char c;
   
    // Establish IP connection to brick deamon brickd
    IPConnection ipcon;
    if(ipcon_create(&ipcon, HOST, PORT) < 0) {
        fprintf(stderr, "Could not create IP connection to brickd. Is brickd running?\n");
        exit(1);
    }

    // Create IO4-device object
    io4_create(&io, IO4_UID); 

    // Add IO4 to IP connection
    if(ipcon_add_device(&ipcon, &io) < 0) {
        fprintf(stderr, "Could not connect to IO4 bricklet\n");
        exit(1);
    }
    
    // Create stepper-device object
    stepper_create(&stepper, STEPPER_UID); 
    // Add device to IP connection
    if(ipcon_add_device(&ipcon, &stepper) < 0) {
        fprintf(stderr, "Could not connect to stepper brick\n");
        exit(1);
    }

    // Configure stepper driver
    stepper_set_motor_current(&stepper, 800); // 800mA
    stepper_set_step_mode(&stepper, 8); // 1/8 step mode
    stepper_set_max_velocity(&stepper, 2000); // Velocity 2000 steps/s
    stepper_set_speed_ramping(&stepper, 500, 500); // Slow acceleration & deacelleration (500 steps/s^2),     
    stepper_enable(&stepper);

  	// Enable interrupt on pin 0 
    io4_set_interrupt(&io, 1 << 0); // TTL pulses for advance go on pin 0
  	// io4_set_interrupt(&io, 1 << 1); // home button goes on pin 1
  	// io4_set_interrupt(&io, 1 << 2); // step size button goes on pin 2

	  // Register callback for interrupts
	  io4_register_callback(&io, IO4_CALLBACK_INTERRUPT, (void*)dispatch_interrupts);

    // Everything set. Lets use ncurses to display output and inputs nicely
    initscr();
    clear();
    noecho();
    
    printw("Gear ratio is set to %d \n", gearRatio);
    printw("Waiting for TTL interrupts.\n");
    printw(" Press h to go to the home position.\n Press H to set current position as home.\n Press a to advance.\n Press q to quit and display statistics\n");    
    
    while((c = getch()) != 'q') {
        if(c=='a')
            advance();
        if(c=='h')  
            go_home();
        if(c=='H')  
            set_home();
    }
    
    ipcon_destroy(&ipcon);
    endwin();
    
    printf("\rNumber of steps performed: %3d (%6.2fdeg)\n", nSteps, ((float)nSteps)/gearRatio);
    fflush(stdout);
    return 0;
}
