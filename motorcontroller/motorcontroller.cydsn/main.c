#include "project.h"
#include "controlcodes.h"

#include <stdlib.h>

void hasDataHandler() {
    
}

void apiInit() {
    hasData_StartEx(hasDataHandler);
    UART_Start();
}

int main(void) {
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    apiInit();

    for(;;) {
        
    }
}

/* [] END OF FILE */
