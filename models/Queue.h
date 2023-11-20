/**
 * @file Queue.h
 * @author Abdullah Elsayed Ahmed (ID: 7459, Group: 3, Section: 2)
 * @brief (Queue of address) data structure to help with the project 
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

/** Macro functions **/

/** Defined datatypes **/
typedef int queueItemType;

typedef enum 
{
    QUEUE_NULL,
    QUEUE_EMPTY,
    QUEUE_FULL,
    QUEUE_OK
}
queueStatusMsg;

typedef struct
{
    int front;
    int rear;
    int capacity;
    int size;
    queueItemType **queue; // Array of length capacity
}
Queue;

/** Functions declaration **/

/**
 * @brief Initialize new queue.
 * 
 * @param queue Reference to queue variable to save the new Queue in.
 * @param capacity Max size of the queue.
 * @return queueStatusMsg Status message.
 */
queueStatusMsg queue_init(Queue **queue, const int capacity);

/**
 * @brief Add new item to the end of the  queue.
 * 
 * @param queue Reference to queue variable.
 * @param item Item to add.
 * @return queueStatusMsg Status message.
 */
queueStatusMsg queue_enqueue(Queue *queue, queueItemType *item);

/**
 * @brief Remove first item from the queue.
 * 
 * @param queue Reference to queue variable.
 * @param item Return the removed item value in this variable (Can be null).
 * @return queueStatusMsg Status message.
 */
queueStatusMsg queue_dequeue(Queue *queue, queueItemType *item);

/**
 * @brief Get the first item in the queue.
 * 
 * @param queue Reference to queue variable.
 * @param item Return the first item value in this variable.
 * @return queueStatusMsg Status message.
 */
queueStatusMsg queue_front(Queue *queue, queueItemType *item);

/**
 * @brief Get the last item in the queue.
 * 
 * @param queue Reference to queue variable.
 * @param item Return the last item value in this variable.
 * @return queueStatusMsg Status message.
 */
queueStatusMsg queue_rear(const Queue *queue, queueItemType *item);

/**
 * @brief Return status of the Queue.
 * 
 * @param queue Reference to queue variable.
 * @return queueStatusMsg Status message.
 */
queueStatusMsg queue_status_check(const Queue *queue);

/**
 * @brief Print message for status code.
 * 
 * @param status status code.
 * @param msg Reference to the msg distentions. 
 */
void queue_status_msg(queueStatusMsg status, char *res_msg);

/**
 * @brief Free all variables allocated in the queue.
 * 
 * @param queue Reference to queue variable.
 * @return queueStatusMsg Status message.
 */
queueStatusMsg queue_destroy(Queue *queue);


#endif