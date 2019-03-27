#include "project.h"
#include "globals.h"

#include <stdlib.h>
#include <math.h>

#define INIT_PART(sub, name) name ## _ ##sub ##_Start()

#define INIT_MOTOR(section) INIT_PART(SMD, section); \
    INIT_PART(H_Bridge, section);

unsigned short lastInitializedToken = 0;

void milliSecPassed() {
    milliseconds++;
    
    for(unsigned short i = lastInitializedToken; i < queueCount; i++) {
        if(commandQueue[i].state == CCT_INQUEUE) {
            commandQueue[i].fn(commandQueue[i].data);
            commandQueue[i].state = CCT_DONE;
        }
    }
}

void apiInit() {
    RTC_Start();
    UART_Start();
    INIT_PART(SMD, STM_SHOULDER);
}

void sampleData();
void updateMotors();

int delayTime = 100;

void stepMotor(unsigned int period) {
    for(unsigned int i = 0; i <= period; i++) {
        
        CyDelay(delayTime);
    }
}

extern void parseSerial();

int main(void) {
    CyGlobalIntEnable; /* Enable global interrupts. */
    apiInit();
    
    commandQueue = malloc(sizeof(controlCommandToken) * DEFAULT_PREALLOCATED_SPACE);
    currentAllocatedEntriesCQ = DEFAULT_PREALLOCATED_SPACE;
    
    int i;
    
    for(;;) {
        parseSerial();
        updateMotors();
    }
}

/* [] END OF FILE */
