#include <stdio.h>
#include <stdlib.h>
#include "linearQueue.h"
#define MAGIC_NUM 123456789

typedef struct Node Node; 
struct Node
{
	int m_data;
	Node* m_next;
	Node* m_prev;
};

struct Queue
{
	Node m_head;
	Node m_tail;
};

Queue* QueueCreate(void)
{
	Queue* myQueue = (Queue*)malloc(sizeof(Queue));
	if (myQueue == NULL)
	{
		return NULL;
	}
	myQueue->m_head.m_next = &myQueue->m_tail;
	myQueue->m_tail.m_prev = &myQueue->m_head;
	myQueue->m_head.m_data = MAGIC_NUM;
	return myQueue;
}

void QueueDestroy(Queue* _myQueue)
{
	Node* temp;
	if (_myQueue != NULL && _myQueue->m_head.m_data == MAGIC_NUM)
	{
		while (_myQueue->m_head.m_next != &_myQueue->m_tail)
		{
			temp = _myQueue->m_head.m_next;
			_myQueue->m_head.m_next = temp->m_next;
			free(temp);
		}
		_myQueue->m_head.m_data = 0;
		free(_myQueue);
	}
}

static Node* NodeCreate(Queue* _myQueue, int _data)
{
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	if ( newNode == NULL)
	{
		return NULL;
	}
	newNode->m_data = _data;
	return newNode;
}

ADTErr QueueInsert(Queue* _myQueue, int _data)
{
	Node* newNode;
	if ( _myQueue == NULL || _myQueue->m_head.m_data != MAGIC_NUM)
	{
		return NULL_ERR;
	}
	newNode = NodeCreate(_myQueue,_data);
	if (newNode == NULL)
	{
		return ALOC_ERR;
	}
	newNode->m_prev = _myQueue->m_tail.m_prev;
	newNode->m_next = &_myQueue->m_tail;
	_myQueue->m_tail.m_prev->m_next = newNode;
	_myQueue->m_tail.m_prev = newNode;
	return SUCCESS;
}

ADTErr QueueRemove(Queue* _myQueue, int* _data)
{
	Node* temp;
	if (_myQueue == NULL || _data == NULL || _myQueue->m_head.m_data != MAGIC_NUM)
	{
		return NULL_ERR;
	}
	if (_myQueue->m_head.m_next == &_myQueue->m_tail)
	{
		return UNDERFLOW_ERR;
	}
	temp =_myQueue->m_head.m_next;
	*_data = _myQueue->m_head.m_next->m_data;
	_myQueue->m_head.m_next->m_next->m_prev = &_myQueue->m_head;
	_myQueue->m_head.m_next = _myQueue->m_head.m_next->m_next;
	free (temp);
	return SUCCESS;
}

int IsQueueEmpty(Queue* _myQueue)
{
	if (_myQueue == NULL || _myQueue->m_head.m_data != MAGIC_NUM)
	{
		return 1; 
	}
	if (_myQueue->m_head.m_next == &_myQueue->m_tail)
	{
		return 1;
	}
	return 0;
}

void QueuePrint(Queue* _myQueue)
{
	Node* temp;
	int count = 1;
	if (_myQueue == NULL || _myQueue->m_head.m_data != MAGIC_NUM)
	{
		printf("Create a List First");
	}
 	printf("List Items:\n");
 	temp = _myQueue->m_head.m_next;
	while (temp != &_myQueue->m_tail)
	{
 		printf("\nItem # %d\n",count);
 		printf("Node: %p\n",(void*)temp);
 		printf("Data: %d\n",temp->m_data);
		printf("Previous Node: %p\n",(void*)temp->m_prev);
 		printf("Next Node: %p\n",(void*)temp->m_next);
		temp = temp->m_next;
		count++;
	}
}

