#include "stepperMotor.h"
#include "project.h"

#include <math.h>

stepperMotor StepperMotors[] = {
    {SHOULDER_STEP_MODE_Write, SHOULDER_LOGIC_Write, SHOULDER_LOGIC_Read, 0, 0, 0},
    {ELBOW_STEP_MODE_Write, ELBOW_LOGIC_Write, ELBOW_LOGIC_Read, 0, 0, 0}, 
    {}
};

void setStepper(stepperMotor* motor, signed int angle, unsigned char div) {
    int divmult = pow(2, div);
    
    int oldDiv = pow(2 ,motor->ControlRegRead());
   
    int angleDelta = angle - ((motor->absolutePos*1.8)/oldDiv);
    
    motor->delta = angle > 0 ? 1 : -1;
    
    motor->totalDelta = (angleDelta/1.8) * divmult;
    
    motor->ControlRegWrite(div);
}

/* [] END OF FILE */
