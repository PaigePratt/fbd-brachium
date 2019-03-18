#ifndef GLOBAL_VARS
#define GLOBAL_VARS 1
    #include "controlCommands.h"
    // Global varibles

    //Timing data
    //extern struct RTC_TIME_DATE* currentTime;
    unsigned short milliseconds;
    //unsigned short timeDeltaInMilliseconds;

    //this short is written to the Motor_Enables with each bit serving as the state of each register
    unsigned short enabledMotors;
    
    #define DEFAULT_PREALLOCATED_SPACE 128
    controlCommandToken* commandQueue;
    unsigned int queueCount = 0;
    
#endif
/* [] END OF FILE */
