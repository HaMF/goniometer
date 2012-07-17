
#include <stdio.h>

#include "bindings/ip_connection.h"
#include "bindings/bricklet_io4.h"

#define HOST "localhost"
#define PORT 4223
#define IO4_UID "XYZ" // Change to your UID
#define STEPPER_UID "XYZ" // Change to your UID

int main() {
    // Create IP connection to brickd
    IPConnection ipcon;
    if(ipcon_create(&ipcon, HOST, PORT) < 0) {
        fprintf(stderr, "Could not create IP connection to brickd\n");
        exit(1);
    }

    // Create IO4 object
    IO4 io;
    io4_create(&io, IO4_UID); 

    // Add IO4 to IP connection
    if(ipcon_add_device(&ipcon, &io) < 0) {
        fprintf(stderr, "Could not connect to IO4-Bricklet\n");
        exit(1);
    }
    
    // Create stepper object
    Stepper stepper;
    stepper_create(&stepper, STEPPER_UID); 

    // Add stepper to IP connection
    if(ipcon_add_device(&ipcon, &stepper) < 0) {
      	fprintf(stderr, "Could not connect to Stepper-Brick\n");
      	exit(1);
    }
    stepper_set_motor_current(&stepper, 800); // 800mA
    stepper_set_step_mode(&stepper, 8); // 1/8 step mode
    stepper_set_max_velocity(&stepper, 2000); // Velocity 2000 steps/s
    
    // Slow acceleration (500 steps/s^2), 
    // Fast deacceleration (5000 steps/s^2)
    stepper_set_speed_ramping(&stepper, 500, 5000);
  	stepper_enable(&stepper);
    stepper_set_steps(&stepper, 20); //this advances

// Configure PIN as input
// Register callbacks
// Wait for callback
//   Advance by f degrees
// Wait for advance button down <A> 
//   Advance one step
// Wait for home button press <H>
//   Go home

}
