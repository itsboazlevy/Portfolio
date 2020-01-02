#include "stack.h"

int main()
{
	Stack* userPtr = NULL;
	size_t size = 2;
	size_t blockSize = 2;
	int item = 0;
	int status;
	int itemGot;
	char userCommand;

	printf("\n\nInteractive Test Mode:\n\n");
	printf("List of commands:\n");
	printf("Create Stack - c\n");
	printf("Push - a\n");
	printf("Destroy Stack - d\n");
	printf("Print Stack  - p\n");
	printf("Pop - r\n");
	printf("Top - t\n");
	printf("Number of Items - n\n");
	printf("Quit - q\n\n");

	while(1)
	{
		userCommand = getchar();
		if (userCommand == 'c')
		{
			userPtr= StackCreate (size,blockSize);
			printf("\n Given Pointer Address: %p\n",(void*)userPtr);	
		}
		if (userCommand == 'a')
		{
			status = StackPush (userPtr,item);
			printf("\n Status: %d\n",status);	
		}
		if (userCommand == 'd')
		{
			StackDestroy (userPtr);
			printf("\n Pointer Address After Destroy: %p\n",(void*)userPtr);	
		}
		if (userCommand == 'p')
		{
			StackPrint(userPtr);
		}
		if (userCommand == 'r')
		{
			status = StackPop (userPtr, &itemGot);
			printf("\n Status: %d\n",status);
		}
		if (userCommand == 't')
		{
			status =  StackTop (userPtr, &itemGot);
			printf("\n Status: %d\n",status);
		}
		if (userCommand == 'n')
		{
			status =  StackIsEmpty(userPtr);
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

