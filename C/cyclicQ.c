#include "cyclicQ.h"
#include <stdlib.h>

struct Queue
{
	int* m_vec;
	size_t m_size;
	size_t m_head; 
	size_t m_tail;
	size_t m_nItems;
	size_t m_magicNum;
};

int NullCheck (Queue* _queue)
{
	if (_queue != NULL && _queue->m_magicNum == 1234567890)
	{
		return SUCCESS;
	}
	return ERR_NULL;
}

int NullCheckWithItem (Queue* _queue, int* _item)
{
	if (_queue != NULL && _queue->m_magicNum == 1234567890 && _item != NULL)
	{
		return SUCCESS;
	}
	return ERR_NULL;
}

Queue* QueueCreate (size_t _size)
{
	Queue* queue;
	if (_size == 0 )
	{
		return NULL;
	}
	queue = (Queue*)malloc(sizeof(Queue));
	if ( queue == NULL)
	{
		return NULL;
	}
	queue->m_vec = (int*)malloc(sizeof(int)*_size);
		if ( queue->m_vec == NULL)
	{
		free(queue);
		return NULL;
	}
	queue->m_size = _size;
	queue->m_head = 0;
	queue->m_tail = 0;
	queue->m_nItems = 0;
	queue->m_magicNum = 1234567890;
	return queue;
}

void QueueDestroy (Queue* _queue)
{
	if (NullCheck(_queue) == SUCCESS)
	{
		_queue->m_magicNum = 0;
		free(_queue->m_vec);
		free(_queue);
	}
}

ADTErr QueueInsert (Queue* _queue, int _item)
{
	if (NullCheck(_queue) != SUCCESS)
	{
		return ERR_NULL;	
	}
	if ( _queue->m_nItems == _queue->m_size  )
	{
			return ERR_OVERFLOW; 
	}
	*(_queue->m_vec + _queue->m_tail ) = _item;
	_queue->m_nItems++;
	_queue->m_tail = (_queue->m_tail + 1) % _queue->m_size;
	return SUCCESS;
}
ADTErr QueueRemove (Queue* _queue, int* _item)
{
	if (NullCheckWithItem(_queue,_item) != SUCCESS)
	{
		return ERR_NULL;	
	}
	if (_queue->m_nItems == 0)
	{
		return ERR_UNDERFLOW;
	}	
	*_item = *(_queue->m_vec + _queue->m_head);
	_queue->m_nItems--;
	_queue->m_head = (_queue->m_head + 1) % _queue->m_size;
	return SUCCESS;
}

int QueueIsEmpty (Queue* _queue)
{
	if (NullCheck(_queue) != SUCCESS)
	{
		return ERR_NULL;	
	}
	if ( _queue->m_nItems == 0)
	{
		return SUCCESS;
	}
	return FAIL;
}

void QueuePrint (Queue* _queue)
{
	int i;
	if (NullCheck(_queue) != SUCCESS)
	{
		printf("Try Creating your ADT before you print it !\n");
		return;	
	}
	printf("\n ADT Details \n");
	printf("size: %ld \n",_queue->m_size);
	printf("Head Index: %ld \n",_queue->m_head);
	printf("Tail Index: %ld \n",_queue->m_tail);
	printf("Number of Items: %ld \n",_queue->m_nItems);
	printf("Magic Number: %ld \n",_queue->m_magicNum);
	for (i=0;i < _queue->m_nItems;i++)
	{
			printf("item[%d] =  %d \n",i,*(_queue->m_vec + ((_queue->m_head +i) % _queue->m_size)));
	}
}
