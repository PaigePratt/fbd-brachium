#include "stepperMotor.h"
#include "project.h"

#include <stdio.h>

stepperMotor StepperMotors[] = {
    {STM_SHOULDER_SMD_WriteCompare1, STM_SHOULDER_SMD_WriteCompare2, STM_SHOULDER_H_Bridge_Write,
        0, 0, 0, 0, 0},
    
    {STM_ELBOW_SMD_WriteCompare1, STM_ELBOW_SMD_WriteCompare2, STM_ELBOW_H_Bridge_Write,
        0, 0, 0, 0, 0},
    
    {STM_ENDEFFECT_SMD_WriteCompare1, STM_ENDEFFECT_SMD_WriteCompare2, STM_ENDEFFECT_H_Bridge_Write,
        0, 0, 0, 0, 0}
};

void setStepper(stepperMotor* motor, unsigned char pos, unsigned int durration) {
    //delta calculation
    unsigned char currentPos = motor->absolutePos;
    
    motor->delta += (currentPos - pos);
    
    if(motor->delta < (float)MIN_TIME_BETWEEN_STEPS_MS) {
        printf("WARNING: %fms is lower than the minimum possible time between steps, supplanting with %ims instead\r\n",
            motor->delta, MIN_TIME_BETWEEN_STEPS_MS);
        motor->delta = MIN_TIME_BETWEEN_STEPS_MS;
    }
    
    motor->durrationInMsecs += durration;
}

void setStepperMotor(char* args) {
    char motor = args[0];
    char pos = args[1];
    unsigned int durr = (args[2] << 24 | args[3] << 16 | args[4] << 8 | args[5]);
    
    setStepper(&StepperMotors[motor], pos, durr);
}

void holdStepper(char* args) {
    char motor = args[0];
    
    setStepper(&StepperMotors[motor], 0, 0);
}

/* [] END OF FILE */
