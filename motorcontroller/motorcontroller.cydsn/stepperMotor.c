
#include "stepperMotor.h"

#include "project.h"

stepperMotor StepperMotors[] = {
    //{0, Stepper_Motor_Driver_WriteCompare1, Stepper_Motor_Driver_WriteCompare2}
};

void setStepper(stepperMotor* motor, unsigned char pos, unsigned int durration) {
    //delta calculation
    unsigned char currentPos = motor->pos;
    
    motor->delta += (currentPos - pos);
    motor->durrationInMsecs += durration;
}
   

/* [] END OF FILE */
