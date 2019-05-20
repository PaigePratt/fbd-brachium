#if !defined(DRIVER_STEPPER_MOTOR)
#define DRIVER_STEPPER_MOTOR 1
//PSoC creator does this weird ass indents if there's a way to fix it I will

#define STM_ELBOW 0
#define STM_SHOULDER 1
#define STM_WRIST 2

//this is the maximum number of steps to do one 360 degree rotation
#define STM_MAX_STEPS_PER_REV 200

//may need to be more finely tuned
#define MIN_TIME_BETWEEN_FULL_STEPS_MS 100


#define STEPPER_MOTOR_POSABS_MAX 6400

#define DV_STEP_FULL 0x0
#define DV_STEP_HALF 0x1
#define DV_STEP_QUARTER 0x2
#define DV_STEP_EIGHTH 0x3
#define DV_STEP_SIXTEENTH 0x4
    
typedef struct stepperMotor {
    //PWM writeCompare functions
    void (*StepWriteCompare)(unsigned short);
    void (*StepWritePeriod)(unsigned short);
    void (*DirWrite)(unsigned char);
    void (*ControlRegWrite)(unsigned char);
    //unsigned char(*readControlReg)(void);
    //how long the motor should run until its at its given position
//    unsigned int durrationInMsecs; //when to trigger the event based on the PSoC local clock
    signed short absolutePos;
    signed short delta; //the distance the motor should be running given the durration
    signed short totalDelta; 
} stepperMotor;

void setStepper(stepperMotor* motor, signed short pos, signed short delta);

#endif
/* [] END OF FILE */
