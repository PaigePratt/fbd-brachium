#ifndef CONTROL_COMMANDS
#define CONTROL_COMMANDS 1
    
    //function prototypes
    
    void setMotorVoltage(char* args);
    void setServoPos(char* args);
    void getSensorData(char* args);

    typedef void (*controlFunction)(char*);
    
    //struct definitions

    typedef struct {
        controlFunction fn;
        char* data;
        //this char is here to align memmory and shouldnt be used for anything more
        char align;
    } controlCommandToken;
    
    //only used in the lookup table
    typedef struct {controlFunction fn; 
        unsigned char argCount;
    } controlCommand;
    
    //controlCommand functionTable[] = {
    //    {setMotorVoltage, 2},
    //    {setServoPos, 2},
    //    {getSensorData, 2}
    //};

#endif
/* [] END OF FILE */
