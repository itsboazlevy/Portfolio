#include <stdio.h>
#include "genVector.h"
#include <stdlib.h>

typedef struct RandStruc RandStruc;
struct RandStruc
{
	int m_randInt;
	char m_randChar;
	float m_randFloat;
};

int PrintElementAction (void* _element, size_t _index, void* _context)
{
	if (_element == NULL || _context == NULL)
	{
		return 0;
	}
	printf("%p\n",_element);
	return 1;
}

void RandStrucDestroy(void* _myRandStruc)
{
	free ((RandStruc*)_myRandStruc);
	return;
}

void CreationDestructionTests()
{
	size_t initialCapacity = 2;
	size_t blockSize = 5;
	RandStruc* myRandStruc;
	Vector* userPtr = NULL;
	myRandStruc = (RandStruc*)malloc(sizeof(RandStruc)*5);
	if ( myRandStruc == NULL)
	{
		return;
	}
	userPtr= Vector_Create (initialCapacity,blockSize);
	if (userPtr !=	NULL)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if(Vector_Create (0,1) && Vector_Create (1,0) && !Vector_Create (0,0))
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	Vector_Destroy(&userPtr,RandStrucDestroy);
	Vector_Destroy(&userPtr,RandStrucDestroy);
	Vector_Destroy(NULL,RandStrucDestroy);
}

void AppendRemoveTests()
{
	int count;
	size_t initialCapacity = 2;
	size_t blockSize = 5;
	void* pValue;
	RandStruc* myRandStruc[3];
	Vector* userPtr;
	for (count = 0; count < 3; count++)
	{
		myRandStruc[count] = (RandStruc*)malloc(sizeof(RandStruc)*5);
		if ( myRandStruc[count] == NULL)
		{
			return;
		}
	}
	userPtr= Vector_Create (initialCapacity,blockSize);
	if (Vector_Append (NULL,myRandStruc[0]) == VECTOR_NULL_ERR)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if (Vector_Append (userPtr,myRandStruc[0]) == VECTOR_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if (Vector_Append (userPtr,myRandStruc[1]) == VECTOR_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if (Vector_Remove (userPtr,&pValue) == VECTOR_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( pValue == myRandStruc[1])
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if (Vector_Remove (userPtr,&pValue) == VECTOR_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( pValue == myRandStruc[0])
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if (Vector_Remove (userPtr,&pValue) == VECTOR_UNDERFLOW)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	Vector_Destroy(&userPtr,RandStrucDestroy);

	return;
}

void AppendWithBlock0Tests()
{
	int count;
	size_t initialCapacity = 1;
	size_t blockSize = 0;
	RandStruc* myRandStruc[3];
	Vector* userPtr;
	for (count = 0; count < 3; count++)
	{
		myRandStruc[count] = (RandStruc*)malloc(sizeof(RandStruc)*5);
		if ( myRandStruc[count] == NULL)
		{
			return;
		}
	}
	userPtr= Vector_Create (initialCapacity,blockSize);
	if (Vector_Append (userPtr,myRandStruc[0]) == VECTOR_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if (Vector_Append (userPtr,myRandStruc[1]) == VECTOR_OVERFLOW)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	Vector_Destroy(&userPtr,RandStrucDestroy);
	return;
}


int main()
{
	CreationDestructionTests();
	
	AppendRemoveTests();
	
	AppendWithBlock0Tests();


	return 1;
}
