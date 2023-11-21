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
#include "../models/Queue.h"
#include "../models/Process.h"

/** Macro defintions **/
typedef enum 
{
    PROCESS_NULL,
    PROCESS_WAITING,
    PROCESS_READY,
    PROCESS_RUNNING,
    PROCESS_DONE,
    PROCESS_OK
}
processStatusMsg;

typedef struct
{
    Queue *waitingQueue; // Any new process store here first with size of 100
    Queue *Queue1;       // Queue with Q = 8  and size = 10
    Queue *Queue2;       // Queue with Q = 16 and size = 20
    Queue *Queue3;       // Queue with FCFS   and size = 30
}
Scheduler;

/** Macro functions **/


/** Functions declaration **/


#endif