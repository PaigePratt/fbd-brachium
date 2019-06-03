#if !defined(DRIVER_STEPPER_MOTOR)
#define DRIVER_STEPPER_MOTOR 1

/*
 * stepperMotor.h struct and function definitions for 
*/
    
#define STM_ELBOW 0
#define STM_SHOULDER 1
#define STM_TURNTABLE 2

//this is the maximum number of steps to do one 360 degree rotation
#define STM_MAX_STEPS_PER_REV 200

#define UNIQUE_STMS 3
    
//various definitions to be sent to the stepper motor contoller for microstepping
#define DV_STEP_FULL 0x0
#define DV_STEP_HALF 0x1
#define DV_STEP_QUARTER 0x2
#define DV_STEP_EIGHTH 0x3
#define DV_STEP_SIXTEENTH 0x4

//stepperMotor: he abstract data type which holds all the neccesary function adresses and position data    
typedef struct stepperMotor {
    void (*DirWrite)(unsigned char);
    void (*ControlRegWrite)(unsigned char);
    unsigned char (*ControlRegRead)();
    
    signed int absolutePos;
    //at the moment only holds -1 or 1, tells the direction that the stepper motor should rotate
    signed int delta;
    //the total delta to travel
    signed int totalDelta; 
    //gear ratio config
    signed int ratioNum;
    signed int ratioDen;
} stepperMotor;

void setStepper(stepperMotor* motor, signed int angle, unsigned char div);

#endif
/* [] END OF FILE */
