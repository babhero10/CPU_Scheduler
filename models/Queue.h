/**
 * @file Queue.h
 * @author Abdullah Elsayed Ahmed
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
#include "Std_types.h"
#include "Std_codes.h"
#include "Process.h"

/** Macro defintions **/

/** Macro functions **/

/** Defined datatypes **/
typedef Process queueItemType;

typedef struct Queue Queue;

/** Functions declaration **/

/**
 * @brief Initialize new queue.
 * 
 * @param queue Reference to queue variable to save the new Queue in.
 * @param capacity Max size of the queue.
 * @return Std_code Status message.
 */
Std_code queue_init(Queue **queue, const uint8_t capacity);

/**
 * @brief Add new item to the end of the  queue.
 * 
 * @param queue Reference to queue variable.
 * @param item Item to add.
 * @return Std_code Status message.
 */
Std_code queue_enqueue(Queue *queue, queueItemType *item);

/**
 * @brief Remove first item from the queue.
 * 
 * @param queue Reference to queue variable.
 * @param item Return the removed item value in this variable (Can be null).
 * @return Std_code Status message.
 */
Std_code queue_dequeue(Queue *queue, queueItemType **item);

/**
 * @brief Get the first item in the queue.
 * 
 * @param queue Reference to queue variable.
 * @param item Return the first item value in this variable.
 * @return Std_code Status message.
 */
Std_code queue_front(Queue *queue, queueItemType **item);

/**
 * @brief Get the last item in the queue.
 * 
 * @param queue Reference to queue variable.
 * @param item Return the last item value in this variable.
 * @return Std_code Status message.
 */
Std_code queue_rear(const Queue *queue, queueItemType **item);

/**
 * @brief Check if queue is empty or not.
 * 
 * @param queue Reference to queue variable.
 * @param isEmpty Address to return the value in.
 * @return Std_code Status message. 
 */
Std_code queue_is_empty(const Queue *queue, boolean *isEmpty);

/**
 * @brief Check if queue is full or not.
 * 
 * @param queue Reference to queue variable.
 * @param isFull Address to return the value in.
 * @return Std_code Status message. 
 */
Std_code queue_is_full(const Queue *queue, boolean *isFull);

/**
 * @brief Free all variables allocated in the queue.
 * 
 * @param queue Reference to queue variable.
 * @return Std_code Status message.
 */
Std_code queue_destroy(Queue *queue);

void printQueue(Queue* queue);
#endif