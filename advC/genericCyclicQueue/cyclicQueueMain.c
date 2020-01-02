#include "cyclicQueue.h"
#include <stdio.h>

typedef struct RandStruc RandStruc;

struct RandStruc
{
	int m_randInt;
	char m_randChar;
	float m_randFloat;
};

void RandStrucDestroy (void* _item)
{
	free((RandStruc*)_item);
	return;	
}

int RandStrucPrint (void* _element, size_t _index, void* _context)
{
	printf("%p\n",_element);
	printf("%d\n",((RandStruc*)_element)->m_randInt);
	return 1;
}

void  QueueCreateTest()
{
	if ( Queue_Create(0) == NULL)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( Queue_Create(5) != NULL)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	
}

void QueueDestroyTest()
{
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s2p = (RandStruc*)malloc(sizeof(RandStruc));
	Queue* myQueue;
	myQueue =  Queue_Create(5);
	Queue_Destroy(&myQueue,NULL);
	if (myQueue == NULL)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	Queue_Destroy(&myQueue,NULL);
	Queue_Destroy(&myQueue,NULL);
	myQueue =  Queue_Create(5);
	Queue_Destroy(&myQueue,RandStrucDestroy);
	if (myQueue == NULL)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	Queue_Destroy(&myQueue,RandStrucDestroy);
	Queue_Destroy(&myQueue,RandStrucDestroy);
	myQueue =  Queue_Create(5);
	Queue_Enqueue(myQueue,(void*) s1p);
	Queue_Enqueue(myQueue,(void*) s2p);
	if (myQueue != NULL)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	Queue_Destroy(&myQueue,RandStrucDestroy);
	if (myQueue == NULL)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	Queue_Destroy(&myQueue,RandStrucDestroy);
	Queue_Destroy(&myQueue,RandStrucDestroy);
}

void QueueIsEmptyTest()
{
	Queue* myQueue;
	void* temp;
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	myQueue =  Queue_Create(2);
	
	if (Queue_IsEmpty(NULL) == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if (Queue_IsEmpty(myQueue) == 1)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	Queue_Enqueue(myQueue,(void*) s1p);
	if (Queue_IsEmpty(myQueue) == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	Queue_Dequeue(myQueue, &temp);
	if (Queue_IsEmpty(myQueue) == 1)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	Queue_Destroy(&myQueue,RandStrucDestroy);
}

void 	EnqueueDequeueTest()
{
	Queue* myQueue;
	void* temp;
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s2p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s3p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s4p = (RandStruc*)malloc(sizeof(RandStruc));
	s1p->m_randInt = 1;
	s2p->m_randInt = 2;
	s3p->m_randInt = 3;
	s4p->m_randInt = 4;
	myQueue =  Queue_Create(3);
	if ( Queue_Enqueue(myQueue,(void*) s1p) == QUEUE_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( Queue_Enqueue(myQueue,(void*) s2p) == QUEUE_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( Queue_Enqueue(myQueue,(void*) s3p) == QUEUE_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( Queue_Enqueue(myQueue,(void*) s4p) == QUEUE_OVERFLOW)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( Queue_Enqueue(NULL,(void*) s4p) == QUEUE_UNINITIALIZED_ERROR)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	Queue_Dequeue(myQueue, &temp);
	if ( temp == s1p)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	Queue_Dequeue(myQueue, &temp);
	if ( temp == s2p)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	Queue_Dequeue(myQueue, &temp);
	if ( temp == s3p)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	Queue_Dequeue(myQueue, &temp);
	if ( temp == s3p)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if (Queue_Dequeue(myQueue, &temp) == QUEUE_UNDERFLOW)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	Queue_Destroy(&myQueue,RandStrucDestroy);
}

int main()
{
	QueueCreateTest();
	QueueDestroyTest();
	QueueIsEmptyTest();
	EnqueueDequeueTest();
	return 1;
}
