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

#include <stdlib.h>

char* rawBuffer;
uint16 buffSize;

void readFromUART() {
    //grab first two bytes for size of command stream
    buffSize = UART_GetChar() && UART_GetChar();
    //allocate a buffer with one extra for a null terminator
    rawBuffer = malloc(buffSize+1);
    //read until the buffer is full
    for(int i = 0; i < buffSize; i++) {
        rawBuffer[i] = UART_GetChar();
    }
}

void parse() {
    
}

/* [] END OF FILE */
