#include <stdio.h>
#include "linearQueue.h"
#define MAGIC_NUM 123456789
int main()
{
	int removedData;	
	Queue* myQueue = NULL;
	
	if ( IsQueueEmpty(myQueue) == 1)
	{
		printf("SUCCESS!\n");
	}
	else
	{
		printf("FAIL!\n");
	}
	
	if ( QueueRemove(myQueue, &removedData) == NULL_ERR)
	{
		printf("SUCCESS!\n");
	}
	else
	{
		printf("FAIL!\n");
	}	
		
	if ( QueueInsert(myQueue, 1) == NULL_ERR)
	{
		printf("SUCCESS!\n");
	}
	else
	{
		printf("FAIL!\n");
	}

	myQueue = QueueCreate();
	
	if ( IsQueueEmpty(myQueue) == 1)
	{
		printf("SUCCESS!\n");
	}
	else
	{
		printf("FAIL!\n");
	}
	
	if ( QueueRemove(NULL, &removedData) == NULL_ERR)
	{
		printf("SUCCESS!\n");
	}
	else
	{
		printf("FAIL!\n");
	}	
	
	if ( QueueRemove(myQueue, NULL) == NULL_ERR)
	{
		printf("SUCCESS!\n");	
	}
	else
	{
		printf("FAIL!\n");
	}	
	
	if ( QueueRemove(myQueue, &removedData) == UNDERFLOW_ERR)
	{
		printf("SUCCESS!\n");
	}
	else
	{
		printf("FAIL!\n");
	}	
	
	
	if ( QueueInsert(NULL, 1) == NULL_ERR)
	{
		printf("SUCCESS!\n");
	}
	else
	{
		printf("FAIL!\n");
	}
	
	if ( QueueInsert(myQueue, 1) == SUCCESS)
	{
		printf("SUCCESS!\n");
	}
	else
	{
		printf("FAIL!\n");
	}

	QueueInsert(myQueue, 2);
	QueueInsert(myQueue, 3);
	QueueInsert(myQueue, 4);
	QueueRemove(myQueue, &removedData);
	
	if ( removedData == 1)
	{
		printf("SUCCESS!\n");
	}
	else
	{
		printf("FAIL!\n");
	}

	QueueRemove(myQueue, &removedData);

	if ( removedData == 2)
	{
		printf("SUCCESS!\n");
	}
	else
	{
		printf("FAIL!\n");
	}

	if ( IsQueueEmpty(myQueue) == 0)
	{
		printf("SUCCESS!\n");
	}
	else
	{
		printf("FAIL!\n");
	}

	QueueDestroy(myQueue);
	
	if ( IsQueueEmpty(myQueue) == 1)
	{
		printf("SUCCESS!\n");
	}
	else
	{
		printf("FAIL!\n");
	}

	if ( QueueRemove(myQueue, &removedData) == NULL_ERR)
	{
		printf("SUCCESS!\n");
	}
	else
	{
		printf("FAIL!\n");
	}	
		
	if ( QueueInsert(myQueue, 1) == NULL_ERR)
	{
		printf("SUCCESS!\n");
	}
	else
	{
		printf("FAIL!\n");
	}
	
	return 1;
}
