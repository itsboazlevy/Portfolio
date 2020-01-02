#include <stdlib.h>
#include <stdio.h>
#define nullError -1
#define reallocFail -2

int *create (int size, int *status)
{
	int *localPtr = malloc(size);
	if (localPtr == NULL)
	{
		*status = nullError;
	}
	return localPtr;
}

void insert1 (int **ptr, int data, int *numOfElements, int *size, int incrementBlockSize, int *status)
{
	int *localPtr;
	if (*numOfElements == *size)
	{
		localPtr = realloc(*ptr,incrementBlockSize);
		if (localPtr == NULL)
		{
			*status = reallocFail;	
		}
		*ptr = localPtr;
		*size += incrementBlockSize;	
	}
	*(*ptr + *numOfElements) = data;
	(*numOfElements)++;		
}

int remove1 (int *ptr, int *data, int *numOfElements)
{
	*data = *(ptr + (*numOfElements)-1);
	(*numOfElements)--;
	return 1;	
}

void destroy (int *ptr)
{
	free(ptr);	
}

