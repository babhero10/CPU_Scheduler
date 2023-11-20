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
    char statusMsg[50];
    queueStatusMsg statusCode; 
    Queue *queue = NULL;

    statusCode = queue_init(&queue, 5);
    queue_status_msg(statusCode, statusMsg);

    printf("Init Status Code: %d\n", statusCode);
    printf("Init Status Message: %s\n", statusMsg);
    printf("------------\n");

    int number;
    int nums[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        statusCode = queue_enqueue(queue, &nums[i]);
        queue_status_msg(statusCode, statusMsg);

        printf("queue_enqueue Status Code: %d\n", statusCode);
        printf("queue_enqueue Status Message: %s\n", statusMsg);

        statusCode = queue_rear(queue, &number);
        queue_status_msg(statusCode, statusMsg);

        printf("queue_rear Status Code: %d\n", statusCode);
        printf("queue_rear Status Message: %s\n", statusMsg);

        printf("Item value: %d\n", number);
        printf("Size: %d\n",queue->size);
        printf("Rear: %d         Front: %d\n", queue->rear, queue->front);
        printf("------------\n");
    }

    for (int i = 0; i < 8; i++)
    {
        statusCode = queue_dequeue(queue, &number);
        queue_status_msg(statusCode, statusMsg);

        printf("queue_dequeue Status Code: %d\n", statusCode);
        printf("queue_dequeue Status Message: %s\n", statusMsg);

        printf("Item value: %d\n", number);
        printf("Size: %d\n",queue->size);
        printf("Rear: %d         Front: %d\n", queue->rear, queue->front);
        printf("------------\n");
    }

    for (int i = 0; i < 9; i++)
    {
        statusCode = queue_enqueue(queue, &nums[i]);
        queue_status_msg(statusCode, statusMsg);

        printf("queue_enqueue Status Code: %d\n", statusCode);
        printf("queue_enqueue Status Message: %s\n", statusMsg);

        statusCode = queue_rear(queue, &number);
        queue_status_msg(statusCode, statusMsg);

        printf("queue_rear Status Code: %d\n", statusCode);
        printf("queue_rear Status Message: %s\n", statusMsg);

        printf("Item value: %d\n", number);
        printf("Size: %d\n",queue->size);
        printf("Rear: %d         Front: %d\n", queue->rear, queue->front);
        printf("------------\n");
    }

    statusCode = queue_destroy(queue);
    queue_status_msg(statusCode, statusMsg);

    printf("queue_destroy Status Code: %d\n", statusCode);
    printf("queue_destroy Status Message: %s\n", statusMsg);
  
    printf("All done have a good day!\n");

    return 0;
}