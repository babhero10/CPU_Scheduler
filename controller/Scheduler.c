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
#include "Scheduler.h"

/** Functions defintions **/

/**
 * @brief Initialize a new scheduler.
 * 
 * @param scheduler Address to store the new scheduler.
 * @return schedulerStatusMsg Current status of the operation.
 */
schedulerStatusMsg scheduler_init(Scheduler **scheduler_dist)
{
    schedulerStatusMsg ret = SCHEDULER_OK; 
    if (scheduler_dist == NULL)
    {
        ret = SCHEDULER_NULL;
    }
    else
    {
        *scheduler_dist = (Scheduler *) malloc(sizeof(Scheduler));

        // Out of memory
        if (*scheduler_dist == NULL)
        {
            ret = SCHEDULER_NULL;
        }
        else
        {
            queue_init(&(*scheduler_dist)->waitingQueue, MAX_WAIT_QUEUE);
            queue_init(&(*scheduler_dist)->Queue1, MAX_QUEUE1);
            queue_init(&(*scheduler_dist)->Queue2, MAX_QUEUE1);
            queue_init(&(*scheduler_dist)->Queue3, MAX_QUEUE1);
        }
    }

    return ret;
}