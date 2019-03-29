#if !defined(CONTROL_COMMANDS)
#define CONTROL_COMMANDS 1
    
#define CCT_INQUEUE 0
#define CCT_DONE 1

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
    char state; //marks wheather or not the command is completed
} controlCommandToken;

//only used in the lookup table
typedef struct {
    controlFunction fn; 
    unsigned char argCount;
    
} controlCommand;

void resetTime(char* args);
void clearCommands(char* args);

controlCommand Commands[] = {
    {setStepperMotor, 6},
    {holdStepper, 1},
    {resetTime, 0},
    {clearCommands, 0}
};

#define COMMAND_MAX 5

#define EMERGENCY_ALL_STOP 0xff

#endif
/* [] END OF FILE */
