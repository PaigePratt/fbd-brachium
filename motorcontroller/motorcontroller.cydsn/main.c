#include "project.h"
#include "globals.h"
#include "stepperMotor.h"
#include "util.h"

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdarg.h>

#define INIT_PART(sub, name) name ## _ ##sub ##_Start()
#define INIT_MOTOR(section) INIT_PART(SMD, section); INIT_PART(H_Bridge, section);
#define DELAY_LOOP 1000

extern void updateMotors();
extern void parseSerialData();

unsigned short lastInitializedToken = 0;
unsigned short queueItor;

extern stepperMotor StepperMotors[UNIQUE_STMS];

void UARTprintf(const char* fmt, ...) {
    va_list vl;
    va_start(vl, fmt);
    char buff[32 + strlen(fmt) + 1];
    memset(buff, 0, 64);
    vsprintf(buff, fmt, vl);
    USBUART_PutString(buff);
    va_end(vl);
}

//this is the handler that the oneMillisecPassed inturrupt calls
void milliSecPassed() {
    unsigned int i;
    for(i = completedTasks; i < totalTasks; i++) {
        if(tasks[i].TimeToCall >= milliseconds) {
            tasks[i].Method(tasks[i].Data);
            completedTasks++;
        }
    }
}

int main(void) {
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    USBUART_Start(0, USBUART_5V_OPERATION);
    
    //MillisecTimer_Start();
    //tasks = calloc(DEFAULT_PREALLOCATED_SPACE, sizeof(task_t));
    //totalTasks = 0;
    //completedTasks = 0;
    
    currentDiv = DV_STEP_FULL;
    CyDelay(500);
    UARTprintf("FBD-Brachium Serial Debug Terminal\n\rCode by Demian Ihrig (Demian.l.ihrig@gmail.com)\n\r");
    
    UARTprintf("Entering Main Loop\n\r");
    for(;;) {
        
        if(USBUART_GetCount()) {
            //parseSerialData();
            char b = USBUART_GetChar();
            USBUART_PutChar(b);
        }
        
        for(int i = 0; i < UNIQUE_STMS; i++) {
            
            if(StepperMotors[i].totalDelta) {
                //TODO change this
                StepperMotors[i].ControlRegWrite(0x0 | ((StepperMotors[i].delta >> 31)& 1));
                StepperMotors[i].ControlRegWrite(0x2 | ((StepperMotors[i].delta >> 31)& 1));

                StepperMotors[i].totalDelta -= StepperMotors[i].delta;
                StepperMotors[i].absolutePos -= StepperMotors[i].delta;
            }
            
            
        }
        
        CyDelay(5);
        debug_loop_count++;
    }
}

/* [] END OF FILE */
