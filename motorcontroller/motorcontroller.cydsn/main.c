#include "project.h"
#include "globals.h"

#include <stdlib.h>

#define INIT_PART(name, sub) name ## _ ##sub ##_Start()


void milliSecPassed() {
    milliseconds++;
    
    if(milliseconds >= commandQueue[queueCount+1].timeInMillisec) {
        
    }
}

void apiInit() {
    RTC_Start();
    UART_Start();
    INIT_PART(Stepper_Motor_Driver, STM_SHOULDER);
}

void sampleData();
void updateMotors();

int main(void) {
    CyGlobalIntEnable; /* Enable global interrupts. */
    apiInit();
    
    for(;;) {
        
    }
}

/* [] END OF FILE */
