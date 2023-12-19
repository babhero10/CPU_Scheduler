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
#include <string.h>
#include "../models/Std_codes.h"
#include "../models/Queue.h"
#include "../models/Process.h"

/** Macro defintions **/
#define MAX_JOB_QUEUE 100
#define MAX_QUEUE1 10
#define MAX_QUEUE2 20
#define MAX_QUEUE3 30

/** Macro functions **/

/** Defined datatypes **/
typedef enum 
{
    SCHEDULER_ALL_READY, // When there is no process in job queue.
    SCHEDULER_RUNNING,   // ALL good no errors.
    SCHEDULER_ALL_DONE,  // When there is no process in any queue.
}
schedulerStatus;

typedef struct Scheduler Scheduler;

/** Functions declaration **/

/**
 * @brief Initialize a new scheduler.
 * 
 * @param scheduler Address to store the new scheduler.
 * @return Std_code status of the operation.
 */
Std_code scheduler_init(Scheduler **scheduler_dist);

/**
 * @brief Responsible for adding process to job queue.
 * 
 * @param scheduler Reference to the scheduler.
 * @param process Reference to process to add.
 * @return Std_code 
 */
Std_code scheduler_add_process(Scheduler *scheduler, Process *process);

/**
 * @brief Takes process from jobQueue to Queue1.
 * 
 * @param scheduler Reference to the scheduler.
 * @return Std_code 
 */
Std_code scheduler_make_process_ready(Scheduler *scheduler);

/**
 * @brief Responsible for running scheduler once.
 * 
 * @param scheduler Reference to the scheduler.
 * @param process Store finished process.
 * @return Std_code 
 */
Std_code scheduler_run(Scheduler *scheduler, Process **process);

/**
 * @brief Responsible for running queue1 once.
 * 
 * @param scheduler Reference to the scheduler.
 * @param process Store worked on process into this variable.
 * @return Std_code 
 */
Std_code scheduler_queue1_run(Scheduler *scheduler, Process **process);

/**
 * @brief Responsible for running queue2 once.
 * 
 * @param scheduler Reference to the scheduler.
 * @param process Store worked on process into this variable.
 * @return Std_code 
 */
Std_code scheduler_queue2_run(Scheduler *scheduler, Process **process);

/**
 * @brief Responsible for running queue3 once.
 * 
 * @param scheduler Reference to the scheduler.
 * @param process Store worked on process into this variable.
 * @return Std_code 
 */
Std_code scheduler_queue3_run(Scheduler *scheduler, Process **process);

/**
 * @brief Get scheduler current status.
 * 
 * @param scheduler Reference to the scheduler.
 * @param status Store scheduler current status in this variable.
 * @return Std_code 
 */
Std_code scheduler_status_code(Scheduler *scheduler, schedulerStatus *status);

/**
 * @brief Get scheduler current status msg.
 * 
 * @param scheduler Reference to the scheduler.
 * @param msg Store scheduler current status msg in this variable.
 * @return Std_code 
 */
Std_code scheduler_status_msg(Scheduler *scheduler, char *msg);

/**
 * @brief free all space allocated by scheduler.
 * 
 * @param scheduler Address to scheduler target.
 * @return Std_code status of the operation.
 */
Std_code scheduler_destroy(Scheduler *scheduler);

#endif