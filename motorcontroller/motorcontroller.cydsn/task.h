#ifndef TASK
#define TASK

typedef unsigned int(*taskMethod)(unsigned int*);

typedef struct task_s {
    taskMethod Method;
    unsigned int TimeToCall;
    unsigned int* Data;
} task_t;



void addToTasks(unsigned int time, taskMethod mt, unsigned int* data, unsigned int argc);


#endif

/* [] END OF FILE */
