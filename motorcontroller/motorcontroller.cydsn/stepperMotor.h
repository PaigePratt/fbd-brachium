#ifndef DRIVER_STEPPER_MOTOR
#define DRIVER_STEPPER_MOTOR 1
    //PSoC creator does this weird ass indents if there's a way to fix it I will
    
    #define STM_ELBOW 0
    #define STM_SHOULDER 1
    #define STM_WRIST 2
    
    //this is the maximum number of steps to do one 360 degree rotation
    #define STM_MAX_STEPS_PER_REV 200
    
    typedef struct {
        //how long the motor should run until its at its given position
        unsigned int durrationInMsecs;
        //PWM writeCompare functions
        void (*Coil1Period)(unsigned short);
        void (*Coil2Period)(unsigned short);
        //inverters switches for steps 2 and 3
        void (*SwitchACoil)(char);
        void (*SwitchBCoil)(char);
        //motor configs
        signed short delta; //the distance the motor should be running given the durration
        unsigned char pos; //current pos
        //Clockwise is positive and counterclock wise being negative
        unsigned char lastStep; //last step in the sequence (0-3)
        
    } stepperMotor;

    void setStepper(stepperMotor* motor, unsigned char pos, unsigned int durration);
    
    //multipliers for the value of each stepper value
    signed short stepSeq[4][4] = {
        {1, 1, -1, -1},
        {-1, 1, 1, -1},
        {-1, -1, 1, 1},
        {1, -1, -1, 1}
    };
    
#endif
/* [] END OF FILE */
