#include "stack.h"

int main()
{
	Stack* userPtr = NULL;
	size_t size = 5;
	size_t blockSize = 5;
	int item;
	int itemGot = 2;
	int i;
	
	userPtr = StackCreate (size,blockSize);
	
	for(i = 0; i < 30; i++)
	{
		item = (int)getchar();
		if (item == '[' || item == '(' || item == '{')
		{
			StackPush (userPtr,item);
		}
		if (item == ']' ||  item == '}')
		{
			StackPop(userPtr,&itemGot);
			if (itemGot+2 != item)
			{
				printf("its bad");
				break;
			}	
		}
		if (item == ')')
		{
			StackPop(userPtr,&itemGot);
			if (itemGot+1 != item)
			{
				printf("its bad");
				break;
			}
		}
	}
	
	if (StackIsEmpty(userPtr))
	{
		printf("ALL GOOD!");
	}
	else
	{
		printf("NOPE!");
	}
	return 1;
}


