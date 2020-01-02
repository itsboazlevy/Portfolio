#include <stdio.h>
#include "hashMap.h"

size_t HashInts(const void* _key)
{
	return *((int*)_key);
}

int EqualityIntsKeys(const void* _firstKey, const void* _secondKey)
{
	return (*((int*)_firstKey) == *((int*)_secondKey));
}

int IntKeyValueDestroy (const void* _key, void* _value, void* _context)
{
	if (_key == NULL)
	{
		return 0;
	}
	*((int*)_key) = 0;
	if (_value != NULL)
	{
	*((int*)_value) = 0;
	}
	return 1;
}

void HashMap_CreateTest()
{
	HashMap* myHash;
	myHash = HashMap_Create(0, HashInts, EqualityIntsKeys);
	if ( myHash == NULL)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	myHash = HashMap_Create(100, NULL, EqualityIntsKeys);
	if ( myHash == NULL)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	myHash = HashMap_Create(100, HashInts, NULL);
	if ( myHash == NULL)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	myHash = HashMap_Create(100, HashInts, EqualityIntsKeys);
	if ( myHash != NULL)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashMap_Destroy(&myHash, IntKeyValueDestroy);
}


void HashMap_DestroyTest()
{
	HashMap* myHash = NULL;
	myHash = HashMap_Create(100, HashInts, EqualityIntsKeys);
	HashMap_Destroy(NULL, IntKeyValueDestroy);
	if ( myHash != NULL)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashMap_Destroy(&myHash, IntKeyValueDestroy);
	if ( myHash == NULL)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashMap_Destroy(&myHash, NULL);
	HashMap_Destroy(NULL, IntKeyValueDestroy);
}

void HashMap_SizeTest()
{
	HashMap* myHash;
	int i1 = 1;
	int i10 = 10;
	int i2 = 2;
	int i20 = 20;
	int i3 = 3;
	int i30 = 30;
	myHash = HashMap_Create(10, HashInts, EqualityIntsKeys);
	if (HashMap_Size(myHash) == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashMap_Insert(myHash, (void*)&i1, (void*)&i10);
	if (HashMap_Size(myHash) == 1)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashMap_Insert(myHash, (void*)&i2, (void*)&i20);
	if (HashMap_Size(myHash) == 2)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashMap_Insert(myHash, (void*)&i3, (void*)&i30);
	if (HashMap_Size(myHash) == 3)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashMap_Destroy(&myHash, IntKeyValueDestroy);
}

HashMap_InsertTest()
{
	HashMap* myHash;
	int i1 = 1;
	int i10 = 10;
	int i2 = 2;
	int i20 = 20;
	int i3 = 3;
	int i30 = 30;
	myHash = HashMap_Create(10, HashInts, EqualityIntsKeys);
	if ( HashMap_Insert(myHash, (void*)&i1, (void*)&i1) == MAP_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( HashMap_Insert(myHash, (void*)&i1, (void*)&i1) == MAP_KEY_DUPLICATE_ERROR)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( HashMap_Insert(myHash, NULL, (void*)&i1) == MAP_KEY_NULL_ERROR)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( HashMap_Insert(NULL, (void*)&i1, (void*)&i1) == MAP_UNINITIALIZED_ERROR)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( HashMap_Insert(myHash, (void*)&i1, NULL) == MAP_KEY_DUPLICATE_ERROR)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( HashMap_Insert(myHash, (void*)&i2, NULL) == MAP_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashMap_Destroy(&myHash, IntKeyValueDestroy);
}
int main()
{
	printf("\nHashMap_CreateTest\n");
	HashMap_CreateTest();
	printf("\nHashMap_DestroyTest\n");
	HashMap_DestroyTest();
	printf("\nHashMap_SizeTest\n");
	HashMap_SizeTest();
	printf("\nHashMap_InsertTest\n");
	HashMap_InsertTest();
	return 1;
}
