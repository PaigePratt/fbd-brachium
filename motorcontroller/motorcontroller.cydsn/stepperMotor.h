#ifndef DRIVER_STEPPER_MOTOR
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
    
    #define SET_HB_A(byte) byte & 0x01
    #define SET_HB_B(bbyte) byte & 0x02
    
    typedef struct {
        //how long the motor should run until its at its given position
        unsigned int durrationInMsecs;
        //PWM writeCompare functions
        void (*Coil1Period)(unsigned char);
        void (*Coil2Period)(unsigned char);
        signed short delta; //the distance the motor should be running given the durration
        //the states of the two h-briges with msOffset being the bit offset applied before
        //the states are sent to the control register CR_H_Bridge
        unsigned char motorStates;
        unsigned char msOffset;
        unsigned char pos; //current pos
        //Clockwise is positive and counterclock wise being negative
        unsigned char lastStep; //last step in the sequence (0-3)
        
    } stepperMotor;

    void setStepper(stepperMotor* motor, unsigned char pos, unsigned int durration);
    
    //macros for getting the first and second quarter of a byte
    
    
#endif
/* [] END OF FILE */
