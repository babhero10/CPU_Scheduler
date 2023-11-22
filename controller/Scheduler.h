/**
 * @file Scheduler.h
 * @author Abdullah Elsayed Ahmed
 * @brief This is a mulit-level CPU Scheduler algorithm
 * 
 *  50% ------>  Queue1 Q(8)  ---------> DONE
 *         ^                     |
 *         |                     |
 *         -------<---50%--------|---
 *                               |  ^
 *        --------<---------------  |
 *        |                         |                 
 *        |                         |
 *  30% ------>  Queue2 Q(16)  --------> DONE
 *                                  |
 *                                  |
 *         -------<---50%------------
 *         |  
 *         |        
 *  20% ------>  Queue3 (FCFS) --------> DONE
 * 
 * @version 0.1
 * @date 2023-11-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

/** Libraries **/
#include <stdlib.h>
#include "../models/Queue.h"
#include "../models/Process.h"

/** Macro defintions **/
#define MAX_WAIT_QUEUE 100
#define MAX_QUEUE1 10
#define MAX_QUEUE2 20
#define MAX_QUEUE3 30

/** Macro functions **/

/** Defined datatypes **/
typedef enum 
{
    SCHEDULER_NULL, // Process is null pointer.
    SCHEDULER_OK
}
schedulerStatusMsg;

typedef struct
{
    Queue *waitingQueue; // Any new process store here first with size of 100
    Queue *Queue1;       // Queue with Q = 8  and size = 10
    Queue *Queue2;       // Queue with Q = 16 and size = 20
    Queue *Queue3;       // Queue with FCFS   and size = 30
}
Scheduler;

/** Functions declaration **/

/**
 * @brief Initialize a new scheduler.
 * 
 * @param scheduler Address to store the new scheduler.
 * @return schedulerStatusMsg Current status of the operation.
 */
schedulerStatusMsg scheduler_init(Scheduler **scheduler_dist);

/**
 * @brief free all space allocated by scheduler.
 * 
 * @param scheduler Address to scheduler target.
 * @return schedulerStatusMsg Current status of the operation.
 */
schedulerStatusMsg scheduler_destroy(Scheduler *scheduler);

#endif