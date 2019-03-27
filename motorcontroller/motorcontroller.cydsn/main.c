#include "project.h"
#include "globals.h"

#include <stdlib.h>
#include <math.h>

#define INIT_PART(name, sub) name ## _ ##sub ##_Start()


void milliSecPassed() {
    milliseconds++;
    
    if(milliseconds >= commandQueue[queueCount+1].timeInMillisec) {
        
    }
}

int posit = 0;

void stepOnceHandler() {
    posit = (posit + 1) % 4;
}

void apiInit() {
    RTC_Start();
    UART_Start();
    INIT_PART(Stepper_Motor_Driver, STM_SHOULDER);
    stepOnceISR_StartEx(stepOnceHandler);
    
}

void sampleData();
void updateMotors();

int delayTime = 100;

void stepMotor(unsigned int period) {
    for(unsigned int i = 0; i <= period; i++) {
        
        CyDelay(delayTime);
    }
}

char stepEnable[] = {
    3, //11b
    6, //110b
    12,//1100b
    9// 1001/
};
#define B_MAX 7

const unsigned char stepSeq2[4][4] = {
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 1},
    {1, 0, 0, 1}
};

int main(void) {
    CyGlobalIntEnable; /* Enable global interrupts. */
    apiInit();
    
    //CR_H_Bridge_Write(3);
    
    for(;;) {
        CR_H_Bridge_Write(stepEnable[posit]);
        posit++;
        posit = posit % 4;
        CyDelay(delayTime);
    }
}

/* [] END OF FILE */
