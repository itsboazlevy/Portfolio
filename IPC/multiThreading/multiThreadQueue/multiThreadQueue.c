#include "multiThreadQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define ALIVE 0
#define DEAD 1

struct Queue
{
	void** m_item;
	size_t m_size;
	size_t m_head; 
	size_t m_tail;
	size_t m_nItems;
	size_t m_lifeFlag;
	size_t m_waitingThreads;
	pthread_cond_t m_cond;
	pthread_mutex_t m_mutex;
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
	pthread_cond_init(&(queue->m_cond), NULL);
	pthread_mutex_init(&(queue->m_mutex), NULL);
	return queue;
}

void Queue_Destroy(Queue** _queue, void (*_elementDestroy)(void* _item))
{
	int count;
	if (_queue != NULL && *_queue != NULL)
	{
		pthread_mutex_lock(&((*_queue)->m_mutex));
		(*_queue)->m_lifeFlag = DEAD; 
		if ( (*_queue)->m_waitingThreads != 0)
		{
			pthread_cond_broadcast(&((*_queue)->m_cond));
			pthread_cond_wait(&((*_queue)->m_cond), &((*_queue)->m_mutex));   
		}
		if (*_elementDestroy != NULL)
		{
			for (count = 0; count < (*_queue)->m_nItems; count++)
			{
				(*_elementDestroy)((*_queue)->m_item[(count+(*_queue)->m_head)%(*_queue)->m_size]);
			}
		}
		pthread_mutex_unlock(&((*_queue)->m_mutex));
		pthread_cond_destroy(&((*_queue)->m_cond));
		pthread_mutex_destroy(&((*_queue)->m_mutex));
		free((*_queue)->m_item);
		free(*_queue);
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
	pthread_mutex_lock(&(_queue->m_mutex));
	while( _queue->m_lifeFlag == ALIVE && _queue->m_nItems == _queue->m_size)
	{
		_queue->m_waitingThreads++;
		pthread_cond_wait(&(_queue->m_cond),&(_queue->m_mutex));	
		_queue->m_waitingThreads--;
	}
	if ( _queue->m_lifeFlag != ALIVE)
	{
		if ( _queue->m_waitingThreads == 0)
		{
			pthread_cond_signal(&_queue->m_cond);
		}
		pthread_mutex_unlock(&(_queue->m_mutex));
		return QUEUE_UNINITIALIZED_ERROR;
	}
	_queue->m_item[_queue->m_tail] = _item;
	_queue->m_nItems++;
	_queue->m_tail = (_queue->m_tail + 1) % _queue->m_size;
	pthread_cond_broadcast(&(_queue->m_cond));
	pthread_mutex_unlock(&(_queue->m_mutex));
	return QUEUE_SUCCESS;
}

Queue_Result Queue_Dequeue(Queue* _queue, void** _pValue)
{
	if (_queue == NULL || _pValue == NULL )
	{
		return QUEUE_UNINITIALIZED_ERROR;
	}
	pthread_mutex_lock(&(_queue->m_mutex));
	while( _queue->m_lifeFlag == ALIVE && _queue->m_nItems == 0)
	{
		_queue->m_waitingThreads++;
		pthread_cond_wait(&(_queue->m_cond),&(_queue->m_mutex));	
		_queue->m_waitingThreads--;
	}
	if ( _queue->m_lifeFlag != ALIVE)
	{
		if ( _queue->m_waitingThreads == 0)
		{
			pthread_cond_signal(&_queue->m_cond);
		}
		pthread_mutex_unlock(&(_queue->m_mutex));
		return QUEUE_UNINITIALIZED_ERROR;
	}
	*_pValue = _queue->m_item[_queue->m_head];
	_queue->m_nItems--;
	_queue->m_head = (_queue->m_head + 1) % _queue->m_size;
	pthread_cond_broadcast(&(_queue->m_cond));
	pthread_mutex_unlock(&(_queue->m_mutex));
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

size_t Queue_ForEach(Queue* _queue,int(*QueueElementAction)(void* _element, size_t _index, void* _context), void* _context)
{
	size_t count;
	if (_queue == NULL || QueueElementAction == NULL)
	{
		return 0;
	}
	for (count = 0; count < _queue->m_nItems; count++)
	{
		pthread_mutex_lock(&(_queue->m_mutex));
		QueueElementAction(_queue->m_item[(count+_queue->m_head)%_queue->m_size], 0, NULL);
		pthread_mutex_unlock(&(_queue->m_mutex));
	}
	return count;
}
