#include "stack.h"
#include "DV.h"

struct Stack
{
	Vector* Vector;
};

Stack* StackCreate (size_t _size, size_t _blocksize)
{
	return (Stack*)VectorCreate (_size, _blocksize);
}

void StackDestroy (Stack* _stack)
{
	VectorDestroy ((Vector*)_stack);
}

ADTErr StackPush (Stack* _stack, int _item)
{
	return VectorAdd ((Vector*) _stack, _item);
}

ADTErr StackPop (Stack* _stack, int* _item)
{
	return VectorDelete ((Vector*)_stack, _item);
}

ADTErr StackTop (Stack* _stack, int* _item)
{
	int numOfItems;
	VectorGetItemsNum((Vector*) _stack, &numOfItems);
	return VectorGet((Vector*) _stack, numOfItems-1, _item);
}

int StackIsEmpty(Stack* _stack)
{
	int status;
	VectorGetItemsNum((Vector*) _stack, &status);
	if (status == 0)
	{
		return 1;
	}
	return 0;
}

void StackPrint (Stack* _stack)
{
	VectorPrint ((Vector*)_stack);
}

