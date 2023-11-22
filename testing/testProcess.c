/**
 * @file testProcess.c
 * @author Abdullah Elsayed Ahmed
 * @brief Program to Test Queue code
 * @version 0.1
 * @date 2023-11-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "models/Process.h"

int main(void)
{
    srand(time(NULL)); // Seed the random number generator with the current time
    Std_code status_code;
    char process_str[50];
    char status_msg[50];
    Process *processes[10];

    printf("------- Create ------\n");

    for (int i = 0; i < 10; i++)
    {
        status_code = process_create_random(&processes[i]);
        process_status_msg(status_code, status_msg);
        printf("Status Code: %d\n", status_code);
        printf("Status message: %s\n", status_msg);
        process_to_string(processes[i], process_str);
        printf("Process'data: %s\n", process_str);
    }

    printf("------- Update ------\n");

    for (int i = 0; i < 10; i++)
    {
        status_code = process_update(processes[i], 50);
        std_code_msg(status_code, status_msg);
        printf("Status Code: %d\n", status_code);
        printf("Status message: %s\n", status_msg);

        if (status_code != PROCESS_DONE)
        {
            process_to_string(processes[i], process_str);
            printf("Process'data: %s\n", process_str);
        }
        else
        {
            processes[i] = NULL;
        }
    }

    printf("------- Destroy ------\n");

    for (int i = 0; i < 10; i++)
    {
        status_code = process_destroy(processes[i]);
        std_code_msg(status_code, status_msg);
        printf("Status Code: %d\n", status_code);
        printf("Status message: %s\n", status_msg);
    }
}