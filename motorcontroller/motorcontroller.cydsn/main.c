#include "project.h"
#include "globals.h"
#include "stepperMotor.h"

#include <stdlib.h>
#include <math.h>

#define INIT_PART(sub, name) name ## _ ##sub ##_Start()

#define INIT_MOTOR(section) INIT_PART(SMD, section); \
    INIT_PART(H_Bridge, section);

extern void updateMotors();
extern void parseSerial();

unsigned short lastInitializedToken = 0;
unsigned short queueItor;

extern stepperMotor StepperMotors[3];

void milliSecPassed() {
    milliseconds++;
    
    for(int i = 0; i < 2; i++) {
        StepperMotors[i].durrationInMsecs--;
    }
    
    
    for(queueItor = lastInitializedToken; queueItor < queueCount; queueItor++) {
        if(commandQueue[queueItor].state == CCT_INQUEUE && milliseconds >= commandQueue[queueItor].timeInMillisec) {
            commandQueue[queueItor].fn(commandQueue[queueItor].data);
            commandQueue[queueItor].state = CCT_DONE;
        }
    }   
}

void addToCommandQueue(controlFunction fn, unsigned int time, char* args, int sz) {
    commandQueue[queueCount].fn = fn;
    commandQueue[queueCount].timeInMillisec = time;
    commandQueue[queueCount].data = malloc(sz);
    memcpy(commandQueue[queueCount].data, args, sz);
    commandQueue[queueCount].state  = CCT_INQUEUE;
}

int main(void) {
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    
    UART_Start();
    PWM_Start();
    oneMillsecPassed_StartEx(milliSecPassed);
    MillisecTimer_Start();
    INIT_PART(SMD, STM_SHOULDER);
    INIT_PART(SMD, STM_ELBOW);
    
    //commandQueue initialization
    commandQueue = malloc(sizeof(controlCommandToken) * DEFAULT_PREALLOCATED_SPACE);
    currentAllocatedEntriesCQ = DEFAULT_PREALLOCATED_SPACE;
    
    char data[] = {
        0, 200, 2, 7, 1, 0
    };
    
    addToCommandQueue(setStepperMotor, 2000, data, 6); 
    int i = 0;
    for(;;) {
        parseSerial();
        updateMotors();
    }
}

/* [] END OF FILE */
