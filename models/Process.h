/**
 * @file Process.h
 * @author Abdullah Elsayed Ahmed (ID: 7459, Group: 3, Section: 2)
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

/** Macro defintions **/

/** Macro functions **/

/** Defined datatypes **/
typedef enum 
{
    PROCESS_NULL,
    PROCESS_WAIT,
    PROCESS_READY,
    PROCESS_DONE,
    PROCESS_OK
}
processStatusMsg;

typedef struct Process
{
    char *name;
    int pid;
    int time;
}
Process;

/** Functions declaration **/

/**
 * @brief Initialize a new process.
 * 
 * @param name Process program name.
 * @param pid  Process ID Number.
 * @param time The number of time required to finish the process.
 * @param process_dist The Address to store the new process.
 * @return processStatusMsg Current status of the process.
 */
processStatusMsg process_init(const char *name, const int time, Process **process_dist);

/**
 * @brief Make random new process with incrementing PID.
 * 
 * @param process_dist The Address to store the new process.
 * @return processStatusMsg Current status of the process.
 */
processStatusMsg process_create_random(Process **process_dist);

/**
 * @brief Create string value for (process's name, pid, and time).
 * 
 * @param process Current status of the process.
 * @param str_dist The Address to store the output.
 * @return processStatusMsg Current status of the process.
 */
processStatusMsg process_to_string(Process *process, char *str_dist);

/**
 * @brief Take the time done and subtract it from process's time.
 * 
 * @param process Reference to process variable. 
 * @param time_finished Time which done processing.
 * @return processStatusMsg Current status of the process.
 */
processStatusMsg process_update(Process *process, const int time_finished);

/**
 * @brief Get the process time and save it to time_dist
 * 
 * @param process Reference to process variable. 
 * @param time_dist The Address to store process's time.
 * @return processStatusMsg Current status of the process.
 */
processStatusMsg process_get_time(Process *process, int *time_dist);

/**
 * @brief Print message for status code.
 * 
 * @param status status code.
 * @param msg Reference to the msg distentions. 
 */
void process_status_msg(processStatusMsg status, char *res_msg);

/**
 * @brief Free all memory allocated by the process.
 * 
 * @param process Reference to process variable. 
 * @return processStatusMsg Current status of the process.
 */
processStatusMsg process_destroy(Process *process);

#endif