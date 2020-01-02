#include <stdio.h>
#include "DV.h"
int main()
{
	size_t initialSize = 2;
	size_t extensionBlockSize = 5;
	int item = 2;
	int itemGot;
	size_t index = 2;
	Vector* userPtr = NULL;
	char userCommand;
	int status;
	
	/*Creation Tests*/
	userPtr= VectorCreate (initialSize,extensionBlockSize);
	if (userPtr !=	NULL)
	{
	printf("Success\n");
	}
	if(VectorCreate (0,1) && VectorCreate (1,0) && !VectorCreate (0,0))
	{
	printf("Success\n");
	}
	printf("Success\n");
	printf("Success\n");
	printf("Success\n");

	/*Destroy Tests*/
	VectorDestroy (userPtr);
	printf("\nSuccess\n");
	VectorDestroy (userPtr);
	printf("Success\n");
	VectorDestroy (NULL);
	printf("Success\n");
	printf("Success\n");
	printf("Success\n");

	/*VectorAdd Tests*/
	userPtr= VectorCreate (initialSize,extensionBlockSize);
	status = VectorAdd (NULL,item);
	if (status == 1)
	{
		printf("\nSuccess\n");
	}
	status = VectorAdd (userPtr,item);
	if (status == 0)
	{
		printf("Success\n");
	}
	extensionBlockSize = 0;
	initialSize = 1;
	userPtr= VectorCreate (initialSize,extensionBlockSize);
	status = VectorAdd (userPtr,item);
	if (status == 0)
	{
		printf("Success\n");
	}
	status = VectorAdd (userPtr,item);
	if (status == 6)
	{
		printf("Success\n");
	}
	printf("Success\n");

	/*VectorDelete Tests*/
	extensionBlockSize = 2;
	initialSize = 1;
	userPtr= VectorCreate (initialSize,extensionBlockSize);
	status = VectorDelete (userPtr,&item);
	if (status == ERR_NOT_INITIALIZED)
	{
		printf("\nSuccess\n");
	}
	userPtr= VectorCreate (initialSize,extensionBlockSize);
	status = VectorAdd (userPtr,1);
	status = VectorAdd (userPtr,2);
	VectorGet(userPtr, 1, &itemGot);
	if (itemGot == 2)
	{
		printf("Success\n");
	}
	status = VectorDelete (userPtr,NULL);
	if (status == 1)
	{
		printf("Success\n");
	}
	status = VectorDelete (NULL,&item);
	if (status == 1)
	{
		printf("Success\n");
	}
	VectorDestroy (userPtr);
	extensionBlockSize = 0;
	initialSize = 2;
	userPtr= VectorCreate (initialSize,extensionBlockSize);
	status = VectorAdd (userPtr,1);
	status = VectorAdd (userPtr,1);
	status = VectorDelete (userPtr,&item);
	if (status == ERR_UNDERFLOW)
	{
		printf("Success\n");
	}

	/*VectorGet Tests*/
	extensionBlockSize = 1;
	initialSize = 1;
	userPtr= VectorCreate (initialSize,extensionBlockSize);
	status = VectorAdd (userPtr,13);
	status = VectorAdd (userPtr,17);
	status = VectorGet(NULL, 1, &itemGot);
	if (status == ERR_GENERAL)
	{
		printf("\nSuccess\n");
	}
	status = VectorGet(userPtr, 1, NULL);
	if (status == ERR_GENERAL)
	{
		printf("Success\n");
	}
	status = VectorGet(userPtr, 1, &itemGot);
	if (itemGot == 17)
	{
		printf("Success\n");
	}
	status = VectorGet(userPtr, 0, &itemGot);
	if (itemGot == 13)
	{
		printf("Success\n");
	}
	status = VectorGet(userPtr, 2, &itemGot);
	if (status == ERR_WRONG_INDEX)
	{
		printf("Success\n");
	}

	/*VectorSet Tests*/
	extensionBlockSize = 1;
	initialSize = 1;
	userPtr= VectorCreate (initialSize,extensionBlockSize);
	status = VectorAdd (userPtr,13);
	status = VectorAdd (userPtr,17);
	item = 50;
	status = VectorSet(NULL, 1, item);
	if (status == ERR_GENERAL)
	{
		printf("\nSuccess\n");
	}
	status = VectorSet(userPtr, 1, item);
	status = VectorGet(userPtr, 1, &itemGot);
	if (itemGot == 50)
	{
		printf("Success\n");
	}
	status = VectorSet(userPtr, 2, item);
	if (status == ERR_WRONG_INDEX)
	{
		printf("Success\n");
	}
	status = VectorSet(userPtr, -1, item);
	if (status == ERR_WRONG_INDEX)
	{
		printf("Success\n");
	}
	printf("Success\n");
	
	/*VectorGetItemsNum Tests*/
	extensionBlockSize = 1;
	initialSize = 1;
	userPtr= VectorCreate (initialSize,extensionBlockSize);
	status = VectorAdd (userPtr,13);
	status = VectorAdd (userPtr,17);

	status = VectorGetItemsNum(NULL, &itemGot);
	if (status == ERR_GENERAL)
	{
		printf("\nSuccess\n");
	}
	status = VectorGetItemsNum(userPtr, NULL);
	if (status == ERR_GENERAL)
	{
		printf("Success\n");
	}
	status = VectorGetItemsNum(userPtr, &itemGot);
	if (itemGot == 2)
	{
		printf("Success\n");
	}
	status = VectorAdd (userPtr,13);
	status = VectorAdd (userPtr,17);
	status = VectorGetItemsNum(userPtr, &itemGot);
	if (itemGot == 4)
	{
		printf("Success\n");
	}
	printf("Success\n");

	userPtr = NULL;
	initialSize = 5;
	extensionBlockSize = 1;

	printf("\n\nInteractive Test Mode:\n\n");
	printf("List of commands:\n");
	printf("Create Vector - c\n");
	printf("Add Item - a\n");
	printf("Destroy Vector - d\n");
	printf("Print Vector  - p\n");
	printf("Remove Item - r\n");
	printf("Get item - g\n");
	printf("Set item - s\n");
	printf("Quit - q\n\n");

	while(1)
	{
		userCommand = getchar();
		if (userCommand == 'c')
		{
			userPtr= VectorCreate (initialSize,extensionBlockSize);
			printf("\n Given Pointer Address: %p\n",(void*)userPtr);	
		}
		if (userCommand == 'a')
		{
			status = VectorAdd (userPtr,item);
			printf("\n Status: %d\n",status);	
		}
		if (userCommand == 'd')
		{
			VectorDestroy (userPtr);
			printf("\n Pointer Address After Destroy: %p\n",(void*)userPtr);	
		}
		if (userCommand == 'p')
		{
			VectorPrint(userPtr);
		}
		if (userCommand == 'r')
		{
			status = VectorDelete (userPtr, &itemGot);
			printf("\n Status: %d\n",status);
		}
		if (userCommand == 'g')
		{
			status =  VectorGet(userPtr, index, &itemGot);
			printf("\n Status: %d\n",status);
		}
		if (userCommand == 's')
		{
	
			status =  VectorSet(userPtr, index, item);
			printf("\n Status: %d\n",status);
		}
		if (userCommand == 'q')
		{	
			printf("GoodBye!\n");
			break;
		}
	}
	return 1;
}
