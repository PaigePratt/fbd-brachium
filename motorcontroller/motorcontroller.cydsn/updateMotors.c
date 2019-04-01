#include "project.h"

#include "stepperMotor.h" 
#include "globals.h"

#include <math.h>

extern stepperMotor StepperMotors[3];
//todo change the 3 to a 4
void updateMotors() {
    for(unsigned int i = 0; i < 1; i++) {
        StepperMotors[i].absolutePos += StepperMotors[i].delta;
        
        if(StepperMotors[i].absolutePos-(int)StepperMotors[i].absolutePos == 0 && !(StepperMotors[i].delta == 0)) {
            
            StepperMotors[i].stepSeq++;
            StepperMotors[i].ControlReg(steps[StepperMotors[i].stepSeq]);
        }
        
        else {
            //TODO step interpolation
        }
    }
}

/* [] END OF FILE */
