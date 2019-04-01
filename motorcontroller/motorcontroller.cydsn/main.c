#include "project.h"
#include "globals.h"

#include <stdlib.h>
#include <math.h>

#define INIT_PART(sub, name) name ## _ ##sub ##_Start()

#define INIT_MOTOR(section) INIT_PART(SMD, section); \
    INIT_PART(H_Bridge, section);

void apiInit() {
    RTC_Start();
    UART_Start();
    INIT_PART(SMD, STM_SHOULDER);
}

extern void updateMotors();
extern void parseSerial();

unsigned short lastInitializedToken = 0;
unsigned short queueItor;

void milliSecPassed() {
    milliseconds++;
    
    for(queueItor = lastInitializedToken; queueItor < queueCount; queueItor++) {
        if(commandQueue[queueItor].state == CCT_INQUEUE && milliseconds >= commandQueue[queueItor].timeInMillisec) {
            commandQueue[queueItor].fn(commandQueue[queueItor].data);
            commandQueue[queueItor].state = CCT_DONE;
        }
    }   
}

int main(void) {
    CyGlobalIntEnable; /* Enable global interrupts. */
    apiInit();
    
    ///commandQueue initialization
    commandQueue = malloc(sizeof(controlCommandToken) * DEFAULT_PREALLOCATED_SPACE);
    currentAllocatedEntriesCQ = DEFAULT_PREALLOCATED_SPACE;
    
    queueCount++;
    
    for(;;) {
        parseSerial();
        updateMotors();
    }
}

/* [] END OF FILE */
