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
    unsigned int sz = USBUART_GetCount();
    signed char buff[sz+1];
    memset(buff, 0, sz+1);
    char buff_buff[5];
    buff_buff[4] = 0;
    
    for(unsigned int i = 0; i < sz; i++) {
        buff[i] = (signed char)UARTGETCHAR();
        while(!USBUART_CDCIsReady());
    }
    
    
    //USBUART_PutString(buff);
    
    for(int i = 0; i < UNIQUE_STMS; i++) {
        //setStepper(&StepperMotors[i], (signed int)buff[i], currentDiv);
        signed int angle = (signed int) buff[i];
        StepperMotors[i].ControlRegWrite(currentDiv);
        StepperMotors[i].delta = 1;//angle > 0 ? 1 : -1;
        StepperMotors[i].totalDelta = ((signed int)buff[i])/1.8;
        
        itoa(StepperMotors[i].totalDelta, buff_buff, 10);
        USBUART_PutString(buff_buff);
        while(!USBUART_CDCIsReady());
        
    }
    
    USBUART_PutCRLF();
}

/* [] END OF FILE */
