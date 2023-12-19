/**
 * @file main.c
 * @author Abdullah Elsayed Ahmed (ID: 7459, Group: 3, Section: 2)
 * @brief Program to simulate CPU Scheduling with 3 Queues
 * @version 0.1
 * @date 2023-11-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include "controller/Scheduler.h"
#include "models/Process.h"
#include <time.h>

#define NUMBER_OF_PROCESS 100

int main(void)
{
    srand((unsigned int)time(NULL));
    Scheduler *scheduler;
    schedulerStatus scheduler_status;
    processStatus process_status;
    char process_print[100];
    int current_process_index = 0;
    Process *process_holder;
    Process *processes[NUMBER_OF_PROCESS];

    scheduler_init(&scheduler);

    for (current_process_index = 0; current_process_index < NUMBER_OF_PROCESS; current_process_index++)
    {
        process_create_random(&processes[current_process_index]);
    }


    current_process_index = 0;

    while (1)    
    {
        if (current_process_index < NUMBER_OF_PROCESS)
        {
            scheduler_add_process(scheduler, processes[current_process_index++]);
        }
        
        scheduler_make_process_ready(scheduler);

        scheduler_run(scheduler, &process_holder);

        process_get_status(process_holder, &process_status);

        if (process_status == PROCESS_TERMINATED)
        {
            process_to_string(process_holder, process_print);
            printf("%s\n", process_print);
            process_destroy(process_holder);
            process_holder = NULL;
        }

        scheduler_status_code(scheduler, &scheduler_status);

        if (scheduler_status == SCHEDULER_ALL_DONE)
        {
            break;
        }
    }
    
    scheduler_destroy(scheduler);
    
    return 0;
}