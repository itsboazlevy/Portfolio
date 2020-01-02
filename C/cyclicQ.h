#ifndef __CYCLICQ_H__
#define __CYCLICQ_H__
#include <stdio.h>

typedef enum
{
	SUCCESS,
	FAIL,
	ERR_NULL,
	ERR_OVERFLOW,
	ERR_UNDERFLOW
} ADTErr;

typedef struct Queue Queue;

/*
Description: creates stack
Input: initial size cant be 0 because it cant grow
Output: pointer to Queue structure, NULL if creation failed
*/
Queue* QueueCreate (size_t _size);

/*
Description: destroys stack, if destruction is executed without creation - won't preform it
Input: pointer to Queue structure. if null pointer sent wont preform operation
Output: none
*/
void QueueDestroy (Queue* _queue);

/*
Description: adds item to tail (FIFO)
Input: pointer to Queue structure and item to insert
Output: ERR_NULL for Null pointer or no previous creation, ERR_OVERFLOW if reached max size, SUCCESS if succesful
*/
ADTErr QueueInsert (Queue* _queue, int _item);

/*
Description: deletes item from head (FIFO) moves it to given pointer value.
Input: pointer to Queue structure, pointer to item that will get the deleted value.
Output: ERR_NULL for Null pointers or no previous creation, ERR_UNDERFLOW if trying to remove item and there are no items, SUCCESS if succesful
*/
ADTErr QueueRemove (Queue* _queue, int* _item);

/*
Description: checks if queue is empty
Input: pointer to queue structure
Output: If queue is empty returns SUCCESS if not returns FAIL if null pointer returns ERR_NULL
*/
int QueueIsEmpty (Queue* _queue);

/*
Description: prints queue  details and indexed list of items in it, if no vector exists prints alternative message.
Input: pointer to queue structure
Output: none
*/
void QueuePrint (Queue* _queue);

#endif /* __CYCLICQ_H__*/

