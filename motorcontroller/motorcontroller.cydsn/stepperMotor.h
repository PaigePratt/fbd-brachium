#if !defined(DRIVER_STEPPER_MOTOR)
#define DRIVER_STEPPER_MOTOR 1
//PSoC creator does this weird ass indents if there's a way to fix it I will

#define STM_ELBOW 0
#define STM_SHOULDER 1
#define STM_WRIST 2

//enable adresses for the various h bridges
//#define STM_ELBOW_CA 0000001b
//#define STM_ELBOW_CB 0000010b

//this is the maximum number of steps to do one 360 degree rotation
#define STM_MAX_STEPS_PER_REV 200

typedef struct {
    //PWM writeCompare functions
    void (*Coil1Period)(unsigned char);
    void (*Coil2Period)(unsigned char);
    void (*ControlReg)(unsigned char);
    //how long the motor should run until its at its given position
    unsigned int durrationInMsecs;
    unsigned int timeBetweenStepsMS; //millisecs
    float absolutePos;
    float delta; //the distance the motor should be running given the durration
    unsigned char stepSeq;
} stepperMotor;

void setStepper(stepperMotor* motor, unsigned char pos, unsigned int durration);

char steps[] = {
    3, //11b
    6, //110b
    12,//1100b
    9// 1001/
};
    
#endif
/* [] END OF FILE */
