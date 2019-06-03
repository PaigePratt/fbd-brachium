
    
#if !defined(GLOBAL_VARS)
#define GLOBAL_VARS
#define DEFAULT_PREALLOCATED_SPACE 128
#include "stepperMotor.h"

//this varable holds the microstepping setting
unsigned char currentDiv;
//this is just here to allow main() and parseSeralData() to access the stepper motors and their data
extern stepperMotor StepperMotors[UNIQUE_STMS];

#endif
/* [] END OF FILE */
