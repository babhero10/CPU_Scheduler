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
 * @return New process struct.
 */
Process *process_init(char *name, int pid, int time);

/**
 * @brief Make random new process with incrementing PID.
 * 
 * @return New process struct.
 */
Process *process_create_random(void);

/**
 * @brief Print process's name, pid, and time on screen.
 * 
 * @param process Reference to process variable.
 */
void process_print(Process *process);

/**
 * @brief Take the time done and subtract it from process's time.
 * 
 * @param process Reference to process variable. 
 * @param time_finished Time which done processing.
 * @return int The new time after update.
 */
int process_update(Process *process, int time_finished);

/**
 * @brief Free all memory allocated by the process.
 * 
 * @param process Reference to process variable. 
 */
void process_destroy(Process *process);

#endif