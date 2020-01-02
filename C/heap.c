#include "heap.h"
#include <stdlib.h>
#define CREATION_CHECK_NUM 123456789
#define LEFT_SON_INDEX(n) n*2+1
#define RIGHT_SON_INDEX(n) n*2+2
#define FATHER_INDEX(n) (n-1)/2

struct Heap
{
	Vector* m_vec;
	size_t m_heapSize;
	size_t m_numForCreationCheck;
};

/* Bubble down algorithem */
static void Heapify(Heap* _heap, int _index)
{
	int item;
	int leftSon;
	int rightSon;
	int rightSonStatus;
	int leftSonStatus;
	int maxIndex;
	int maxItem;
	
	VectorGet(_heap->m_vec, _index, &item);
	leftSonStatus = VectorGet(_heap->m_vec, LEFT_SON_INDEX(_index), &leftSon);
	rightSonStatus = VectorGet(_heap->m_vec, RIGHT_SON_INDEX(_index), &rightSon);
	if (leftSonStatus == ERR_WRONG_INDEX && rightSonStatus == ERR_WRONG_INDEX)
	{
		return;
	}
	else if ( rightSonStatus == ERR_OK && rightSon >= leftSon  && rightSon > item)
	{
		maxIndex =  RIGHT_SON_INDEX(_index);
		maxItem = rightSon;
	}
	else if ( (rightSonStatus == ERR_WRONG_INDEX || leftSon >= rightSon ) && leftSon > item)
	{
		maxIndex =  LEFT_SON_INDEX(_index);
		maxItem = leftSon;
	}
	else
	{
		return;
	}
	VectorSet(_heap->m_vec, _index, maxItem);
	VectorSet(_heap->m_vec, maxIndex, item);
	Heapify(_heap,maxIndex);
	return;
}

Heap* HeapBuild(Vector* _vec)
{
	int numOfItems;
	int count;
	Heap* myHeap;
	if (_vec == NULL)
	{
		return NULL;
	}
	myHeap = (Heap*)malloc(sizeof(Heap));
	if (myHeap == NULL)
	{
		return NULL;
	}
	myHeap->m_vec = _vec; 
	VectorGetItemsNum(_vec,&numOfItems);
	myHeap->m_heapSize =(size_t)numOfItems;
	myHeap->m_numForCreationCheck = CREATION_CHECK_NUM;
	for(count = numOfItems/2 - 1; count >= 0; count--)
	{
		Heapify(myHeap, count);
	}
	return myHeap;
}
/* Bubble up algorithem */
ADTErr HeapInsert(Heap* _heap, int _data)
{
	int status;
	int tempFatherItem;
	int insertedItemIndex;
	if (_heap == NULL || _heap->m_numForCreationCheck != CREATION_CHECK_NUM)
	{
		return ERR_NULL;
	}
	status = VectorAdd (_heap->m_vec, _data);
	if ( status != ERR_OK )
	{
		return status;
	}
	insertedItemIndex = _heap->m_heapSize;
	_heap->m_heapSize++;
	while (1)
	{
		VectorGet(_heap->m_vec, FATHER_INDEX(insertedItemIndex), &tempFatherItem); 
		if ( tempFatherItem < _data)
		{
			VectorSet(_heap->m_vec, insertedItemIndex, tempFatherItem);
			VectorSet(_heap->m_vec, FATHER_INDEX(insertedItemIndex), _data);
		} 
		if ( FATHER_INDEX(insertedItemIndex) == 0)
		{
			break;
		}
		insertedItemIndex = FATHER_INDEX(insertedItemIndex);
	}
	return ERR_OK;
}

void HeapDestroy(Heap* _heap)
{
	if (_heap == NULL || _heap->m_numForCreationCheck != CREATION_CHECK_NUM)
	{
		return;
	}
	_heap->m_numForCreationCheck = 0;
	free(_heap);
	return;
}
ADTErr HeapMax (Heap* _heap, int* _data)
{
	if (_heap == NULL ||_data == NULL || _heap->m_numForCreationCheck != CREATION_CHECK_NUM)
	{
		return ERR_NULL;
	}
	VectorGet(_heap->m_vec, 0, _data);
	return ERR_OK;
}

ADTErr HeapExtractMax (Heap* _heap, int* _data)
{
	int maxItem;
	int lastItem;
	int status;
	if (_heap == NULL ||_data == NULL || _heap->m_numForCreationCheck != CREATION_CHECK_NUM)
	{
		return ERR_NULL;
	}
	if (_heap->m_heapSize == 0)
	{
		return ERR_UNDERFLOW;
	}
	status = VectorGet(_heap->m_vec, _heap->m_heapSize -1, &lastItem);
	if ( status != ERR_OK)
	{
		return status;
	}
	status = VectorGet(_heap->m_vec, 0 , &maxItem);
	if ( status != ERR_OK)
	{
		return status;
	}
	status = VectorSet(_heap->m_vec, 0 , lastItem);
	if ( status != ERR_OK)
	{
		return status;
	}
	status = VectorDelete (_heap->m_vec, &lastItem);
	if ( status != ERR_OK)
	{
		return status;
	}

	_heap->m_heapSize--;
	*_data = maxItem;
	if (_heap->m_heapSize != 0)
	{
	Heapify(_heap,0);
	}
	return ERR_OK;
}

void HeapPrint (Heap* _heap)
{
	if (_heap == NULL || _heap->m_numForCreationCheck != CREATION_CHECK_NUM)
	{
		printf("Error, make sure you created a heap before you print it\n");
		return;
	}
	VectorPrint(_heap->m_vec);
	return;
}

int HeapItemsNum (Heap* _heap)
{
	if (_heap == NULL || _heap->m_numForCreationCheck != CREATION_CHECK_NUM)
	{
		return ERR_NULL;
	}
	return _heap->m_heapSize;
}
