#ifndef __DV_H__
#define __DV_H__
#include <stdio.h>

typedef enum
{
		ERR_OK,
	ERR_GENERAL,
	ERR_NOT_INITIALIZED,
	ERR_ALLOCATION_FAILED,
	ERR_REALLOCATION_FAILED,
	ERR_UNDERFLOW,
	ERR_OVERFLOW,
	ERR_WRONG_INDEX,
	ERR_NULL
} ADTErr;

typedef struct Vector Vector;

/*
Description: creates dynamic vector 
Input: initial size and extension block size, both cant be 0 
Output: pointer to dynamic vector structure, NULL if creation failed
*/
Vector* VectorCreate (size_t _initialSize, size_t _extensionBlockSize);

/*
Description: destroys dynamic vector, if destruction is executed without creation - won't preform it
Input: pointer to dynamic vector structure. if null pointer sent wont preform operation
Output: none
*/
void VectorDestroy (Vector* _vector);

/*
Description: adds item to top (LIFO), reallocates extra chunks of memory if needed
Input: pointer to dynamic vector structure and item to insert
Output: ERR_GENERAL for Null pointer or no previous creation, ERR_OVERFLOW if needed and impossible to reallocate a chunk of memory because its 0, ERR_OK if succesful
*/
ADTErr VectorAdd (Vector* _vector, int _item);

/*
Description: deletes item from top (LIFO), reallocates chunks of memory if needed - if more than 2 extra chucks of memory to spare it delets 1
Input: pointer to dynamic vector structure, pointer to item that will get the deleted value.
Output: ERR_GENERAL for Null pointers or no previous creation, ERR_NOT_INITIALIZED if trying to remove item and there are no items,
	ERR_UNDERFLOW if trying to reallocate less memory than initialiy defined, ERR_OK if succesful
*/
ADTErr VectorDelete (Vector* _vector, int* _item);

/*
Description: gets an item by its index
Input: pointer to dynamic vector structure, index, pointer to variable to insert to
Output: ERR_GENERAL for Null pointers or no previous creation, ERR_WRONG_INDEX if index doesnt exist in list, ERR_OK if succesful
*/
ADTErr VectorGet(Vector* _vector, size_t _index, int* _item);

/*
Description: sets an item to an index
Input: pointer to dynamic vector structure, index, item to insert
Output: ERR_GENERAL for Null pointers or no previous creation, ERR_WRONG_INDEX if index doesnt exist in list, ERR_OK if succesful
*/
ADTErr VectorSet(Vector* _vector, size_t _index, int _item);

/*
Description: gets number of items
Input: pointer to dynamic vector structure, pointer to variable to insert to
Output: ERR_GENERAL for Null pointers or no previous creation, ERR_OK if succesful
*/
ADTErr VectorGetItemsNum(Vector* _vector, int* _numOfItems);

/*
Description: prints vector struct details and indexed list of items in it, if no vector exists prints alternative message.
Input: pointer to dynamic vector structure
Output: none
*/
void VectorPrint(Vector* _vector);

#endif /*__DV_H__*/
