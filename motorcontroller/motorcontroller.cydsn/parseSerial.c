#include "project.h" 

#include "controlCommands.h" 
#include <stdlib.h>

char* rawBuffer;
uint16 buffSize;


void readFromUART() {
    //grab first two bytes for size of command stream
    char high = UART_GetChar();
    char low  = UART_GetChar();
    buffSize = (high << 8) | low;
    //allocate a buffer with one extra for a null terminator
    rawBuffer = malloc(buffSize+1);
    //read until the buffer is full
    for(int i = 0; i < buffSize; i++) {
        rawBuffer[i] = UART_GetChar();
    }
}

void parse() {
    for(int i = 0; i < buffSize; i++) {
        
    }
}

void parseSerial() {
    readFromUART();
    parse();
}

/* [] END OF FILE */
