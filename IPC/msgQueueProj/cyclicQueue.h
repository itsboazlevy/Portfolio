/**************************************************************************************
    Author :			Boazs		
    Created :      		10.3.19
    Updated :			4.4.19
    Description : 		Message Queue over Shared Memory in multi-process interlock
***************************************************************************************/
#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <stdlib.h> 

typedef struct Queue Queue;

typedef enum Queue_Result {
	QUEUE_SUCCESS,
	QUEUE_UNINITIALIZED_ERROR,				
	QUEUE_OVERFLOW,							
	QUEUE_UNDERFLOW							
} Queue_Result;

/**  
 * @brief Dynamically create a new queue object of given capacity 
 * @param[in] _maxSize - maximal number of elements that can be stored in the queue
 * @return Queue * - on success / NULL on fail 
 * @warning if _maxSize is zero function will return NULL.
 */
Queue* Queue_Create(size_t _maxSize);

/**  
 * @brief create a new queue object of given capacity in a given location within shared memory
 * @param[in] _maxSize - maximal number of elements that can be stored in the queue, _queLoc pointer to start of queue within shm object
 * @return Queue * - on success / NULL on fail 
 */
Queue* Queue_Init(size_t _maxSize, Queue* _queLoc);

/**  
 * @brief measure que size
 * @param[in] _queue 
 * @return que size by bytes
 */
int Queue_Size(Queue* _queue);

/**  
 * @brief Dynamically deallocate a previously allocated vector  
 * @param[in] _queue - Vector to be deallocated.
 * @params[in] _elementDestroy : A function pointer to be used to destroy all remaining elements in the queue or a null if no such destroy is required
 * @return void
 */
void Queue_Destroy(Queue** _queue, void (*_elementDestroy)(void* _item));

/**  
 * @brief Enqueue an Item to the tail of the Queue.  
 * @param[in] _queue - Queue to operate on.
 * @param[in] _item - Item to enqueue.
 * @return success or error code 
 * @retval QUEUE_SUCCESS on success 
 * @retval QUEUE_UNINITIALIZED_ERROR if null pointer for queue
 * @retval QUEUE_OVERFLOW if reached max capacity - queue is full	
 * @warning _item can't be null. this will be assertion violation
 */
Queue_Result Queue_Enqueue(Queue* _queue, void* _item);

/**  
 * @brief Dequeue (Remove and obtain) item at head of queue 
 * @param[in] _queue - Queue to operate on.
 * @param[out] _pValue - pointer to variable that will receive dequeued item
 * @return success or error code 
 * @retval QUEUE_SUCCESS on success 
 * @retval QUEUE_UNINITIALIZED_ERROR if null pointer for queue
 * @retval QUEUE_UNDERFLOW if no items to remove - queue is empty		
 */
Queue_Result Queue_Dequeue(Queue* _queue, void** _pValue);

/**  
 * @brief Return true if the queue is empty.
 * @param[in] _queue - Queue to check.
 * @return  1 if empty 0 otherwise
 */
int Queue_IsEmpty(const Queue* _queue);

/**
 * The following are convenience functions for debugging purposes
 */
/**  
 * @brief Iterate over all elements in the queue.
 * @details The user provided _action function will be called for each element
 *          if _action return a zero for an element the iteration will stop.  
 * @param[in] _queue  - queue to iterate over.
 * @param[in] _action - User provided function pointer to be invoked for each element
 * @param[in] _context - User provided context, will be sent to _action
 * @returns number of times the user functions was invoked
 * 
 * Example use: Queue_ForEach(queue, PrintElement, NULL)
 */
size_t Queue_ForEach(const Queue* _queue,int(*QueueElementAction)(void* _element, size_t _index, void* _context), void* _context);


#endif /* __QUEUE_H__ */