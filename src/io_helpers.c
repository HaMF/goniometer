void print_stats(nSteps) {
    printf("\rPosition: %6.2fdeg (%3d steps)", steps2angle(nSteps), nSteps);
    fflush(stdout);
}

void display_usage() {
    printf("This program drives a stepper motor when a TTL pulse is registered on port 0 of a tinkerforge IO4 bricklet.\n\n");
    printf("Command line arguments:\n");
    printf("    -a,  --angle       Angle by wich motor advances on interrupt (default: 5)\n");
    printf("    -g,  --gear-ratio  Gear ratio between motor and sample rod (default: 2)\n");
    printf("    -s,  --steps-per-revolution Number of full-width steps needed for one revolution of the motor rod (default:200)\n");
    printf("    -m,  --step-mode   Perform 1/n steps. Note 1/1 steps give the biggest torque. (n = (1,2,4,8); default: 1)\n");
    printf("    -d,  --dynamic     Dynamic mode: --angle is ignored and instead TTL pulse length is used. 10ms = 0.1deg\n");
    printf("    -r,  --record      Record the angular position after every interrupt\n");
    printf("    -t,  --trigger     Trigger spectrometer instead of being triggered by it (for CW measurements)\n");
    printf("    -w,  --sweep-time  Time spectrometer needs for field sweep and to ready for the next one (with -t)\n");
    printf("    -n,  --n-aquisitions  Number of field sweeps/aquisitions (with -t)\n");
}
