#include "project.h"

#include "stepperMotor.h" 
#include "globals.h"

#include <math.h>

extern stepperMotor StepperMotors[3];

void updateMotors() {
    for(unsigned int i = 0; i < 2; i++) {
        
        StepperMotors[i].absolutePos += StepperMotors[i].delta;
        
        //check if the absolute position is a whole number and that delta is non zero
        if(ceilf(StepperMotors[i].absolutePos) == StepperMotors[i].absolutePos && StepperMotors[i].durrationInMsecs == 0) {
            //if all conditions are met this means that the motor is still spinning
            StepperMotors[i].stepSeq++;
            StepperMotors[i].stepSeq = (StepperMotors[i].stepSeq) % 4;
            StepperMotors[i].ControlRegWrite(steps[StepperMotors[i].stepSeq]);
        }
        
        else {
            //TODO step interpolation
            
            
        }
    }
}

/* [] END OF FILE */
