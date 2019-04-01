#include "globals.h"
#include "controlCommands.h"

#include <string.h>

extern unsigned short lastInitializedToken;
extern unsigned short queueItor;

//so PSoC creator doesnt allow structs to be set to null and thus this exists
static controlCommandToken nullToken = {
    NULL, 0, NULL, 0
};

void resetTime(char* args) {
    args = args;
    milliseconds = 0;
}

void clearCommands(char* args) {
    args = args;
    
    queueCount = 0;
}

void pruneCompletedEvents(char* args) {
    args = args;
    
    //set all the commans to null
    for(int i = 0; i < lastInitializedToken; i++) {
        commandQueue[i] = nullToken;
    }
    //mover the entries back, reset the itorator and lastIntialized token, set the queue count to the new size 
    memmove(commandQueue, &commandQueue[lastInitializedToken+1], queueCount-lastInitializedToken);
    queueItor = 0;
    queueCount = queueCount-lastInitializedToken;
    lastInitializedToken = 0;
}

/* [] END OF FILE */
