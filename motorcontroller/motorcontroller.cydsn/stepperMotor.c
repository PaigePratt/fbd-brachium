#include "stepperMotor.h"
#include "project.h"

#include <math.h> // pow()

stepperMotor StepperMotors[] = {
    {SHOULDER_STEP_MODE_Write, SHOULDER_LOGIC_Write, SHOULDER_LOGIC_Read, 0, 0, 0, 50, 20},
    {ELBOW_STEP_MODE_Write, ELBOW_LOGIC_Write, ELBOW_LOGIC_Read, 0, 0, 0, 1, 1}, 
    {TURNTABLE_STEP_MODE_Write, TURNTABLE_LOGIC_Write, TURNTABLE_LOGIC_Read, 0, 0, 0, 80, 35}
};

/*
    setStepper(): sets the new stepper motor delta, and microstepping setting
*/
void setStepper(stepperMotor* motor, signed int angle, unsigned char div) {
    //set the abosulute angle to a modulo of 360 if it hasnt already been done
    motor->absolutePos = motor->absolutePos % 360;
    //calculate the new microstepping multiplier 
    int divmult = pow(2, div);
    //calculate the old one
    int oldDiv = pow(2 ,motor->ControlRegRead());
    //calculate necesary angle delta
    int angleDelta = angle - ((motor->absolutePos*1.8)/oldDiv);
    //determine if this is a positive or negative delta
    motor->delta = angle > 0 ? 1 : -1;
    //update totoal delta
    motor->totalDelta = (angleDelta/1.8) * divmult;
    //set new microstepping division
    motor->ControlRegWrite(div);
}

/* [] END OF FILE */
