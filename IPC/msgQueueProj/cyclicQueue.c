#include "cyclicQueue.h"
#include <stdlib.h>

struct Queue
{
	size_t m_size;
	size_t m_head; 
	size_t m_tail;
	size_t m_nItems;
	void** m_item;
};

Queue* Queue_Create(size_t _maxSize)
{
	Queue* queue;
	if (_maxSize == 0 )
	{
		return NULL;
	}
	queue = (Queue*)calloc(1,sizeof(Queue));
	if ( queue == NULL)
	{
		return NULL;
	}
	queue->m_item = (void**)malloc(_maxSize*sizeof(void*));
	if ( queue->m_item == NULL)
	{
		free(queue);
		return NULL;
	}
	queue->m_size = _maxSize;
	return queue;
}

Queue* Queue_Init(size_t _maxSize, Queue* _queLoc)
{
	_queLoc->m_size = _maxSize;
	_queLoc->m_head = 0;
	_queLoc->m_tail = 0;
	_queLoc->m_nItems = 0;
	_queLoc->m_item = (void**)(_queLoc + 1);
	return _queLoc;
}

int Queue_Size(Queue* _queue)
{
	return (sizeof(Queue)+sizeof(void*)*_queue->m_size);
}

void Queue_Destroy(Queue** _queue, void (*_elementDestroy)(void* _item))
{
	int count;
	if (_queue != NULL && *_queue != NULL)
	{
		if (*_elementDestroy == NULL)
		{
			free((*_queue)->m_item);
			free(*_queue);
		}
		else
		{
			for (count = 0; count < (*_queue)->m_nItems; count++)
			{
				(*_elementDestroy)((*_queue)->m_item[(count+(*_queue)->m_head)%(*_queue)->m_size]);
			}
			free((*_queue)->m_item);
			free(*_queue);
		}
		*_queue = NULL;
	}
	return;
}

Queue_Result Queue_Enqueue(Queue* _queue, void* _item)
{
	if (_queue == NULL)
	{
		return QUEUE_UNINITIALIZED_ERROR;
	}
	if ( _queue->m_nItems == _queue->m_size  )
	{
			return QUEUE_OVERFLOW; 
	}
	_queue->m_item[_queue->m_tail] = _item;
	_queue->m_nItems++;
	_queue->m_tail = (_queue->m_tail + 1) % _queue->m_size;
	return QUEUE_SUCCESS;
}

Queue_Result Queue_Dequeue(Queue* _queue, void** _pValue)
{
	if (_queue == NULL || _pValue == NULL )
	{
		return QUEUE_UNINITIALIZED_ERROR;
	}
	if (_queue->m_nItems == 0)
	{
		return QUEUE_UNDERFLOW;
	}	
	*_pValue = _queue->m_item[_queue->m_head];
	_queue->m_nItems--;
	_queue->m_head = (_queue->m_head + 1) % _queue->m_size;
	return QUEUE_SUCCESS;
}

int Queue_IsEmpty(const Queue* _queue)
{
	if (_queue == NULL)
	{
		return 0;	
	}
	if ( _queue->m_nItems == 0)
	{
		return 1;
	}
	return 0;
}

size_t Queue_ForEach(const Queue* _queue,int(*QueueElementAction)(void* _element, size_t _index, void* _context), void* _context)
{
	size_t count;
	if (_queue == NULL || QueueElementAction == NULL)
	{
		return 0;
	}
	for (count = 0; count < _queue->m_nItems; count++)
	{
		QueueElementAction(_queue->m_item[(count+_queue->m_head)%_queue->m_size], 0, NULL);
	}
	return count;
}
