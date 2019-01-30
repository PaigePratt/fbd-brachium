#include "project.h"
#include "globals.h"

#include <stdlib.h>

void apiInit() {
    RTC_Start();
    MillisecCounter_Start();
    UART_Start();
}

void parseSerial();
void sampleData();
void updateMotors();

int main(void) {
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    apiInit();
    
    for(;;) {
        parseSerial();
        sampleData();
        updateMotors();
    }
}

/* [] END OF FILE */
