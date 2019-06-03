//printf compatibility files
//probably shouldn't be changed much unless some scanf/terminal input method is ever defined

#include "project.h"

//just in case the components name changes
#define UART_WRITE_CHAR(c) USBUART_PutChar(c)
#define UART_READ_CHAR() USBUART_GetChar()

#if defined (__GNUC__)
    //this enables us to print out floating points when newlib-nano is enabled
   asm (".global _printf_float");
#endif

// in order to have output capability at all (without redefining printf and related funtions)
// _write needs to be completely rewritten
// thankfully the replacement version is actually quiet simple
int _write(int file, char* ptr, int len) {
    //this line is just here to avoid compiler warnings
    file = file;
    
    char buff[len + 1];
    memset(buff, 0, len + 1);
    memcpy(buff, ptr, len);
    
    for(int i = 0; i < (len/64) + 1; i++) {
        USBUART_PutString(&buff[64*i]);
    }
    
    return len;
}
/* [] END OF FILE */
