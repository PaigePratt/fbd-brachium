#include "util.h"
#include "globals.h"
#include "project.h"
#include "stepperMotor.h"
#include <stdlib.h>
#include <stdio.h>

#define UARTGETCHAR() USBUART_GetChar()

#define BYTES_EXPECTED 3u

//debug varaible, marks the number of times bytes were recieved but not the the neccesary number to constitute a proper command
unsigned int dbg_falsePositives;

//parseSerialData(): contains all the code to parse and income serial data from the computer and convert it into relevant angle delta information
void parseSerialData(unsigned int sz) {
    
    //preallocate a buffer and set all entries within it to zero for saftey's sake
    signed char buff[sz+1];
    memset(buff, 0, sz+1);
    
    //get incoming serial data and put it into the buffer
    //this must be done reguardless if the data is valid data (see next block of comments)
    //otherwise the data is left within the hardware buffer and will corrupt/offset real data on the next function call
    for(unsigned int i = 0; i < sz; i++) {
        buff[i] = (signed char)UARTGETCHAR();
        USBUART_PutChar(buff[i]);
        while(!USBUART_CDCIsReady());
        
    }
    
    //we've found that there is occasional bytes and data that is sent to the machine unintentionally
    //most likely its the OS polling the device to see if it went to sleep or not
    //reguardless if the size is 
    if(sz < BYTES_EXPECTED) {
        dbg_falsePositives++;
        return;
    }
    
    //index through the bytes and convert them into proper angles and deltas
    for(int i = 0; i < UNIQUE_STMS; i++) {
        signed int angle =  (int)buff[i];
        StepperMotors[i].ControlRegWrite(currentDiv);
        StepperMotors[i].delta = (angle > 0 ? 1 : -1);
        StepperMotors[i].totalDelta = (angle)/1.8 * (StepperMotors[i].ratioNum/StepperMotors[i].ratioDen);
        
    }
}

/* [] END OF FILE */
