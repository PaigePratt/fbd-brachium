#include "project.h" 

#include "controlCommands.h" 
#include "globals.h"
#include <stdlib.h>

char* rawBuffer;
uint16 buffSize;

//change me
#define COMMAND_MAX 2

void readFromUART() {
    //grab first two bytes for size of command stream
    char high = UART_GetChar();
    char low  = UART_GetChar();
    buffSize = (high << 8) | low;
    //allocate a buffer with one extra for a null terminator
    realloc(rawBuffer, buffSize+1);
    //read until the buffer is full
    for(int i = 0; i < buffSize; i++) {
        rawBuffer[i] = UART_GetChar();
    }
    
}

void parse() {
    for(int i = 0; i < buffSize; i++) {
        if(rawBuffer[i] > COMMAND_MAX) {
            //error
            
            return;
        }
        
        //check to see if we have space in the command queue
        if(queueCount+1 > currentAllocatedEntriesCQ) {
            //if not add 4 entries
            currentAllocatedEntriesCQ += 4;
            realloc(commandQueue, currentAllocatedEntriesCQ * sizeof(controlCommandToken));
        }
        
        //set the function to the appropriate command
        commandQueue[queueCount].fn = Commands[rawBuffer[i]].fn;
        //allocate space for args
        commandQueue[queueCount].data = malloc(Commands[rawBuffer[i]].argCount + 1); //null char for safety
        
        //dump the args
        int  j;
        for(j = 0; j < Commands[rawBuffer[i]].argCount; j++) {
            commandQueue[queueCount].data[j] = rawBuffer[i + j];
        }
        
        //incrament things
        queueCount++;
        i = i + j;
        
        
    }
}

void parseSerial() {
    readFromUART();
    parse();
}

/* [] END OF FILE */
