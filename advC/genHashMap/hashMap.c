#include "hashMap.h"
#include <math.h>

typedef struct Pair Pair;
typedef struct PC PC;

struct Pair
{
	const void* m_key;
	const void* m_value;
};

struct HashMap
{
	List** m_data;
	Map_Stats* m_stats;
	HashFunction m_hashFunc;
	EqualityFunction m_keysEqualFunc;
}; 

struct PC
{
	Pair* m_pair;
	void* m_context;
};

static int PairDestroy(const void* _key, void* _value, void* _context)
{
	free((Pair*)(((PC*)_context)->m_pair));
	return 1;
}

static int IsPrime(size_t _num)
{
	int count;
	if (_num < 2)
	{
		return 0;
	}
	for(count = 2; count < _num ; count++)
	{
		if (_num%count == 0)
		{
			return 0;
		}
	}
	return 1;
}

HashMap* HashMap_Create(size_t _capacity, HashFunction _hashFunc, EqualityFunction _keysEqualFunc)
{
	HashMap* myHashMap;
	
	if (_capacity == 0 || _hashFunc == NULL || _keysEqualFunc == NULL)
	{
		return NULL;
	}
	myHashMap = (HashMap*)calloc(1,sizeof(HashMap));
	if (myHashMap == NULL)
	{
		return NULL;
	}
	while (IsPrime(_capacity) == 0)
	{
		_capacity++;
	}
	myHashMap->m_data = (List**)calloc(_capacity,sizeof(List*));
	if (myHashMap->m_data == NULL)
	{
		free(myHashMap);
		return NULL;
	}
	myHashMap->m_stats = (Map_Stats*)calloc(1,sizeof(Map_Stats));
	if (myHashMap->m_stats == NULL)
	{
		free(myHashMap->m_data);
		free(myHashMap);
		return NULL;
	}
	myHashMap->m_stats->buckets = _capacity;
	myHashMap->m_hashFunc = _hashFunc;
	myHashMap->m_keysEqualFunc = _keysEqualFunc;
	return myHashMap;
}

void HashMap_Destroy(HashMap** _map, KeyValueActionFunction _action)
{
	if( _map != NULL && *_map != NULL) 
	{
		if ( _action != NULL)
		{
			 HashMap_ForEach(*_map, _action, NULL);
		}
		HashMap_ForEach(*_map, PairDestroy, NULL);
		free((*_map)->m_stats);
		free((*_map)->m_data);
		free(*_map);
		*_map = NULL;	
	}	
	return;	
}

Map_Result HashMap_Find(const HashMap* _map, const void* _searchKey, void** _pValue)
{
	size_t searchIndex;
	List* searchList;
	ListItr itr;
	ListItr endItr;
	Pair* tempData;
	if (_map == NULL)
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	else if (_searchKey == NULL)
	{
		return MAP_KEY_NULL_ERROR;
	}
	else if ( _pValue == NULL)
	{
		return MAP_PVALUE_NULL_ERROR;
	}
	searchIndex = _map->m_hashFunc(_searchKey) % _map->m_stats->buckets;
	searchList = _map->m_data[searchIndex];
	if ( searchList != NULL)
	{
		itr =  ListItr_Begin(searchList);
		endItr = ListItr_End(searchList);
		while ( itr != endItr )
		{
			tempData = (Pair*)(ListItr_Get(itr));
			if ( _map->m_keysEqualFunc(_searchKey, tempData->m_key))
			{
				*_pValue = tempData->m_value;
				return MAP_SUCCESS;
			}
			itr =  ListItr_Next(itr);
		}
	}
	return MAP_KEY_NOT_FOUND_ERROR;
}

Map_Result HashMap_Remove(HashMap* _map, const void* _searchKey, void** _pKey, void** _pValue)
{
	size_t searchIndex;
	List* searchList;
	ListItr itr;
	ListItr endItr;
	Pair* tempData;
	int findResult;
	/*validity check for removal*/
	if ( _pKey == NULL)
	{
		return MAP_PKEY_NULL_ERROR;
	}
	findResult = HashMap_Find(_map, _searchKey, _pValue);
	if ( findResult != MAP_SUCCESS)
	{
		return findResult;
	}
	/*removal*/
	searchIndex = _map->m_hashFunc(_searchKey) % _map->m_stats->buckets;
	searchList = _map->m_data[searchIndex];
	itr =  ListItr_Begin(searchList);
	endItr = ListItr_End(searchList);
	while ( itr != endItr )
	{
		tempData = (Pair*)(ListItr_Get(itr));
		if ( _map->m_keysEqualFunc(_searchKey, tempData->m_key))
		{
			*_pKey = tempData->m_key;
			ListItr_Remove(itr);
			PairDestroy(tempData->m_key,tempData->m_value, tempData);
			break;

		}
		itr =  ListItr_Next(itr);
	}
	/*status update*/
	if (List_Size( _map->m_data[searchIndex]) == _map->m_stats->maxChainLength -1)
	{
		_map->m_stats->maxChainLength--;
	}
	if (List_Size( _map->m_data[searchIndex]) == 0)
	{
		_map->m_stats->chains--;
	}
	_map->m_stats->pairs--;
	_map->m_stats->averageChainLength = _map->m_stats->pairs / _map->m_stats->chains;
	return MAP_SUCCESS;
}

Map_Result HashMap_Insert(HashMap* _map, const void* _key, const void* _value)
{
	void* temp;
	Pair* newPair;
	size_t insertIndex;
	/*validity check for insertion*/
	if (_map == NULL)
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	if (_key == NULL)
	{
		return MAP_KEY_NULL_ERROR;
	}
	if ( HashMap_Find(_map, _key, &temp) == MAP_SUCCESS)
	{
		return MAP_KEY_DUPLICATE_ERROR;
	}
	/*pair creation*/
	newPair = (Pair*)malloc(sizeof(Pair));
	if (newPair == NULL)
	{
		return MAP_ALLOCATION_ERROR;
	}
	newPair->m_value = _value;
	newPair->m_key = _key;
	/*insertion with stats update*/
	insertIndex = _map->m_hashFunc(_key) % _map->m_stats->buckets;
	if (  _map->m_data[insertIndex] == NULL)
	{
		_map->m_data[insertIndex] = List_Create();
		if ( _map->m_data[insertIndex] == NULL)
		{
			return MAP_ALLOCATION_ERROR;
		}
		_map->m_stats->chains++;
	}
	else
	{
		_map->m_stats->collisions++;
	}
	List_PushTail( _map->m_data[insertIndex], newPair);
	/*just stats update*/
	_map->m_stats->pairs++;
	if ( List_Size( _map->m_data[insertIndex]) > _map->m_stats->maxChainLength)
	{
		_map->m_stats->maxChainLength = List_Size( _map->m_data[insertIndex]);
	}
	_map->m_stats->averageChainLength = _map->m_stats->pairs / _map->m_stats->chains;
	return MAP_SUCCESS;
}


static int IntRehash(const void* _key, void* _value, void* _context)
{
	HashMap_Insert((HashMap*) _context, _key, _value);
	return 1;
}

Map_Result HashMap_Rehash(HashMap *_map, size_t newCapacity)
{
	HashMap* newMap;
	if (_map == NULL || newCapacity < _map->m_stats->buckets)
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	newMap = HashMap_Create(newCapacity,_map->m_hashFunc, _map->m_keysEqualFunc);
	HashMap_ForEach(_map, IntRehash, (void*) newMap);
	*(newMap->m_stats) = *(_map->m_stats);
	HashMap_Destroy(_map, NULL);
	return MAP_SUCCESS;	
}


size_t HashMap_Size(const HashMap* _map)
{
	return _map->m_stats->pairs;
}

size_t HashMap_ForEach(const HashMap* _map, KeyValueActionFunction _action, void* _context)
{
	size_t count;
	size_t flag;
	List* tempList;
	ListItr tempItr;
	ListItr tempEndItr;
	PC* tempPCstruc;
	tempPCstruc->m_context =  _context;
	if (_map == NULL || _action == NULL)
	{
		return MAP_GENERAL_NULL_ERROR;
	}
	for(count = 0; count < _map->m_stats->buckets; count++)
	{
		tempList = _map->m_data[count];
		if (tempList != NULL)
		{
			tempItr = ListItr_Begin(tempList);
			tempEndItr = ListItr_End(tempList);
			flag = 0;
			while( tempItr != tempEndItr)
			{
				tempPCstruc->m_pair = (Pair*) (ListItr_Get(tempItr));
				if ( _action(tempPCstruc->m_pair->m_key,tempPCstruc->m_pair->m_value, (void*)tempPCstruc) == 0)
				{
					flag = 1;
					break;
				}
				tempItr = ListItr_Next(tempItr);
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
	return count;
}

