
    
#if !defined(GLOBAL_VARS)
#define GLOBAL_VARS

#include <controlCommands.h>
// Global varibles

//Timing data
//extern struct RTC_TIME_DATE* currentTime;
unsigned short milliseconds;
//unsigned short timeDeltaInMilliseconds;

//this short is written to the Motor_Enables with each bit serving as the state of each register
unsigned short enabledMotors;

#define DEFAULT_PREALLOCATED_SPACE 128
controlCommandToken* commandQueue;
unsigned short queueCount = 0;
unsigned short currentAllocatedEntriesCQ = 0;

#endif
/* [] END OF FILE */
