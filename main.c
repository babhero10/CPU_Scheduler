/**
 * @file main.c
 * @author Abdullah Elsayed Ahmed (ID: 7459, Group: 3, Section: 2)
 * @brief Program to simulate CPU Scheduling with 3 Queues
 * @version 0.1
 * @date 2023-11-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include "models/Queue.h"

int main(void)
{
    Queue *queue = NULL;
    printf("Status: %d\n", queue_init(&queue, 5));
    printf("------------\n");

    int number;
    int nums[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        printf("Status enqueue: %d\n", queue_enqueue(queue, &nums[i]));
        printf("Status rear: %d\n", queue_rear(queue, &number));
        printf("Item value: %d\n", number);
        printf("Size: %d\n",queue->size);
        printf("Rear: %d         Front: %d\n", queue->rear, queue->front);
        printf("------------\n");
    }
    printf("LOOOOOOOOOOL\n");

    printf("Status: %d\n", queue_destroy(queue));
    printf("All done have a good day!\n");

    return 0;
}