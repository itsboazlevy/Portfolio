#include <stdlib.h>
#include "myMalloc.h"
#define IS_INT_ALLIGN(n) (n)%4==0
#define LOCK(n) 
void* memInit (int _buffSize)
{
	int count = 0;
	char* buff = malloc(_buffSize);
	if (buff == NULL)
	{
		return NULL;
	}
	while (!IS_INT_ALLIGN((size_t)buff+count))
	{
		count++;
	}
	_buffSize -= count;
	buff += count; 
	count = 0;
	while (!IS_INT_ALLIGN((size_t)buff+_buffSize+count))
	{
		count--;
	} 
	_buffSize += count;
	*((unsigned int*)(buff)) = _buffSize;
	
	return (void*)buff;
}
