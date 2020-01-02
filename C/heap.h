/*
heap ADT
author: BL
date: 20.2.19
*/
#include "DV.h"
#ifndef __HEAP_H__
#define __HEAP_H__

typedef struct Heap Heap;

/*
Description: Creates heap ADT from a given vector pointer
Input: Vector pointer 
Output: Heap pointer
Error: NULL if null pointer or allocation error
*/
Heap* HeapBuild(Vector* _vec);

/*
Description: Destroys heap ADT
Input: Heap pointer
Output: None
Error: NULL if NULL pointer
*/
void HeapDestroy(Heap* _heap);

/*
Description: Insert a new node with data to the heap 
Input: Heap pointer, data of pointer
Output: ERR_OK
Error: ERR_NULL if null pointer, ERR_OVERFLOW if max size reached.
*/
ADTErr HeapInsert(Heap* _heap, int _data); /*stops when father is bigger (O(logn)), bubble up */

/*
Description: Removes the max value from the heap into data 
Input: Heap pointer, pointer to data 
Output: ERR_OK
Error: ERR_NULL if null pointer/s
*/
ADTErr HeapExtractMax (Heap* _heap, int* _data);

/*
Description: Gets the max value inside the heap into data 
Input: Heap pointer, pointer to data 
Output: ERR_OK
Error: ERR_NULL if null pointer/s
*/
ADTErr HeapMax (Heap* _heap, int* _data);

/*
Description: Returns the number of items inside the heap 
Input: Heap pointer 
Output: Number of items
Error: ERR_NULL if null pointer
*/
int HeapItemsNum (Heap* _heap);

/*
Description: Prints heap nodes data 
Input: Heap pointer 
Output: Prints heap nodes data 
Error: Prints error message 
*/
void HeapPrint (Heap* _heap);

#endif /* __HEAP_H__ */
