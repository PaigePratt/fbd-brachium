#include "stepperMotor.h"
#include "project.h"

stepperMotor StepperMotors[] = {
    {SHOULDER_SMD_WriteCompare, SHOULDER_SMD_WritePeriod,
        SHOULDER_STEP_MODE_Write, SHOULDER_LOGIC_Write, 0, 0, 0},
    {ELBOW_SMD_WriteCompare, ELBOW_SMD_WritePeriod,
        ELBOW_STEP_MODE_Write, ELBOW_LOGIC_Write, 0, 0, 0}
};

void setStepper(stepperMotor* motor, signed short pos, signed short delta) {
    motor->totalDelta = (motor->absolutePos - pos);
    
    //motor->delta = (motor->totalDelta / MIN_TIME_BETWEEN_FULL_STEPS_MS);
    motor->delta = delta;
}

/* [] END OF FILE */
