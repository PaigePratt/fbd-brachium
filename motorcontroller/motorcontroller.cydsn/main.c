/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

void hasDataHandler() {
}

void apiInit() {
    hasData_StartEx(hasDataHandler);
    UART_1_Start();
}

int main(void) {
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    apiInit();
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;) {
        
    }
}

/* [] END OF FILE */
