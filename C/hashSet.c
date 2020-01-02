#include <stdio.h>
#include <math.h>
#include "hashSet.h"
#define CREATION_NUM 123456789
#define SIZE_BUFFER(n) (size_t)(n + 0.3*n)
#define FRESH 0
#define OCCUPIED 1
#define FREE 2
#define CAP_LIMIT 0.7

typedef struct StatusTable
{
	unsigned int m_status : 2;			/*keeps status of content in table, using minimum memory*/
}StatusTable;

struct Hash
{
	int* m_data;
	size_t m_hashSize;					/*original size is given by client, updates on demand*/
	size_t m_numOfItems;				/*occupied places in the table*/
	size_t m_maxOfRehashOperations;		/*max num of rehashs for a single insert */
	size_t m_counterOfInsertions;
	size_t m_allRehashOperations;		
	size_t m_creationNum;
	StatusTable* m_myStatusTable;		
};

static int IsPrime(size_t _num)
{
	int count;
	if (_num < 2)
	{
		return 0;
	}
	for(count = 2; count < sqrt(_num); count++)
	{
		if (_num%count == 0)
		{
			return 0;
		}
	}
	return 1;
}

/* checks if insert index is occupied, if it is changes index, updates #rehash and max rehash */
static int Rehash (Hash* _hash, int _data)
{
	int insertIndex = (_data*2)%(_hash->m_hashSize);
	int rehashCounter = 0;
	if (_data < 0)
	{
		insertIndex *= -1;
	}
	while ( _hash->m_myStatusTable[insertIndex].m_status == OCCUPIED)
	{
		insertIndex = (insertIndex+1)%(_hash->m_hashSize);
		rehashCounter++;
	}
	_hash->m_allRehashOperations += rehashCounter;
	if (rehashCounter > _hash->m_maxOfRehashOperations)
	{
		_hash->m_maxOfRehashOperations = rehashCounter;
	}
	return insertIndex;
}
/* checks if capacity has passed capacity limit, if so reallocates memory in the size of the first prime number after the size buffer */
static int Reallocation (Hash* _hash)
{
	size_t newSize;
	if (((float)_hash->m_numOfItems)/_hash->m_hashSize > CAP_LIMIT )
	{
		newSize = SIZE_BUFFER(_hash->m_hashSize);
		while (IsPrime(newSize) != 1)
		{
			newSize++;
		}
		_hash->m_data = (int*)realloc(_hash->m_data,sizeof(int)*newSize);
		if (_hash->m_data == NULL)
		{
			return REALLOC_ERR;
		}
		_hash->m_myStatusTable = (StatusTable*)realloc(_hash->m_myStatusTable,sizeof(StatusTable)*newSize);
		if (_hash->m_myStatusTable == NULL)
		{
			return REALLOC_ERR;
		}
	_hash->m_hashSize = newSize;
	}
	return NO_ERR;
}

Hash* HashCreate (size_t _size)
{
	Hash* myHash;
	if (_size == 0)
	{
		return NULL;
	}
	myHash = (Hash*)calloc(1,sizeof(Hash));
	if (myHash == NULL)
	{
		return NULL;
	}
	myHash->m_data = (int*)malloc(sizeof(int)*_size);
	if (myHash->m_data == NULL)
	{
		free(myHash);
		return NULL;
	}
	myHash-> m_myStatusTable = (StatusTable*)calloc(_size,sizeof(StatusTable));
	if (myHash-> m_myStatusTable == NULL)
	{
		free(myHash->m_data);
		free(myHash);
		return NULL;
	}
	myHash->m_hashSize = _size;
	myHash->m_creationNum = CREATION_NUM;
	return myHash;
}

void HashDestroy (Hash* _hash)
{
	if(_hash == NULL || _hash->m_creationNum != CREATION_NUM)
	{
		return;
	}
	_hash->m_creationNum = 0;
	free(_hash->m_data);
	free(_hash-> m_myStatusTable);
	free(_hash);
}

int HashIsFound (Hash* _hash, int _data)
{
	int count;
	int searchIndex;
	if(_hash == NULL || _hash->m_creationNum != CREATION_NUM)
	{
		return NULL_ERR;
	}
	searchIndex = (_data*2)%(_hash->m_hashSize);
	for (count = 0; count <= _hash->m_maxOfRehashOperations || _hash->m_myStatusTable[searchIndex].m_status != FRESH ; count++)
	{
		if (_hash->m_data[searchIndex] == _data && _hash->m_myStatusTable[searchIndex].m_status == OCCUPIED)
		{
			return 1;
		}
		searchIndex = (searchIndex+1)%_hash->m_hashSize;
	}
	return 0;
}

ADTErr HashInsert (Hash* _hash, int _data)
{
	int insertIndex;
	if (_hash == NULL || _hash->m_creationNum != CREATION_NUM)
	{
		return NULL_ERR;
	}
	if (HashIsFound (_hash,_data) == 1)
	{
		return DATA_OVERLAP_ERR;
	}
	if (Reallocation (_hash) == REALLOC_ERR)
	{
		return REALLOC_ERR;
	}
	insertIndex = Rehash (_hash,_data);
	_hash->m_data[insertIndex] = _data;
	_hash->m_myStatusTable[insertIndex].m_status = OCCUPIED;
	_hash->m_numOfItems++;
	_hash->m_counterOfInsertions++;
	return NO_ERR;
}

ADTErr HashRemove (Hash* _hash, int _data)
{
	int count;
	int searchIndex;
	if(_hash == NULL || _hash->m_creationNum != CREATION_NUM)
	{
		return NULL_ERR;
	}
	searchIndex = (_data*2)%(_hash->m_hashSize);
	for (count = 0; count <= _hash->m_maxOfRehashOperations && _hash->m_myStatusTable[searchIndex].m_status != FRESH ; count++)
	{
		if (_hash->m_data[searchIndex] == _data && _hash->m_myStatusTable[searchIndex].m_status == OCCUPIED)
		{
			_hash->m_myStatusTable[searchIndex].m_status = FREE;
			_hash->m_numOfItems--;
			return NO_ERR;
		}
		searchIndex = (searchIndex+1)%_hash->m_hashSize;
	}	
	return DATA_NOT_FOUND_ERR;
}

size_t HashNumOfItems (Hash* _hash)
{
	if(_hash == NULL || _hash->m_creationNum != CREATION_NUM)
	{
		return NULL_ERR;
	}
	return _hash->m_numOfItems;
}

void HashPrint (Hash* _hash)
{
	int count;
	if(_hash == NULL || _hash->m_creationNum != CREATION_NUM)
	{
		printf("Given hash is not valid");
		return;
	}
	printf("Index     Value         Status\n");
	for(count = 0; count < _hash->m_hashSize; count++)
	{
		printf("%5d%14d%10d\n",count,_hash->m_data[count], _hash->m_myStatusTable[count].m_status ); 
	}
}	

size_t HashCapacitiy (Hash* _hash)
{
	if(_hash == NULL || _hash->m_creationNum != CREATION_NUM)
	{
		return NULL_ERR;
	}
	return _hash->m_hashSize;
}

size_t HashMaxReHash (Hash* _hash)
{
	if(_hash == NULL || _hash->m_creationNum != CREATION_NUM)
	{
		return NULL_ERR;
	}
	return _hash->m_maxOfRehashOperations;
}

double HashAverageRehashes (Hash* _hash)
{
	if(_hash == NULL || _hash->m_creationNum != CREATION_NUM)
	{
		return NULL_ERR;
	}
	if(_hash->m_counterOfInsertions == 0)
	{
		return 0;
	}
	return _hash->m_allRehashOperations/(double)_hash->m_counterOfInsertions;
}

