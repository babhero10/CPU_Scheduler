/**
 * @file Queue.c
 * @author Abdullah Elsayed Ahmed
 * @brief Functions defintion for Queue.h
 * @version 0.1
 * @date 2023-11-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/** Libraries **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

/** Functions declaration **/

/**
 * @brief Initialize new queue.
 * 
 * @param queue Reference to queue variable to save the new Queue in.
 * @param capacity Max size of the queue.
 * @return Std_code Status message.
 */
Std_code queue_init(Queue **queue, const uint8_t capacity)
{
    Std_code ret = STD_OK;
    
    // Invalid argument
    if (queue == NULL)
    {
        ret = STD_NULL_POINTER;
    }
    else
    {

        *queue = NULL;

        Queue *newQueue = (Queue *) malloc(sizeof(Queue));

        // Out of memory
        if (newQueue == NULL)
        {
            ret = STD_OUT_OF_MEMORY;
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
                ret = STD_OUT_OF_MEMORY;
            }
            else
            {
                *queue = newQueue;
            }
        }
    }

    return ret;
}

/**
 * @brief Add new item to the end of the  queue.
 * 
 * @param queue Reference to queue variable.
 * @param item Item to add.
 * @return Std_code Status message.
 */
Std_code queue_enqueue(Queue *queue, queueItemType *item)
{
    Std_code ret = STD_OK;

    // If Queue is null
    if (queue == NULL)
    {
        ret = STD_NULL_POINTER;
    }
    else
    {
        boolean isFull;
        ret = queue_is_full(queue, &isFull);

        if (isFull)
        {
            ret = STD_NOT_OK;
        }
        else
        {
            if (ret == STD_OK)
            {
                queue->queue[((queue->rear) % (queue->capacity))] = item;
                queue->rear = (((queue->rear) + 1) % (queue->capacity));
                queue->size++;
            }
        }
    }

    return ret;
}

/**
 * @brief Remove first item from the queue.
 * 
 * @param queue Reference to queue variable.
 * @param item Return the removed item value in this variable (Can be null).
 * @return Std_code Status message.
 */
Std_code queue_dequeue(Queue *queue, queueItemType *item)
{
    Std_code ret = STD_OK;

    // If Queue is null
    if (queue == NULL)
    {
        ret = STD_NULL_POINTER;
    }
    else
    {
        boolean isEmpty;
        ret = queue_is_empty(queue, &isEmpty);

        if (isEmpty)
        {
            ret = STD_NOT_OK;
        }
        else
        {
            if (ret == STD_OK)
            {
                queue_front(queue, item);
                queue->front = (((queue->front) + 1) % (queue->capacity));
                queue->size--;
            }
        }
    }

    return ret;
}

/**
 * @brief Get the first item in the queue.
 * 
 * @param queue Reference to queue variable.
 * @param item Return the first item value in this variable.
 * @return Std_code Status message.
 */
Std_code queue_front(Queue *queue, queueItemType *item)
{
    Std_code ret = STD_OK;

    // If Queue is null
    if (queue == NULL)
    {
        ret = STD_NULL_POINTER;
    }
    else
    {
        boolean isEmpty;
        ret = queue_is_empty(queue, &isEmpty);

        if (isEmpty)
        {
            ret = STD_NOT_OK;
        }
        else
        {
            if (ret == STD_OK)
            {
                *item = *queue->queue[((queue->front) % (queue->size))];
            }
        }
    }

    return ret;
}

/**
 * @brief Get the last item in the queue.
 * 
 * @param queue Reference to queue variable.
 * @param item Return the last item value in this variable.
 * @return Std_code Status message.
 */
Std_code queue_rear(const Queue *queue, queueItemType *item)
{
    Std_code ret = STD_OK;

    // If Queue is null
    if (queue == NULL)
    {
        ret = STD_NULL_POINTER;
    }
    else
    {
        boolean isEmpty;
        ret = queue_is_empty(queue, &isEmpty);

        if (isEmpty)
        {
            ret = STD_NOT_OK;
        }
        else
        {
            if (ret == STD_OK)
            {
                *item = *queue->queue[(((queue->rear) + (queue->capacity) - 1) % (queue->capacity))];
            }
        }
    }

    return ret;
}

/**
 * @brief Check if queue is empty or not.
 * 
 * @param queue Reference to queue variable.
 * @param isEmpty Address to return the value in.
 * @return Std_code Status message. 
 */
Std_code queue_is_empty(const Queue *queue, boolean *isEmpty)
{
    Std_code ret = STD_OK;

    if (queue == NULL || isEmpty == NULL)
    {
        ret = STD_NULL_POINTER;
    }
    else
    {
        *isEmpty = (queue->size == 0);
    }

    return ret;
}

/**
 * @brief Check if queue is full or not.
 * 
 * @param queue Reference to queue variable.
 * @param isFull Address to return the value in.
 * @return Std_code Status message. 
 */
Std_code queue_is_full(const Queue *queue, boolean *isFull)
{
    Std_code ret = STD_OK;

    if (queue == NULL || isFull == NULL)
    {
        ret = STD_NULL_POINTER;
    }
    else
    {
        *isFull = (queue->size == queue->capacity);
    }

    return ret;
}

/**
 * @brief Free all variables allocated in the queue.
 * 
 * @param queue Reference to queue variable.
 * @return Std_code Status message.
 */
Std_code queue_destroy(Queue *queue)
{
    Std_code ret = STD_OK;
    
    // Check if queue not null
    if (queue == NULL)
    {
        ret = STD_NULL_POINTER;
    }
    else
    {
        free(queue->queue);
        free(queue);
    }

    return ret;
}