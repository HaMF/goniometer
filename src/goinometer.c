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
  + Record positions for every TTL pulse in sensible, simple file format
  + Add commandline parameters to set gear ratio, step size, …
  + Use sensible folder structure and improve makefile
  + Use time of TTL pulse to determine step width
  o Regain platform independance (move away from ncurses)
  o Add and LCD, pysical buttons for home and step size and implement a stand-alone solution (maybe…)
  o check for integer overflows on interrupts (unlikely to occur but who knows)
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <getopt.h>

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
int nStepsPerInterrupt; // default is set when parsing arguments
float gear_ratio = 2; // gear ratio > 1 means motor gear has less teeth
int dynamic_flag, record_flag;
int last_value_mask;
int last_interrupt_time_pin0 = 0;

void print_stats() {
    printw("\rNumber of steps performed: %3d (%6.2fdeg)", nSteps, ((float)nSteps)/gear_ratio);
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


void advance(int steps) {
    if( ! is_motor_ready())
      return;
      
    stepper_set_steps(&stepper, steps); // Drive 100 steps forward
    nSteps += steps;
    
    print_stats();
}


void go_home() {
    if( ! is_motor_ready())
      return;
      
    printw("\rGoing home from position %.2fdeg ...\n", ((float)nSteps)/gear_ratio);
    stepper_set_steps(&stepper, -nSteps);
    nSteps = 0;
    
    print_stats();
}


void set_home() { 
    printw("\rSet current position (%.2fdeg) as new home ...\n", ((float)nSteps)/gear_ratio);
    nSteps = 0;
    
    print_stats();
}


void dispatch_interrupts(uint8_t interrupt_mask, uint8_t value_mask) {
    int interrupt_time = time(NULL);
    if((1<<0) & interrupt_mask) {
        // interrupt on pin 0 -> advance if pin is high
        if(interrupt_mask & value_mask == 1) {                
            if( ! dynamic_flag) {
                advance(nStepsPerInterrupt);
            } else if(last_interrupt_time_pin0 != 0) {
                advance((interrupt_time-last_interrupt_time_pin0)*gear_ratio/10.);
            }
        }
        last_interrupt_time_pin0 = interrupt_time;
    }
    // Add interrupt handling for home and step size button here.
        
    last_value_mask     = value_mask;
}


void display_usage() {
    printf("This program drives a stepper motor when a TTL pulse is registered on port 0 of a tinkerforge IO4 bricklet.\n\n");
    printf("Command line arguments:\n");
    printf("    -a,  --angle       Angle by wich motor advances on interrupt (default: 5)\n");
    printf("    -g,  --gear-ratio  Gear ratio between motor and sample rod (default: 2)\n");
    printf("    -d,  --dynamic     Dynamic mode: --angle is ignored and instead TTL pulse length is used. 10ms = 0.1deg\n");
    printf("    -r,  --record      Record the angular position after every interrupt\n");
}


void parse_arguments(int argc, char **argv) {
    int c;
    double avalue = 5; //default value for angle per interrupt
    int option_index = 0;

    while (1)
      {
       static struct option long_options[] =
         {
           {"dynamic",    no_argument, &dynamic_flag, 1},
           {"record",     no_argument, &record_flag,  1},
           {"angle",      required_argument, NULL, 'a'},
           {"gear-ratio", required_argument, NULL, 'g'},
           {NULL, 0, NULL, 0}
         };

       c = getopt_long (argc, argv, "dra:g:?h",
                        long_options, &option_index);

       if (c == -1)
       {
         break;
       }

       switch (c)
         {
         case 'a':
           if ( ! strtod(optarg, NULL) )
           {
             printf ("option -a requires a double as value\n");
             exit(1);
           }
           avalue = strtod(optarg, NULL); // nStepsPerInterrupt is set later to make sure gear_ratio is already set
           break;
         case 'g':
           if ( ! strtod(optarg, NULL) )
           {
             printf ("option -g requires a double as value\n");
             exit(1);
           }
           gear_ratio = strtod(optarg, NULL);
           break;
         case 'd':
           dynamic_flag = 1;
           break;
         case 'r':
           record_flag = 1;
           break;
         case 'h':
         case '?':
           display_usage();
           exit(0);
         default:
           break;
         }
      }
          
    nStepsPerInterrupt = avalue * gear_ratio;
}


int main(int argc, char **argv) {
    int c;
    
    parse_arguments(argc, argv);
   
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
//        exit(1);
    }
    
    // Create stepper-device object
    stepper_create(&stepper, STEPPER_UID); 
    // Add device to IP connection
    if(ipcon_add_device(&ipcon, &stepper) < 0) {
        fprintf(stderr, "Could not connect to stepper brick\n");
//        exit(1);
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
    
    if(dynamic_flag) {
        printw("Dynamic mode: The angle by which the motor advances corresponds to the TTL pulse length.\n");
        printw(" (Thats the time pin 0 is high. 10ms = 0.1deg). The step size argument will be ignored.\n");
    } else {
        printw("Steps per interrupt %d (%.2fdeg).\n", nStepsPerInterrupt, (float)nStepsPerInterrupt/gear_ratio);
    }
    printw("Gear ratio is set to %f \n", gear_ratio);
    printw("Waiting for TTL interrupts.\n");
    printw(" Press h to go to the home position.\n Press H to set current position as home.\n Press a to advance (A backwards).\n Press q to quit and display statistics\n");    

    while((c = getch()) != 'q') {
        if(c=='a')
            advance(nStepsPerInterrupt);
        if(c=='A')
            advance(-nStepsPerInterrupt);
        if(c=='h')  
            go_home();
        if(c=='H')  
            set_home();
    }
    
    // Disconnect from brickd
    ipcon_destroy(&ipcon);
    
    endwin();
        
    printf("\rNumber of steps performed: %3d (%6.2fdeg)\n", nSteps, ((float)nSteps)/gear_ratio);
    fflush(stdout);
    return 0;
}
