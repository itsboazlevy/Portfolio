#include <stdio.h>
#include <stdlib.h>
#include "genVector.h"
struct Vector
{
	void** m_items;
	size_t m_originalSize;  
	size_t m_size;      
	size_t m_nItems;
	size_t m_blockSize;
};

Vector* Vector_Create(size_t _initialCapacity, size_t _blockSize)
{
	Vector* vector;
	if (_initialCapacity == 0 && _blockSize == 0)
	{
		return NULL;
	}
	vector = (Vector*)malloc(sizeof(Vector));
	if (vector == NULL)
	{
		return NULL;
	}
	vector->m_items = (void**)malloc(sizeof(void*)*_initialCapacity);
	if (vector->m_items == NULL)
	{
		free(vector);
		return NULL;
	}
	vector->m_originalSize =_initialCapacity;	
	vector->m_blockSize = _blockSize;
	vector->m_size = _initialCapacity;
	vector->m_nItems = 0;
	return vector;
}

void Vector_Destroy(Vector** _vector, void (*_elementDestroy)(void* _item))
{
	int count;
	if (_vector != NULL && *_vector != NULL) 
	{
		if (_elementDestroy == NULL)
		{
			for(count = 0; count < (*_vector)->m_nItems; count++)
			{
				_elementDestroy((*_vector)->m_items[count]);
			}
		}
		(*_vector)->m_nItems = 0;
		free((*_vector)->m_items);
		free(*_vector);
		*_vector = NULL;
	}
	return;
}

Vector_Result Vector_Append(Vector* _vector, void* _item)
{
	if (_vector == NULL)
	{
		return VECTOR_NULL_ERR;
	}
	if ( _vector->m_nItems == _vector->m_size  )
	{
		if ( _vector->m_blockSize == 0)
		{
			return VECTOR_OVERFLOW; 
		}
		_vector->m_size += _vector->m_blockSize;
		_vector->m_items = (void**)realloc(_vector->m_items,sizeof(void*)*_vector->m_size);
		if (_vector->m_items == NULL)
		{
			return VECTOR_REALLOCATION_ERROR;
		}
	}
	*(_vector->m_items + _vector->m_nItems) = _item;
	_vector->m_nItems++;
	return VECTOR_SUCCESS;
}

Vector_Result Vector_Remove(Vector* _vector, void** _pValue)
{
	if (_vector == NULL || _pValue == NULL)
	{
		return VECTOR_NULL_ERR;
	}
	if (_vector->m_nItems == 0)
	{
		return VECTOR_UNDERFLOW;
	}
	*_pValue = *(_vector->m_items+ _vector->m_nItems -1);
	if(_vector->m_nItems + (_vector->m_blockSize *2) <  _vector->m_size)
	{
		if (_vector->m_originalSize == _vector->m_size )
		{
			return VECTOR_UNDERFLOW;
		}
		_vector->m_size -= _vector->m_blockSize;
		_vector->m_items = (void**)realloc(_vector->m_items,sizeof(void*)*_vector->m_size);
		if (_vector->m_items == NULL)
		{
			return VECTOR_REALLOCATION_ERROR;
		}
	}
	_vector->m_nItems--;
	return VECTOR_SUCCESS;
}

Vector_Result Vector_Get(const Vector* _vector, size_t _index, void** _pValue)
{
	if (_vector == NULL || _pValue == NULL)
	{
		return VECTOR_NULL_ERR;
	}
	if (_index < 0 || _index >= _vector->m_nItems)
	{
		return VECTOR_INDEX_OUT_OF_BOUNDS_ERROR;
	}
	*_pValue = _vector->m_items[_index];
	return VECTOR_SUCCESS;
}

Vector_Result Vector_Set(Vector* _vector, size_t _index, void*  _value)
{
	if (_vector == NULL)
	{
		return VECTOR_NULL_ERR;
	}
	if (_index < 0 || _index >= _vector->m_nItems)
	{
		return VECTOR_INDEX_OUT_OF_BOUNDS_ERROR;
	}
	_vector->m_items[_index] = _value;
	return VECTOR_SUCCESS;
}

size_t Vector_Size(const Vector* _vector)
{
	if (_vector == NULL)
	{
		return 0;
	}
	return _vector->m_nItems;
}

size_t Vector_Capacity(const Vector* _vector)
{
	if (_vector == NULL)
	{
		return 0;
	}
	return _vector->m_size;
}

size_t Vector_ForEach(const Vector* _vector, int *_vectorElementAction (void* _element, size_t _index, void* _context), void* _context)
{
	size_t count;
	void* someVoidPointer = NULL;
	if (_vector == NULL || _vectorElementAction == NULL || _context == NULL)
	{
		return 0;
	}
	for (count = 0; count < _vector->m_nItems; count++)
	{
		_vectorElementAction(_vector->m_items[count], 0, someVoidPointer);
	}
	return count;
}
