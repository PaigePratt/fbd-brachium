



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
    {0, Stepper_Motor_Driver_STM_SHOULDER_WriteCompare1, Stepper_Motor_Driver_STM_SHOULDER_WriteCompare2, 0, 0, 0, 0, 0}
};

void setStepper(stepperMotor* motor, unsigned char pos, unsigned int durration) {
    //delta calculation
    unsigned char currentPos = motor->pos;
    
    motor->delta += (currentPos - pos);
    motor->durrationInMsecs += durration;
}



/* [] END OF FILE */
