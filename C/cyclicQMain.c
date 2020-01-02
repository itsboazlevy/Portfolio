#include "cyclicQ.h"

int main()
{
	Queue* ptr = NULL;
	size_t size = 1;
	int item;
	int status;
	int i = 0;
	/* #tests = 26 */
	int testCount = 0;
	
	/*Create and Destroy Tests*/
	ptr = QueueCreate(0);
	if( ptr == NULL)
	{
		testCount++;
	}
	ptr = QueueCreate(size);
	if ( ptr != NULL)
	{
		testCount++;
	}
	QueueDestroy (ptr);
	QueueDestroy (ptr);
	
	/*Insert and Remove Tests*/
	status = QueueInsert (ptr, i);
	if(status == ERR_NULL)
	{
		testCount++;
	}
	status = QueueInsert (NULL, i);
	if(status == ERR_NULL)
	{
		testCount++;
	}
	ptr = QueueCreate(5);
	for(i=1; i<=5;i++)
	{
		status = QueueInsert (ptr, i);
		if(status == SUCCESS)
		{
			testCount++;
		}
	}
	status = QueueInsert (ptr, i);
	if(status == ERR_OVERFLOW)
	{
		testCount++;
	}
	status = QueueRemove (NULL, &item);
	if(status == ERR_NULL)
		{
			testCount++;
		}
	status = QueueRemove (ptr, NULL);
	if(status == ERR_NULL)
		{
			testCount++;
		}
	for(i=1; i<=5;i++)
	{
		status = QueueRemove (ptr, &item);
		if(status == SUCCESS)
		{
			testCount++;
		}
		if(item == i)
		{
			testCount++;
		}
	}
	status = QueueRemove (ptr, &item);
	if(status == ERR_UNDERFLOW)
	{
		testCount++;
	}
	
	/*QueueIsEmpty Tests*/
	status = QueueIsEmpty (ptr);
	if(status == SUCCESS)
		{
			testCount++;
		}
	status = QueueIsEmpty (NULL);
	if(status == ERR_NULL)
		{
			testCount++;
		}
	status = QueueInsert (ptr, i);
	status = QueueIsEmpty (ptr);
	if(status == FAIL)
		{
			testCount++;
		}
	
	/*Print Tests*/
	ptr = QueueCreate(5);
	for(i=1; i<=5;i++)
	{
		QueueInsert (ptr, i);
	}
	for(i=1; i<=2;i++)
	{
		QueueRemove (ptr, &item);
	}
	QueueInsert (ptr, 6);
	QueuePrint (ptr);
	printf("Items should be 3 4 5 6 by order\n");

	if (testCount == 26)
	{
		printf("\nALL TESTS SUCCESSFUL\n");
	}
	else
	{
		printf("\nNOT ALL TESTS SUCCESSFULL\n");
	}
	return 1;
}
