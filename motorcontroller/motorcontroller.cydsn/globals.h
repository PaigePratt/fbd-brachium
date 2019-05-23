
    
#if !defined(GLOBAL_VARS)
#define GLOBAL_VARS

#include <task.h>
// Global varibles


unsigned int milliseconds;

#define DEFAULT_PREALLOCATED_SPACE 128

task_t* tasks;
unsigned int totalTasks;
unsigned int completedTasks;
unsigned allocatedEntries;
unsigned char currentDiv;    

#endif
/* [] END OF FILE */
