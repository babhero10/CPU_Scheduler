/**
 * @file Scheduler.c
 * @author Abdullah Elsayed Ahmed
 * @brief Functions defintion for Scheduler.h
 * @version 0.1
 * @date 2023-11-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/** Libraries **/
#include <stdlib.h>
#include <stdio.h>
#include "Scheduler.h"

/** Defined datatypes **/
typedef struct Scheduler
{
    Queue *jobQueue;     // Any new process store here first with size of 100
    Queue *Queue1;       // Queue with Q = 8  and size = 10
    Queue *Queue2;       // Queue with Q = 16 and size = 20
    Queue *Queue3;       // Queue with FCFS   and size = 30
}
Scheduler;

/** Functions defintions **/

/**
 * @brief Initialize a new scheduler.
 * 
 * @param scheduler_dist Address to store the new scheduler.
 * @return Std_code status of the operation.
 */
Std_code scheduler_init(Scheduler **scheduler_dist)
{
    Std_code ret = STD_OK; 
    if (scheduler_dist == NULL)
    {
        ret = STD_NULL_POINTER;
    }
    else
    {
        *scheduler_dist = (Scheduler *) malloc(sizeof(Scheduler));

        // Out of memory
        if (*scheduler_dist == NULL)
        {
            ret = STD_NULL_POINTER;
        }
        else
        {
            queue_init(&(*scheduler_dist)->jobQueue, MAX_JOB_QUEUE);
            queue_init(&(*scheduler_dist)->Queue1, MAX_QUEUE1);
            queue_init(&(*scheduler_dist)->Queue2, MAX_QUEUE2);
            queue_init(&(*scheduler_dist)->Queue3, MAX_QUEUE3);
        }
    }

    return ret;
}

/**
 * @brief Responsible for adding process to job queue.
 * 
 * @param scheduler Reference to the scheduler.
 * @param process Reference to process to add.
 * @return Std_code 
 */
Std_code scheduler_add_process(Scheduler *scheduler, Process *process)
{
    Std_code ret = STD_OK;
    boolean is_full;
    if (scheduler == NULL || process == NULL)
    {
        ret = STD_NULL_POINTER;
    }
    else
    {
        queue_is_full(scheduler->jobQueue, &is_full);

        if (is_full)
        {
            process_update_status(process, PROCESS_REJECTED);
            ret = STD_NOT_OK;
        }
        else
        {
            queue_enqueue(scheduler->jobQueue, process);    
            process_update_status(process, PROCESS_NEW);
        }
    }

    // printQueue(scheduler->jobQueue);
    // printf("////--------------\n");/
    return ret;
}

/**
 * @brief Takes process from jobQueue to Queue1.
 * 
 * @param scheduler Reference to the scheduler.
 * @return Std_code 
 */
Std_code scheduler_make_process_ready(Scheduler *scheduler)
{
    Std_code ret = STD_OK;
    boolean is_full, is_empty;
    Process *process;
    if (scheduler == NULL)
    {
        ret = STD_NOT_OK;
    }
    else
    {
        queue_is_full(scheduler->Queue1, &is_full);
        queue_is_empty(scheduler->jobQueue, &is_empty);
        char process_print[100];
        if (!is_full && !is_empty)
        {
            queue_dequeue(scheduler->jobQueue, &process);
            queue_enqueue(scheduler->Queue1, process);
            process_update_status(process, PROCESS_READY);
        }
    }
    
    return ret;
}

/**
 * @brief Responsible for running scheduler once.
 * 
 * @param scheduler Reference to the scheduler.
 * @param process Store finished process.
 * @return Std_code 
 */
Std_code scheduler_run(Scheduler *scheduler, Process **process)
{
    Std_code ret = STD_OK;

    int prec = rand() % 101;
    
    if (scheduler == NULL)
    {
        ret = STD_NULL_POINTER;
    }
    else
    {
        
        // printf("%i\n", prec);
        if (prec >= 0 && prec < 50) 
        {
            // printf("Queue1\n");
            scheduler_queue1_run(scheduler, process);
        }
        else if (prec >= 50 && prec < 80) 
        {
            // printf("Queue2\n");
            scheduler_queue2_run(scheduler, process);
        }
        else
        {
            // printf("Queue3\n");
            scheduler_queue3_run(scheduler, process);
        }
    }

    // printQueue(scheduler->Queue1);
    // printQueue(scheduler->Queue2);
    // printQueue(scheduler->Queue3);
    // printf("----------------");
    return ret;
}

/**
 * @brief Responsible for running queue1 once.
 * 
 * @param scheduler Reference to the scheduler.
 * @param process Store worked on process into this variable.
 * @return Std_code 
 */
Std_code scheduler_queue1_run(Scheduler *scheduler, Process **process)
{
    processStatus status;
    boolean is_full;
    boolean is_empty;

    queue_is_empty(scheduler->Queue1, &is_empty);

    if (!is_empty)
    {    
        queue_dequeue(scheduler->Queue1, process);
        
        process_update(*process, 8);
        process_get_status(*process, &status);

        if (status != PROCESS_TERMINATED)
        {
            queue_is_full(scheduler->Queue2, &is_full);
            if (is_full)
            {
                queue_enqueue(scheduler->Queue1, *process);
            }
            else
            {
                queue_enqueue(scheduler->Queue2, *process);
            }
        }
    }
    
    return STD_OK;
}

/**
 * @brief Responsible for running queue2 once.
 * 
 * @param scheduler Reference to the scheduler.
 * @param process Store worked on process into this variable.
 * @return Std_code 
 */
Std_code scheduler_queue2_run(Scheduler *scheduler, Process **process)
{
    processStatus status;
    boolean is_full;
    boolean is_empty;
    int random = rand() % 2;

    queue_is_empty(scheduler->Queue2, &is_empty);

    if (!is_empty)
    {
        queue_dequeue(scheduler->Queue2, process);
        process_update(*process, 16);
        process_get_status(*process, &status);

        if (status != PROCESS_TERMINATED)
        {
            if (random == 1)
            {
                queue_is_full(scheduler->Queue1, &is_full);
                if (is_full)
                {
                    queue_enqueue(scheduler->Queue2, *process);
                }
                else
                {
                    queue_enqueue(scheduler->Queue1, *process);
                }
            }
            else
            {
                queue_is_full(scheduler->Queue3, &is_full);
                if (is_full)
                {
                    queue_enqueue(scheduler->Queue2, *process);
                }
                else
                {
                    queue_enqueue(scheduler->Queue3, *process);
                }
            }
        }
    }
    return STD_OK;
}

/**
 * @brief Responsible for running queue3 once.
 * 
 * @param scheduler Reference to the scheduler.
 * @param process Store worked on process into this variable.
 * @return Std_code 
 */
Std_code scheduler_queue3_run(Scheduler *scheduler, Process **process)
{
    int process_time;
    boolean is_empty;

    queue_is_empty(scheduler->Queue3, &is_empty);
    if (!is_empty)
    {
        process_get_time(*process, &process_time);
        queue_dequeue(scheduler->Queue3, process);
        process_update(*process, process_time);
    }

    return STD_OK;
}

/**
 * @brief Get scheduler current status.
 * 
 * @param scheduler Reference to the scheduler.
 * @param status Store scheduler current status in this variable.
 * @return Std_code 
 */
Std_code scheduler_status_code(Scheduler *scheduler, schedulerStatus *status)
{
    Std_code ret = STD_OK;
    boolean isEmpty1;
    boolean isEmpty2;
    boolean isEmpty3;
    boolean isEmpty4;

    if (scheduler == NULL)
    {
        ret = STD_NULL_POINTER;
    }
    else
    {
        queue_is_empty(scheduler->jobQueue, &isEmpty1);
        queue_is_empty(scheduler->Queue1, &isEmpty2);
        queue_is_empty(scheduler->Queue2, &isEmpty3);
        queue_is_empty(scheduler->Queue3, &isEmpty4);

        if (isEmpty2 && isEmpty3 && isEmpty4)
        {
            *status = SCHEDULER_ALL_DONE;
        }
        else if (isEmpty1)
        {
            *status = SCHEDULER_ALL_READY; 
        }
        else
        {
            *status = SCHEDULER_RUNNING;
        }
    }

    return ret;
}

/**
 * @brief Get scheduler current status msg.
 * 
 * @param scheduler Reference to the scheduler.
 * @param msg Store scheduler current status msg in this variable.
 * @return Std_code 
 */
Std_code scheduler_status_msg(Scheduler *scheduler, char *msg)
{
    Std_code ret = STD_OK;
    schedulerStatus status;

    if (scheduler == NULL || msg == NULL)
    {
        ret = STD_NULL_POINTER;
    }
    else
    {
        scheduler_status_code(scheduler, &status);

        switch (status)
        {
            case SCHEDULER_ALL_READY:
                strcpy(msg, "All ready");
                break;
            
            case SCHEDULER_ALL_DONE:
                strcpy(msg, "All done");
                break;
            
            case SCHEDULER_RUNNING:
                strcpy(msg, "Running");
                break;
            
            default:
                break;
        }
    }

    return ret;
}

/**
 * @brief free all space allocated by scheduler.
 * 
 * @param scheduler Address to scheduler target.
 * @return Std_code status of the operation.
 */
Std_code scheduler_destroy(Scheduler *scheduler)
{
    Std_code ret = STD_OK; 

    if (scheduler == NULL)
    {
        ret = STD_NULL_POINTER;
    }
    else
    {
            free(scheduler->jobQueue);
            free(scheduler->Queue1);
            free(scheduler->Queue2);
            free(scheduler->Queue3);
    }

    return ret;
}