/**
 * @file Process.c
 * @author Abdullah Elsayed Ahmed
 * @brief Functions defintion for Process.h
 * @version 0.1
 * @date 2023-11-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/** Libraries **/
#include <stdlib.h>
#include <string.h>
#include "Process.h"

/** Functions defintions **/

/**
 * @brief Initialize a new process.
 * 
 * @param name Process program name.
 * @param time The number of time required to finish the process.
 * @param process_dist The Address to store the new process.
 * @return Std_code Status message.
 */
Std_code process_init(Process **process_dist, const char *name, const int time)
{
    Std_code ret = STD_OK;
    static unsigned int pid = 0;

    // Invalid argument
    if (process_dist == NULL)
    {
        return STD_NULL_POINTER;
    }
    else
    {
        *process_dist = (Process *) malloc(sizeof(Process));

        // Out of memory
        if (*process_dist == NULL)
        {
            ret = STD_NULL_POINTER;
        }
        else
        {
            (*process_dist)->name = (char *) malloc(sizeof(char *) * strlen(name));
            strcpy((*process_dist)->name, name);
            (*process_dist)->pid = pid;
            (*process_dist)->time = time;
            (*process_dist)->status = PROCESS_WAITING;

            pid++;
        }
    }

    return ret;
}

/**
 * @brief Make random new process with incrementing PID.
 * 
 * @param process_dist The Address to store the new process.
 * @return Std_code Status message.
 */
Std_code process_create_random(Process **process_dist)
{
    const char *processNames[] = {"firefox", "chrome", "explorer", "notepad", "bash", "python", "java", "winlogon", "systemd", "init", "svchost", "lsass", "cmd", "powershell", "iexplore", "outlook", "word", "excel", "vscode", "git", "spotify", "zoom", "slack", "discord", "explorer", "mspaint", "calc", "taskmgr", "regedit", "notepad++", "filezilla", "putty", "sublime", "chrome", "firefox", "edge", "opera", "brave", "safari", "thunderbird", "onenote", "steam", "telegram", "whatsapp", "zoom", "teams", "vlc", "microsoftedge"};
    int processNamesLength = ((float) sizeof(processNames)) / sizeof(processNames[0]);

    int randomTime = rand() % 100 + 1; // Generate a random number between 1 and 100
    int randomName = rand() % processNamesLength; // Generate a random number between 0 and processNamesLength - 1

    return process_init(process_dist, processNames[randomName], randomTime);
}

/**
 * @brief Create string value for (process's name, pid, and time).
 * 
 * @param process Current status of the process.
 * @param str_dist The Address to store the output.
 * @return Std_code Status message.
 */
Std_code process_to_string(Process *process, char *str_dist)
{
    Std_code ret = STD_OK;
    if (process == NULL)
    {
        ret = STD_NULL_POINTER;
    }
    else
    {
        if (str_dist != NULL)
        {
            char temp[10];

            strcpy(str_dist, "");
            strcat(str_dist, process->name);
            strcat(str_dist, ",");

            itoa(process->pid, temp, 10);
            strcat(str_dist, temp);
            strcat(str_dist, ",");

            itoa(process->time, temp, 10);
            strcat(str_dist, temp);
            strcat(str_dist, ",");

            process_status_msg(process->status, temp);
            strcat(str_dist, temp);
        }
    }

    return ret;
}   

/**
 * @brief Take the time done and subtract it from process's time.
 * 
 * @param process Reference to process variable. 
 * @param time_finished Time which done processing.
 * @return Std_code Status message.
 */
Std_code process_update(Process *process, const int time_finished)
{
    Std_code ret = STD_OK;
    if (process == NULL)
    {
        ret = STD_NULL_POINTER;
    }
    else
    {
        if (time_finished >= process->time)
        {
            process->time = 0;
            process->status = PROCESS_DONE;
        }
        else
        {
            process->time -= time_finished;
        }
    }

    return ret;
}

/**
 * @brief Get the process time and save it to time_dist
 * 
 * @param process Reference to process variable. 
 * @param time_dist The Address to store process's time.
 * @return Std_code Status message.
 */
Std_code process_get_time(Process *process, int *time_dist)
{
    Std_code ret = STD_OK;
    if (process == NULL)
    {
        ret = STD_NULL_POINTER;
    }
    else
    {
        if (time_dist != NULL)
        {
            *time_dist = process->time;
        }
    }

    return ret;
}

/**
 * @brief Set status value of the process.
 * 
 * @param process Reference to process variable.
 * @return Std_code process'status
 */
Std_code process_set_status(Process *process, Std_code status)
{
    Std_code ret;

    if (process == NULL)
    {
        ret = STD_NULL_POINTER;
    }
    else
    {
        if (process_status_msg(status, NULL) == PROCESS_INVALID)
        {
            ret = PROCESS_INVALID;
        }
        else
        {
            process->status;
            ret = status;
        }
    }
    return ret;
}

/**
 * @brief Get the process status and save it to status.
 * 
 * @param process Reference to process variable. 
 * @param status The Address to store process's status.
 * @return Std_code Status message.
 */
Std_code process_get_status(Process *process, processStatus *status)
{
    Std_code ret = STD_OK;

    if (process == NULL || status == NULL)
    {
        ret = STD_NULL_POINTER;
    }
    else
    {
        *status = process->status;
    }

    return ret;
}

/**
 * @brief Update process status.
 * 
 * @param process Reference to process variable. 
 * @param status Status value to update.
 * @return Std_code Status message.
 */
Std_code process_update_status(Process *process, processStatus status)
{
    Std_code ret = STD_OK;

    if (process == NULL)
    {
        ret = STD_NULL_POINTER;
    }
    else
    {
        if (process_status_msg(status, NULL) == PROCESS_INVALID)
        {
            ret = STD_NOT_OK;
        }

        process->status = status;
    }
    
    return ret;
}

/**
 * @brief Print message for status code or to check the validation of the status
 * 
 * @param status status code.
 * @param msg Reference to the msg distentions. 
 * @return Std_code status
 */
Std_code process_status_msg(Std_code status, char *res_msg)
{
    Std_code ret = status;
    char temp[30];

    switch (status) 
    {
        case PROCESS_REJECTED:
            strcpy(temp, "Rejected");
            break;
        case PROCESS_WAITING:
            strcpy(temp, "Waiting");
            break;
        case PROCESS_READY:
            strcpy(temp, "Ready");
            break;
        case PROCESS_RUNNING:
            strcpy(temp, "Running");
            break;
        case PROCESS_DONE:
            strcpy(temp, "Done");
            break;
        default:
            strcpy(temp, "Invalid Code");  
            ret = PROCESS_INVALID;          
    }

    if (res_msg != NULL)
    {
       strcpy(res_msg, temp);  
    }

    return ret;
}

/**
 * @brief Free all memory allocated by the process.
 * 
 * @param process Reference to process variable. 
 * @return Std_code Status message.
 */
Std_code process_destroy(Process *process)
{
    Std_code ret = STD_OK;
    if (process == NULL)
    {
        ret = STD_NULL_POINTER;
    }
    else
    {
        free(process->name);
        free(process);
    }

    return ret;
}