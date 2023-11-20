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

#ifndef QUEUE_H_
#define QUEUE_H_

/** Libraries **/
#include "Process.h"

/** Macro defintions **/
#define QUEUE_ITEM_TYPE Process *

/** Macro functions **/

/** Defined datatypes **/
typedef enum 
{
    QUEUE_NULL,
    QUEUE_EMPTY,
    QUEUE_FULL,
    QUEUE_OK,
    QUEUE_NOT_OK
}
queueStatusMsg;

typedef struct Queue
{
    int front;
    int rear;
    int capacity;
    int size;
    Process *queue;
}
Queue;

/** Functions declaration **/

/**
 * @brief Initialize new queue
 * 
 * @param queue Reference to queue variable
 * @param capacity Max size of the queue
 * @return queueStatusMsg Status message
 */
queueStatusMsg queue_init(Queue *queue, int capacity);

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