#include "project.h" 
#include "controlCommands.h" 
#include "globals.h"

#include <stdio.h>
#include <stdlib.h>

char* rawBuffer;
uint16 buffSize;


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

//ignore warnings about indexing an array with a char
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wchar-subscripts"

void parse() {
    for(int i = 0; i < buffSize; i++) {
        //while I doubt that such an error would arrise (namely cause 
        if(rawBuffer[i] > COMMAND_MAX) {
            //error
            
            //dump to serial
            printf("Error: command with with value %c does not exist\n", rawBuffer[i]); 
            
            
            //exit the parser
            //return;
        }
        
        
        //check to see if we have space in the command queue
        //if(queueCount+1 > currentAllocatedEntriesCQ) {
            //if not add 4 entries
        //    currentAllocatedEntriesCQ += 4;
        //    realloc(commandQueue, currentAllocatedEntriesCQ * sizeof(controlCommandToken));
        //}
        
        if(rawBuffer[i] == EMERGENCY_ALL_STOP) {
            //halt the machine
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
        i = i + j;
        //convert the following 4 bytes into one uInt representing the time in which the event will be called
        commandQueue[queueCount].timeInMillisec = 
            (rawBuffer[i] << 24 | rawBuffer[i+1] << 16 | rawBuffer[i+2] << 8 | rawBuffer[i+3]);
        i = i + 4;
        
        //increment things
        queueCount++;
        
        
    }
}

#pragma GCC diagnostic pop

void parseSerial() {
    readFromUART();
    parse();
}

/* [] END OF FILE */
