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
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

/** Functions declaration **/

/**
 * @brief Initialize new queue.
 * 
 * @param queue Reference to queue variable to save the new Queue in.
 * @param capacity Max size of the queue.
 * @return queueStatusMsg Status message.
 */
queueStatusMsg queue_init(Queue **queue, const int capacity)
{
    queueStatusMsg ret = QUEUE_OK;
    *queue = NULL;

    Queue *newQueue = (Queue *) malloc(sizeof(Queue));

    // Out of memory
    if (newQueue == NULL)
    {
        ret = QUEUE_NULL;
    } 
    else
    {
        // Initialize the queue
        newQueue->queue = (queueItemType **)malloc(sizeof(queueItemType *) * capacity);
        newQueue->front = 0;
        newQueue->rear = 0;
        newQueue->size = 0;
        newQueue->capacity = capacity;

        // Out of memory
        if (newQueue->queue == NULL)
        {
            free(newQueue);
            ret = QUEUE_NULL;
        }
        else
        {
            *queue = newQueue;
        }
    }

    return ret;
}

/**
 * @brief Add new item to the end of the  queue.
 * 
 * @param queue Reference to queue variable.
 * @param item Item to add.
 * @return queueStatusMsg Status message.
 */
queueStatusMsg queue_enqueue(Queue *queue, queueItemType *item)
{
    queueStatusMsg ret = QUEUE_OK;

    // If Queue is null or full exit
    if (queue_status_check(queue) == QUEUE_NULL || queue_status_check(queue) == QUEUE_FULL)
    {
        ret = queue_status_check(queue);
    }
    else
    {
        queue->queue[((queue->rear) % (queue->capacity))] = item;
        queue->rear = (((queue->rear) + 1) % (queue->capacity));
        queue->size++;
    }

    return ret;
}

/**
 * @brief Remove first item from the queue.
 * 
 * @param queue Reference to queue variable.
 * @param item Return the removed item value in this variable (Can be null).
 * @return queueStatusMsg Status message.
 */
queueStatusMsg queue_dequeue(Queue *queue, queueItemType *item)
{
    queueStatusMsg ret = QUEUE_OK;

    // If Queue is null or empty exit
    if (queue_status_check(queue) == QUEUE_NULL || queue_status_check(queue) == QUEUE_EMPTY)
    {
        ret = queue_status_check(queue);
    }
    else
    {
        queue_rear(queue, item);
        queue->rear = (((queue->rear) + (queue->capacity) - 1) % (queue->capacity));
        queue->size--;
    }

    return ret;
}

/**
 * @brief Get the first item in the queue.
 * 
 * @param queue Reference to queue variable.
 * @param item Return the first item value in this variable.
 * @return queueStatusMsg Status message.
 */
queueStatusMsg queue_front(Queue *queue, queueItemType *item)
{
    queueStatusMsg ret = QUEUE_OK;

    // If Queue is null or empty make item NULL
    if (queue_status_check(queue) == QUEUE_NULL || queue_status_check(queue) == QUEUE_EMPTY)
    {
        ret = queue_status_check(queue);
    }
    else
    {
        *item = *queue->queue[((queue->front) % (queue->size))];
    }

    return ret;
}

/**
 * @brief Get the last item in the queue.
 * 
 * @param queue Reference to queue variable.
 * @param item Return the last item value in this variable.
 * @return queueStatusMsg Status message.
 */
queueStatusMsg queue_rear(const Queue *queue, queueItemType *item)
{
    queueStatusMsg ret = QUEUE_OK;

    // If Queue is null or empty make item NULL
    if (queue_status_check(queue) == QUEUE_NULL || queue_status_check(queue) == QUEUE_EMPTY)
    {
        ret = queue_status_check(queue);
    }
    else
    {
        *item = *queue->queue[(((queue->rear) + (queue->capacity) - 1) % (queue->capacity))];
    }

    return ret;
}

/**
 * @brief Return status of the Queue.
 * 
 * @param queue Reference to queue variable.
 * @return queueStatusMsg Status message.
 */
queueStatusMsg queue_status_check(const Queue *queue)
{
    queueStatusMsg ret = QUEUE_OK;

    if (queue == NULL)
    {
        ret = QUEUE_NULL;
    }
    else if (queue->size == queue->capacity)
    {
        ret = QUEUE_FULL;
    }
    else if (queue->size == 0)
    {
        ret = QUEUE_EMPTY;
    }

    return ret;
}

/**
 * @brief Free all variables allocated in the queue.
 * 
 * @param queue Reference to queue variable.
 * @return queueStatusMsg Status message.
 */
queueStatusMsg queue_destroy(Queue *queue)
{
    queueStatusMsg ret = QUEUE_OK;
    
    // Check if queue not null
    if (queue_status_check(queue) == QUEUE_NULL)
    {
        ret = QUEUE_NULL;
    }
    else
    {
        free(queue->queue);
        free(queue);
        ret = QUEUE_OK;
    }

    return ret;
}

#endif