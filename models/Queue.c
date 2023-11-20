/**
 * @file Queue.c
 * @author your name (you@domain.com)
 * @brief Functions defintions for Process.h
 * @version 0.1
 * @date 2023-11-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @file Queue.h
 * @author Abdullah Elsayed Ahmed (ID: 7459, Group: 3, Section: 2)
 * @brief (Queue) data structure to help with the project 
 * @version 0.1
 * @date 2023-11-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _QUEUE_H_
#define _QUEUE_H_

/** Libraries **/
#include <stdlib.h>
#include "Queue.h"

/** Functions declaration **/

/**
 * @brief Initialize new queue
 * 
 * @param queue Reference to queue variable
 * @param capacity Max size of the queue
 * @return queueStatusMsg Status message
 */
queueStatusMsg queue_init(Queue *queue, int capacity)
{
    Queue *newQueue = (Queue *) malloc(sizeof(Queue *));
    newQueue->front = 0;
    newQueue->rear = 0;
    newQueue->size = 0;
    newQueue->capacity = capacity;
    newQueue->queue = (Process *) calloc(capacity, sizeof(Process *)); // Make array of process of size capacity
    return newQueue;
}

/**
 * @brief Add new item to the end of the  queue.
 * 
 * @param queue Reference to queue variable.
 * @param item Item to add.
 * @return queueStatusMsg Status message.
 */
queueStatusMsg queue_enqueue(Queue *queue, QUEUE_ITEM_TYPE item);

/**
 * @brief Remove first item from the queue.
 * 
 * @param queue Reference to queue variable.
 * @param item Return the removed item value in this variable (Can be null).
 * @return queueStatusMsg Status message.
 */
queueStatusMsg queue_dequeue(Queue *queue, QUEUE_ITEM_TYPE *item);

/**
 * @brief Get the first item in the queue.
 * 
 * @param queue Reference to queue variable.
 * @param item Return the first item value in this variable.
 * @return queueStatusMsg Status message.
 */
queueStatusMsg queue_front(Queue *queue, QUEUE_ITEM_TYPE *item);

/**
 * @brief Get the last item in the queue.
 * 
 * @param queue Reference to queue variable.
 * @param item Return the last item value in this variable.
 * @return queueStatusMsg Status message.
 */
queueStatusMsg queue_rear(Queue *queue, QUEUE_ITEM_TYPE *item);

/**
 * @brief Return status of the Queue.
 * 
 * @param queue Reference to queue variable.
 * @return queueStatusMsg Status message.
 */
queueStatusMsg queue_status_check(Queue *queue);

/**
 * @brief Free all variables allocated in the queue.
 * 
 * @param queue Reference to queue variable.
 * @return queueStatusMsg Status message.
 */
queueStatusMsg queue_destroy(Queue *queue);
#endif