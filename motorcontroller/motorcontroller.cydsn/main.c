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

void milliSecPassed() {
    milliseconds++;
    
    for(unsigned short i = lastInitializedToken; i < queueCount; i++) {
        if(commandQueue[i].state == CCT_INQUEUE && milliseconds >= commandQueue[i].timeInMillisec) {
            commandQueue[i].fn(commandQueue[i].data);
            commandQueue[i].state = CCT_DONE;
        }
    }   
}

int main(void) {
    CyGlobalIntEnable; /* Enable global interrupts. */
    apiInit();
    
    ///commandQueue initialization
    commandQueue = malloc(sizeof(controlCommandToken) * DEFAULT_PREALLOCATED_SPACE);
    currentAllocatedEntriesCQ = DEFAULT_PREALLOCATED_SPACE;
    
    const char* args = "\0x0\0x100\0x0\0x0\0x1000";
    
    controlCommandToken a = {setStepperMotor, 1000, args , CCT_INQUEUE};
    
    commandQueue[0] = a;
    
    queueCount++;
    
    for(;;) {
        parseSerial();
        updateMotors();
    }
}

/* [] END OF FILE */
