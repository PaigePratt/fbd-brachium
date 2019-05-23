#include "project.h"
#include "globals.h"
#include "stepperMotor.h"
#include "util.h"

#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>


#define INIT_PART(sub, name) name ## _ ##sub ##_Start()
#define INIT_MOTOR(section) INIT_PART(SMD, section); INIT_PART(H_Bridge, section);
#define DELAY_LOOP 1000

extern void updateMotors();
extern void parseSerialData();

unsigned short lastInitializedToken = 0;
unsigned short queueItor;

extern stepperMotor StepperMotors[2];

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
    
    UART_Start();
    
    //MillisecTimer_Start();
    hasData_StartEx(parseSerialData);
    //tasks = calloc(DEFAULT_PREALLOCATED_SPACE, sizeof(task_t));
    //totalTasks = 0;
    //completedTasks = 0;
    currentDiv = DV_STEP_FULL;
    StepperMotors[1].absolutePos = 0;
    setStepper(&StepperMotors[1], -90, 0);
    for(;;) {
        printf("This is a test\n");
        for(int i = 0; i < 2; i++) {
            
            if(StepperMotors[i].totalDelta) {
                //TODO change this
                StepperMotors[i].ControlRegWrite(0x0 | ((StepperMotors[i].delta >> 31)& 1));
                StepperMotors[i].ControlRegWrite(0x2 | ((StepperMotors[i].delta >> 31)& 1));

                StepperMotors[i].totalDelta -= StepperMotors[i].delta;
                StepperMotors[i].absolutePos -= StepperMotors[i].delta;
            }
            
            
        }
        
        CyDelay(5);
    }
}

/* [] END OF FILE */
