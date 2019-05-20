#include "util.h"
#include "tasks.h"
#include "task.h"
#include "project.h"
#include <stdlib.h>

#define DEFAULT_PREALLOC_SIZE 128
#define DEFAULT_EXPANSION_AMT 8

void parseSerialData() {
    //get data
    unsigned int currentAllocatedSize = UART_GetRxBufferSize();
    char* buff = calloc(currentAllocatedSize, 1);
    
    for(unsigned int i = 0; i < currentAllocatedSize; i++) {
        buff[i] = UART_GetChar();
    }
    
    //parse
    
    for(unsigned int i = 0; i < currentAllocatedSize; i++) {
        switch(buff[i]) {
        //setting motor data
        case 0 ... 2:
            ; 
            
            unsigned int dt[] = {PACK_CHARS_INTO_INT(buff[i], buff[i+1],  buff[i+2], 0)};
            i += 3;
            unsigned int time = PACK_ARRAY_OFF_CHARS_INTO_INT(buff, i);
            addToTasks(time, setStepperMotorAngle, dt, 1);
            i += 4;
            break;
        
        
        }
        
        
    }
}

/* [] END OF FILE */
