#ifndef __stack_h__
#define __stack_h__
#include "DV.h"


typedef struct Stack Stack;

/*
Description: creates stack
Input: initial size and extension block size, both cant be 0 
Output: pointer to stack structure, NULL if creation failed
*/
Stack* StackCreate (size_t _size, size_t _blocksize);

/*
Description: destroys stack, if destruction is executed without creation - won't preform it
Input: pointer to stack structure. if null pointer sent wont preform operation
Output: none
*/
void StackDestroy (Stack* _stack);

/*
Description: adds item to top (LIFO), reallocates extra chunks of memory if needed
Input: pointer to stack structure and item to insert
Output: ERR_GENERAL for Null pointer or no previous creation, ERR_OVERFLOW if needed and impossible to reallocate a chunk of memory because its 0, ERR_OK if succesful
*/
ADTErr StackPush (Stack* _stack, int _item);

/*
Description: deletes item from top (LIFO), reallocates chunks of memory if needed - if more than 2 extra chucks of memory to spare it delets 1
Input: pointer to stack structure, pointer to item that will get the deleted value.
Output: ERR_GENERAL for Null pointers or no previous creation, ERR_NOT_INITIALIZED if trying to remove item and there are no items,
	ERR_UNDERFLOW if trying to reallocate less memory than initialiy defined, ERR_OK if succesful
*/
ADTErr StackPop (Stack* _stack, int* _item);

/*
Description: gets the last inserted item from the list.
Input: pointer to stack structure, pointer to variable to insert to
Output: ERR_GENERAL for Null pointers or no previous creation, ERR_WRONG_INDEX if Stack is empty, ERR_OK if succesful
*/
ADTErr StackTop (Stack* _stack, int* _item);

/*
Description: checks if stack is empty
Input: pointer to stack structure
Output: If stack is empty returns 1, else 0
*/
int StackIsEmpty(Stack* _stack);

/*
Description: prints stack struct details and indexed list of items in it, if no stack exists prints alternative message.
Input: pointer to stack structure
Output: none
*/
void StackPrint (Stack* _stack);


#endif /*__stack_h__*/
