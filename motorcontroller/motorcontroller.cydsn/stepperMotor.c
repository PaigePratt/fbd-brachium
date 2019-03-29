



#include "stepperMotor.h"
#include "project.h"
//multipliers for the value of each stepper value

#define H_BRIDGE_ENABLE(byte) CR_H_Bridge(byte)

const signed short stepSeq[4][4] = {
    {1, 1, -1, -1},
    {-1, 1, 1, -1},
    {-1, -1, 1, 1},
    {1, -1, -1, 1}
};
stepperMotor StepperMotors[] = {
    {STM_SHOULDER_SMD_WriteCompare1, STM_SHOULDER_SMD_WriteCompare2, STM_SHOULDER_H_Bridge_Write,
        0, 0, 0, 0, 0}
};

void setStepper(stepperMotor* motor, unsigned char pos, unsigned int durration) {
    //delta calculation
    unsigned char currentPos = motor->absolutePos;
    
    motor->delta += (currentPos - pos);
    motor->durrationInMsecs += durration;
    
    
    
}

void setStepperMotor(char* args) {
    char motor = args[0];
    char pos = args[1];
    //TODO
    unsigned int durr = args[2];
    
    setStepper(&StepperMotors[motor], pos, durr);
    
}

void holdStepper(char* args) {
    char motor = args[0];
    
    setStepper(&StepperMotors[motor], 0, 0);
}

/* [] END OF FILE */
