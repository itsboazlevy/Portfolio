#include <stdio.h>
#include <stdlib.h>
#include "DV.h"
struct Vector
{
	int* m_items;
	size_t m_originalSize;  
	size_t m_size;      
	size_t m_nItems;
	size_t m_blockSize;
	int m_toBeOrNot;
};

int NullCheck (Vector* _vector)
{
	if (_vector != NULL && _vector->m_items != NULL && _vector->m_toBeOrNot == 1234567890)
	{
		return ERR_OK;
	}
	return ERR_GENERAL;
}
int NullCheckWithItem (Vector* _vector, int* _item)
{
	if (_vector != NULL && _vector->m_items != NULL && _vector->m_toBeOrNot == 1234567890 && _item != NULL)
	{
		return ERR_OK;
	}
	return ERR_GENERAL;
}


Vector* VectorCreate (size_t _initialSize, size_t _extensionBlockSize)
{
	Vector* vector;
	if (_initialSize == 0 && _extensionBlockSize == 0)
	{
		return NULL;
	}
	vector = (Vector*)malloc(sizeof(Vector));
	vector->m_originalSize =_initialSize;	
	vector->m_items = (int*)malloc(sizeof(int)*_initialSize);
	vector->m_blockSize = _extensionBlockSize;
	vector->m_size = _initialSize;
	vector->m_toBeOrNot = 1234567890;
	vector->m_nItems = 0;	
	return vector;
}

void VectorDestroy (Vector* _vector)
{
	if (NullCheck(_vector) == ERR_OK)
	{
		_vector->m_toBeOrNot = 0;
		_vector->m_nItems = 0;
		free(_vector->m_items);
		free(_vector);
	}
}

ADTErr VectorAdd (Vector* _vector, int _item)
{
	if (NullCheck(_vector) != ERR_OK)
	{
		return ERR_GENERAL;	
	}
	if ( _vector->m_nItems == _vector->m_size  )
	{
		if ( _vector->m_blockSize == 0)
		{
			return ERR_OVERFLOW; 
		}
		_vector->m_size += _vector->m_blockSize;
		_vector->m_items = (int*)realloc(_vector->m_items,sizeof(int)*(_vector->m_size));
	}
	*(_vector->m_items+ _vector->m_nItems) = _item;
	_vector->m_nItems++;
	return ERR_OK;
}

ADTErr VectorDelete (Vector* _vector, int* _item)
{
	if (NullCheckWithItem(_vector,_item) != ERR_OK)
	{
		return ERR_GENERAL;	
	}
	if (_vector->m_nItems == 0)
	{
		return ERR_NOT_INITIALIZED;
	}
	
	*_item = *(_vector->m_items+ _vector->m_nItems -1);
	if(	_vector->m_nItems + (_vector->m_blockSize *2) <  _vector->m_size)
	{
		if (_vector->m_originalSize == _vector->m_size )
		{
			return ERR_UNDERFLOW;
		}
		_vector->m_size -= _vector->m_blockSize;
		_vector->m_items = (int*)realloc(_vector->m_items,sizeof(int)*(_vector->m_size));
	}
	_vector->m_nItems--;
	return ERR_OK;
}

ADTErr VectorGet(Vector* _vector, size_t _index, int* _item)
{
	if (NullCheckWithItem(_vector,_item) != ERR_OK)
	{
		return ERR_GENERAL;	
	}
	if (_index < 0 || _index >= _vector->m_nItems)
	{
		return ERR_WRONG_INDEX;
	}
	*_item = *(_vector->m_items + _index);
	return ERR_OK;
}

ADTErr VectorSet(Vector* _vector, size_t _index, int _item)
{
	if (NullCheck(_vector) != ERR_OK)
	{
		return ERR_GENERAL;	
	}
	if (_index < 0 || _index >= _vector->m_nItems)
	{
		return ERR_WRONG_INDEX;
	}
	*(_vector->m_items + _index) = _item;
	return ERR_OK;
}
ADTErr VectorGetItemsNum(Vector* _vector, int* _numOfItems)
{
	if (NullCheckWithItem(_vector, _numOfItems) != ERR_OK)
	{
		return ERR_GENERAL;	
	}
	* _numOfItems = _vector->m_nItems;
	return ERR_OK;
}

void VectorPrint(Vector* _vector)
{
	int i;
	if (NullCheck(_vector) != ERR_OK)
	{
		printf("Try Creating your ADT before you print it !\n");
		return;	
	}
	for (i=0;i < _vector->m_nItems;i++)
	{
			printf("item[%d] =  %d \n",i,*(_vector->m_items+i));
	}
}
