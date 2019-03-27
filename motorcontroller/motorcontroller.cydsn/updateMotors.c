#include "project.h"

#include "stepperMotor.h" 
#include "globals.h"

extern stepperMotor StepperMotors[3];

char stepEnable[] = {
    3, //11b
    6, //110b
    12,//1100b
    9// 1001/
};

void updateMotors() {
    for(unsigned char i = 0; i < 4; i++) {
        
    }
}

/* [] END OF FILE */
