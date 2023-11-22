/**
 * @file Process.h
 * @author Abdullah Elsayed Ahmed
 * @brief Process data type and function
 * @version 0.1
 * @date 2023-11-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PROCESS_H_
#define PROCESS_H_

/** Libraries **/
#include "Std_types.h"
#include "Std_codes.h"

/** Macro defintions **/

/** Macro functions **/

/** Defined datatypes **/
typedef enum 
{
    PROCESS_REJECTED,  // Process is rejected by scheduler.
    PROCESS_WAITING,   // Process is in waiting queue (Default).
    PROCESS_READY,     // Process is Ready.
    PROCESS_RUNNING,   // Process is Running.
    PROCESS_DONE,      // Process is terminated.
    PROCESS_INVALID    // Invalid process status.
}
processStatus;

typedef struct Process
{
    char *name;
    int pid;
    int time;
    processStatus status;
}
Process;

/** Functions declaration **/

/**
 * @brief Initialize a new process.
 * 
 * @param process_dist The Address to store the new process.
 * @param name Process program name.
 * @param pid  Process ID Number.
 * @param time The number of time required to finish the process.
 * @return Std_code Status message.
 */
Std_code process_init(Process **process_dist, const char *name, const int time);

/**
 * @brief Make random new process with incrementing PID.
 * 
 * @param process_dist The Address to store the new process.
 * @return Std_code Status message.
 */
Std_code process_create_random(Process **process_dist);

/**
 * @brief Create string value for (process's name, pid, and time).
 * 
 * @param process Current status of the process.
 * @param str_dist The Address to store the output.
 * @return Std_code Status message.
 */
Std_code process_to_string(Process *process, char *str_dist);

/**
 * @brief Take the time done and subtract it from process's time.
 * 
 * @param process Reference to process variable. 
 * @param time_finished Time which done processing.
 * @return Std_code Status message.
 */
Std_code process_update(Process *process, const int time_finished);

/**
 * @brief Get the process time and save it to time_dist.
 * 
 * @param process Reference to process variable. 
 * @param time_dist The Address to store process's time.
 * @return Std_code Status message.
 */
Std_code process_get_time(Process *process, int *time_dist);

/**
 * @brief Get the process status and save it to status.
 * 
 * @param process Reference to process variable. 
 * @param status The Address to store process's status.
 * @return Std_code Status message.
 */
Std_code process_get_status(Process *process, processStatus *status);

/**
 * @brief Update process status.
 * 
 * @param process Reference to process variable. 
 * @param status Status value to update.
 * @return Std_code Status message.
 */
Std_code process_update_status(Process *process, processStatus status);

/**
 * @brief Print message for status code or to check the validation of the status
 * 
 * @param status status code.
 * @param msg Reference to the msg distentions. 
 * @return Std_code status.
 */
Std_code process_status_msg(Std_code status, char *res_msg);

/**
 * @brief Free all memory allocated by the process.
 * 
 * @param process Reference to process variable. 
 * @return Std_code Status message.
 */
Std_code process_destroy(Process *process);

#endif