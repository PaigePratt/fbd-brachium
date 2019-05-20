#include "task.h"
#include "tasks.h"
#include "globals.h"
#include <stdlib.h>
#include <string.h>

void addToTasks(unsigned int time, taskMethod mt, unsigned int* data, unsigned int argc) {
    unsigned int index = completedTasks;
    if(totalTasks + 1 > allocatedEntries) {
        allocatedEntries += 4;
        realloc(tasks, allocatedEntries * sizeof(task_t));
    }
    
    tasks[index].Method = mt;
    tasks[index].TimeToCall = time;
    tasks[index].Data = malloc(argc* sizeof(unsigned int));
    memcpy(tasks[index].Data, data, argc* sizeof(unsigned int));
    totalTasks++;
}

//misc tasks



/* [] END OF FILE */
