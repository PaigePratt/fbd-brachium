#include <stddef.h>

#include "controlFuncs.h" 

typedef struct {
    command Command;
    //argument widths are expressed in bytes
    unsigned short* ArgumentWidths;
    
    
} controlCode;

//control codes
controlCode controlCodes[] = {
    set_motor_volts, {1, 1},
    set_servo_pos, {1, 1},
    get_sensor_val,  {1, 1}
};

/* [] END OF FILE */
