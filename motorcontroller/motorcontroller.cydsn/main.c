#include "project.h" //UART api

#include "globals.h" 
#include "util.h"

#include <stdlib.h>
#include <stdio.h>


extern void parseSerialData(unsigned int sz);

int main(void) {
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //USB UART Initialization
    USBUART_Start(0, USBUART_5V_OPERATION);
    while(!USBUART_bGetConfiguration());
    USBUART_CDC_Init();

    currentDiv = DV_STEP_FULL;
    for(;;) {
        
        parseSerialData(USBUART_GetCount());
        
        //Stepper Motor Update code
        for(int i = 0; i < UNIQUE_STMS; i++) {
            if(StepperMotors[i].totalDelta) {
                //in order to tell the stepper motor controller to move a rising edge must be written to the step pin
                //this is done by setting the second pin ..._LOGIC pins (see page 2 of topdesign)
                //on top of that we must tell the controller wheather or not we want it to rotate counterclockwise or clockwise
                //this is done by get the first (signage) bit of the delta varable and logically anding this to the edge we are writing to the controller
                StepperMotors[i].ControlRegWrite(0x0 | ((StepperMotors[i].delta >> 31)& 1));
                StepperMotors[i].ControlRegWrite(0x2 | ((StepperMotors[i].delta >> 31)& 1));
                //finallly we update the absolute position of the motor and decrement the totalDelta
                StepperMotors[i].totalDelta -= StepperMotors[i].delta;
                StepperMotors[i].absolutePos -= StepperMotors[i].delta;
            }
        }
        
        //delay the loop for 5ms as to not overrun the motors and keep everything at a decent speed
        CyDelay(5);
    }
}

/* [] END OF FILE */
