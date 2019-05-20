//printf compatibility files
//probably shouldn't be changed much unless some scanf/terminal input method is ever defined

#include "project.h"

//just in case the components name changes
#define UART_WRITE_CHAR(c) UART_PutChar(c);
#define UART_READ_CHAR() UART_GetChar()

#if defined (__GNUC__)
    //this enables us to print out floating points when newlib-nano is enabled
   asm (".global _printf_float");
#endif

// in order to have output capability at all (without redefining printf and related funtions)
// _write needs to be completely rewritten
// thankfully the replacement version is actually quiet simple
int _write(int file, char* ptr, int len) {
    // i has to be predefined outside of forloops as some compilers (namely non GCC/MSVC ones)
    // dont support inline definitions
    int i;
    //this line is just here to avoid compiler warnings
    file = file;
    
    //the for loop itself just simply sends byte by byte text data
    for(i = 0; i < len; i++) {
        UART_WRITE_CHAR(*ptr++);
    }
    
    return len;
}

int _read(int file, char* ptr, int len) {
    //to ignore compiler warning
    file = file;
    int i;

    int truelen = len;
    int rxBuffsz = UART_GetRxBufferSize();
    //in the event that the rxBuffer is less than that of length of the requested string
    //only send as many bytes as have been stored 
    if(rxBuffsz < len) {
        truelen = rxBuffsz+1;
    }

    for(i = 0; i < truelen; i++) {
        *ptr++ = UART_READ_CHAR();
    }

    return truelen;
}

/* [] END OF FILE */
