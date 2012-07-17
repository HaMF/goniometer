#include <stdio.h>
#include <ncurses.h>

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

void interrupt_advance(uint8_t interrupt_mask, uint8_t value_mask) {
    //printf("Interrupt by: %d\n", interrupt_mask);
    //printf("Value: %d\n", value_mask);
     
    //stepper_set_steps(&stepper, nStepsPerInterrupt); // Drive 100 steps forward
    nSteps += nStepsPerInterrupt;
    printw("Number of steps performed: %d\n", nSteps);
    fflush(stdout);
}

void interrupt_home() { 
    //stepper_set_steps(&stepper, -nSteps);
    nSteps = 0;
    printw("Number of steps performed: %d\n", nSteps);
    fflush(stdout);
}

int main() {
    char c;
        
    initscr();
    clear();
    noecho();
    cbreak();   
    
    // Create IP connection to brickd
    printw("Waiting for TTL interrupts.\n Press h to go to the home position.\n Press H to set current position as home.\n Press s to advance.\n Press q to quit and display statistics\n");    
    
    while((c = getch()) != 'c') {
        if(c=='a')
          interrupt_advance(0,0);
        if(c=='h')  
          interrupt_home();
        if(c=='H')  
          nSteps = 0;
    }
    
//    ipcon_destroy(&ipcon);
    endwin();
    
    printf("Statistics");
    return 0;
}
