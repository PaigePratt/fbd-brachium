#include "util.h"
#include "globals.h"
#include "tasks.h"
#include "task.h"
#include "project.h"
#include "stepperMotor.h"
#include <stdlib.h>
#include <stdio.h>
extern stepperMotor StepperMotors[UNIQUE_STMS];

#define DEFAULT_PREALLOC_SIZE 128
#define DEFAULT_EXPANSION_AMT 8
#define UARTGETCHAR() USBUART_GetChar()


void parseSerialData() {
    
    char buff[4];
    memset(buff, 0, 4);
    
    UARTprintf("getting data\n");
    
    for(int i = 0; i < 3; i++) {
        buff[i] = UARTGETCHAR();
    }
    
    UARTprintf("Got serial data: %s\n", buff);
    
    for(int i = 0; i < UNIQUE_STMS; i++) {
        setStepper(&StepperMotors[i], buff[i], currentDiv);
    }
}

/* [] END OF FILE */
