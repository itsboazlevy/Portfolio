#include <stdio.h>
#include <stdlib.h>

struct daError
{
	int nullError;
	int reallocFail;
	int underFlow;
	int overFlow;
	int wrongInput;
	int success;
};

struct da
{
	int *ptr;
	int size;
	int numOfElements;
	int incrementBlockSize;
	struct daError *myErrorStruct;
};

int checkParameters(struct da *myStruct)
{
	if (myStruct == NULL || myStruct->ptr == NULL || myStruct->myErrorStruct == NULL)
	{
		return myStruct->myErrorStruct->nullError;
	}
	if (myStruct->size < myStruct->numOfElements)
	{
		return myStruct->myErrorStruct->overFlow;
	}
	if (myStruct->size < 0 || myStruct->numOfElements < 0 || myStruct->incrementBlockSize < 0)
	{
		return myStruct->myErrorStruct->wrongInput;
	}
	if (myStruct->numOfElements <= 0)
	{
		return myStruct->myErrorStruct->underFlow;
	}
}

struct da* create(int size, int incrementBlockSize)
{
	struct da *myStruct;
	if (size <= 0 && incrementBlockSize <= 0)
	{
		return NULL;
	}
	myStruct = (struct da*)malloc(sizeof(struct da));
	myStruct->ptr = (int*)malloc(sizeof(int));
	myStruct->myErrorStruct = (struct daError*)malloc(sizeof(struct daError));
	myStruct->size = size;
	myStruct->numOfElements = 0;
	myStruct->incrementBlockSize = incrementBlockSize;
	myStruct->myErrorStruct->nullError = -1;
	myStruct->myErrorStruct->reallocFail = -2;
	myStruct->myErrorStruct->underFlow = -3;
	myStruct->myErrorStruct->overFlow = -4;
	myStruct->myErrorStruct->wrongInput = -5;
	myStruct->myErrorStruct->success = 1;
	return myStruct;
}

int insert1 (struct da *myStruct, int data)
{	
	checkParameters(myStruct);
	int* localPtr;	
	if (myStruct->numOfElements == myStruct->size)
	{
		localPtr = realloc(myStruct->ptr,myStruct->incrementBlockSize);
		if (localPtr == NULL)
		{
			return myStruct->myErrorStruct->nullError;	
		}
		myStruct->ptr = localPtr;
		myStruct->size += myStruct->incrementBlockSize;	
	}
	*((myStruct->ptr) + (myStruct->numOfElements)) = data;
	(myStruct->numOfElements)++;
	return myStruct->myErrorStruct->success;		
}

int remove1 (struct da *myStruct, int *data)
{	
	checkParameters(myStruct);
	*data = *(myStruct->ptr + myStruct->numOfElements -1);
	(myStruct->numOfElements)--;
	return myStruct->myErrorStruct->success;	
}


void destroy (struct da *myStruct)
{
	if ((myStruct->ptr) != NULL)
	{
	free(myStruct->ptr);
	}
}

