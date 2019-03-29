#include "globals.h"
#include "controlCommands.h"

//
void resetTime(char* args) {
    args = args;
    milliseconds = 0;
}

void clearCommands(char* args) {
    args = args;
    
    queueCount = 0;
}

/* [] END OF FILE */
