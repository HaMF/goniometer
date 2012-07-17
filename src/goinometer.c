
#include <stdio.h>

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

void interrupt_step(uint8_t interrupt_mask, uint8_t value_mask) {
    printf("Interrupt by: %d\n", interrupt_mask);
    printf("Value: %d\n", value_mask);

// Drive stepper 
    stepper_set_steps(&stepper, nStepsPerInterrupt); // Drive 100 steps forward
}


int main() {
    // Create IP connection to brickd
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
  	io4_set_interrupt(&io, 1 << 0),

	  // Register callback for interrupts
	  io4_register_callback(&io, IO4_CALLBACK_INTERRUPT, interrupt_step);

// Wait for advance button down <A> 
//   Advance one step
// Wait for home button press <H>
//   Go home

    printf("Waiting for interrupts. Press q to quit and display statistics\n");
    while((c = getchar()) != "C") {
    }
    ipcon_destroy(&ipcon);
}
