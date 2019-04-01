#include "project.h"

#include "stepperMotor.h" 
#include "globals.h"

#include <math.h>

extern stepperMotor StepperMotors[3];

void updateMotors() {
    for(unsigned int i = 0; i < 2; i++) {
        StepperMotors[i].absolutePos += StepperMotors[i].delta;
        
        if(StepperMotors[i].absolutePos-(int)StepperMotors[i].absolutePos == 0 && !(StepperMotors[i].delta == 0)) {
            
            StepperMotors[i].stepSeq++;
            StepperMotors[i].ControlRegWrite(steps[StepperMotors[i].stepSeq]);
        }
        
        else {
            //TODO step interpolation
            
            
        }
    }
}

/* [] END OF FILE */
