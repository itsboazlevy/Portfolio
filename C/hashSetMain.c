#include <stdio.h>
#include "hashSet.h"

void CreationCheck()
{
	Hash* myHash = NULL;
	size_t size = 10;
	myHash = HashCreate (size);
	if (myHash != NULL)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashDestroy(myHash);
	return;
}

void DestroyCheck()
{
	Hash* myHash = NULL;
	size_t size = 10;
	myHash = HashCreate (size);
	HashDestroy(myHash);
	HashDestroy(myHash);
	HashDestroy(NULL);
	return;
}

void InsertCheck()
{
	Hash* myHash = NULL;
	size_t size = 10;
	int data = 1;
	myHash = HashCreate (size);
	HashInsert (myHash,data);
	HashDestroy (myHash);
	return;
}
void MaxRehashCheck()
{
	Hash* myHash = NULL;
	size_t size = 10;

	if (HashMaxReHash (myHash) == NULL_ERR)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	myHash = HashCreate (size);
	if (HashMaxReHash (myHash) == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashInsert (myHash,0);
	if (HashMaxReHash (myHash) == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashInsert (myHash,1);
	if (HashMaxReHash (myHash) == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashInsert (myHash,2);
	HashInsert (myHash,3);
	HashInsert (myHash,4);
	if (HashMaxReHash (myHash) == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashInsert (myHash,10);
	if (HashMaxReHash (myHash) == 1)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashInsert (myHash,20);
	if (HashMaxReHash (myHash) == 3)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

}
void NumOfItemsCheck()
{
	Hash* myHash = NULL;
	size_t size = 10;
	if (HashNumOfItems (myHash) == NULL_ERR)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	myHash = HashCreate (size);
	if (HashNumOfItems (myHash) == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashInsert (myHash,0);
	HashInsert (myHash,1);
	HashInsert (myHash,2);
	HashInsert (myHash,3);
	HashInsert (myHash,4);
	if (HashNumOfItems (myHash) == 5)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashDestroy (myHash);
	return;
}

void SizeModificationCheck()
{
	Hash* myHash = NULL;
	size_t size = 4;
	myHash = HashCreate (size);
	if (HashCapacitiy (myHash) == 4)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashInsert (myHash,0);
	HashInsert (myHash,1);
	HashInsert (myHash,2);
	if (HashCapacitiy (myHash) == 4)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashInsert (myHash,3);
	if (HashCapacitiy (myHash) == 5)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashInsert (myHash,4);
	if (HashCapacitiy (myHash) == 7)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashDestroy (myHash);
	return;
}

void AverageRehashesCheck()
{
	Hash* myHash = NULL;
	size_t size = 10;
	if (HashAverageRehashes (myHash) == NULL_ERR)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	myHash = HashCreate (size);
	if (HashAverageRehashes (myHash) == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashInsert (myHash,0);
	HashInsert (myHash,1);
	HashInsert (myHash,2);
	if (HashAverageRehashes (myHash) == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashInsert (myHash,10);
	if (HashAverageRehashes (myHash) == 1/4.0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashInsert (myHash,20);
	if (HashAverageRehashes (myHash) == 4/5.0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashInsert (myHash,30);
	if (HashAverageRehashes (myHash) == 9/6.0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashDestroy (myHash);
	return;
}

void IsFoundCheck()
{
	Hash* myHash = NULL;
	size_t size = 10;
	if (HashIsFound (myHash,5) == NULL_ERR)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	myHash = HashCreate (size);
	if (HashIsFound (myHash,5) == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashInsert (myHash,5);
	if (HashIsFound (myHash,5) == 1)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	HashDestroy (myHash);
	return;
}

void InsertRemoveCheck()
{
	Hash* myHash = NULL;
	size_t size = 10;
	if (HashInsert (myHash,5) == NULL_ERR)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if (HashRemove (myHash,5) == NULL_ERR)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}		
	myHash = HashCreate (size);
	if (HashRemove (myHash,5) == DATA_NOT_FOUND_ERR)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}	
	if (HashInsert (myHash,5) == NO_ERR)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if (HashRemove (myHash,5) == NO_ERR)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}	

	HashDestroy (myHash);
	return;
}

int main()
{	
	CreationCheck();
	
	DestroyCheck();
	
	NumOfItemsCheck();
	
	SizeModificationCheck();
	
	MaxRehashCheck();
	
	InsertCheck();
	
	AverageRehashesCheck();
	
	IsFoundCheck();
	
	InsertRemoveCheck();
	
	return 1;
}
