#ifndef CONTROL_COMMANDS
#define CONTROL_COMMANDS 1
    
    
    //function prototypes
    
    void setStepperMotor(char* args);
    void holdStepper(char* args);
    

    typedef void (*controlFunction)(char*);
    
    //struct definitions

    typedef struct {
        controlFunction fn;
        unsigned int timeInMillisec;
        char* data;
        //this char is here to align memmory and shouldnt be used for anything more
        char align;
    } controlCommandToken;
    
    //only used in the lookup table
    typedef struct {
        controlFunction fn; 
        unsigned char argCount;
        
    } controlCommand;
    
    //controlCommand Commands[] = {
    //    {setStepperMotor, 3},
    //    {holdStepper, 1}
    //};
    
#endif
/* [] END OF FILE */
