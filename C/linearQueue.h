/* 
written by BL on 9.2.19
Linear Queue ADT
 */

#ifndef __LINEARQUEUE_H__
#define __LINEARQUEUE_H__

typedef enum {FAIL, SUCCESS, ALOC_ERR, UNDERFLOW_ERR, NULL_ERR} ADTErr;
typedef struct Queue Queue; 

/*
Description: creates a new Queue.
Input:	none.
Output: pointer to the new Queue, NULL if failed to allocate memory.
		Address
		NULL
*/
Queue* QueueCreate(void);

/*
Description: destroys a queue.
Input:	pointer to queue.
Output: none.
*/
void QueueDestroy(Queue* _myQueue);

/*
Description: Node Push to Tail of queue
Input:	pointer to queue, data.
Output: SUCCESS or FAIL
*/
ADTErr QueueInsert(Queue* _myQueue, int _data);

/*
Description: Node Pop from Head of queue
Input:	pointer to queue, pointer to data.
Output: SUCCESS or FAIL
*/
ADTErr QueueRemove(Queue* _myQueue, int* _data);

/*
Description: checks if list is empty
Input:	pointer to list
Output: returns 1 if empty, 0 if not or null pointer
*/
int IsQueueEmpty(Queue* _myQueue);

/*
Description: prints list, if null pointer to list prints a message
Input:	pointer to list
Output: none
*/
void QueuePrint(Queue* _myQueue);

#endif /* __LINEARQUEUE_H__ */
