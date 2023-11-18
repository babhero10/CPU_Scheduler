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

/** Macro functions **/

/** Defined datatypes **/
typedef struct Queue
{
    int front;
    int rear;
    int capacity;
    Process *queue;
}
Queue;

/** Functions declaration **/

/**
 * @brief Initialize new queue structure.
 * 
 * @param capacity Max number of element queue can handle.
 * @return Queue* New queue to use.
 */
Queue *queue_init(int capacity);

/**
 * @brief Add an element to the queue.
 * 
 * @param process Reference to process variable.
 */
void queue_enqueue(Process *process);

/**
 * @brief remove an element from the queue and return it.
 * 
 * @return Process* The address of process which had been removed.
 */
Process *queue_dequeue(void);

/**
 * @brief Get first element on the queue.
 * 
 * @return Process* address to the first process in queue.
 */
Process *queue_front(void);

/**
 * @brief Get last element on the queue.
 * 
 * @return Process* address to the last process in queue.
 */
Process *queue_rear(void);

/**
 * @brief Free all memory allocated by the queue.
 * 
 * @param queue Address to target queue. 
 * 
 */
void queue_destroy(Queue *queue);

#endif