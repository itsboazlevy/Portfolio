#include "stack.h"

int main()
{
	char string[] = "(8/4)+2*(7*3)-9/3";
	char newString[50];
	int i = 0;
	int j = 0;
	int item;
	int item2;
	Stack* ptr;
	ptr = StackCreate (5,5);
	while (string[i] != '\0')
	{
		if ( string[i] == '(')
		{
			StackPush (ptr, string[i]);
		}
		if (string[i] == ')')
		{
			StackTop(ptr,&item);
			while (!StackIsEmpty(ptr) && item != '(')
			{
				StackPop (ptr,&item);
				newString[j] = item;
				j++;
				StackTop(ptr,&item);
			}
			StackPop(ptr,&item);
		}
		if ( string[i] >= '0' && string[i] <= '9')
		{
			newString[j] = string[i] ;
			j++;
		}
		if (string[i] == '+' || string[i] == '-') 
		{
			StackTop(ptr,&item);
			while (!StackIsEmpty(ptr) &&  item != '(')
			{
				StackPop (ptr,&item);
				newString[j] = item;
				j++;
				StackTop(ptr,&item);
			}
			StackPush (ptr, string[i]);
		}
		if ( string[i] == '*' || string[i] == '/')
		{
			StackTop(ptr,&item);
			while ( item != '-' && item != '+' && !StackIsEmpty(ptr) &&  item != '(' )
			{
				StackPop (ptr,&item);
				newString[j] = item;
				j++;
				StackTop(ptr,&item);
			}
			StackPush (ptr, string[i]);
		}
		i++;
		
	}
	while (!StackIsEmpty(ptr))
	{
		StackPop (ptr,&item);
		newString[j] = item;
		j++;
	}
	newString[j] = '\0';
	for(i=0; newString[i] != '\0'; i++)
	{
		if ( newString[i] >= '0' && newString[i] <= '9')
		{
			StackPush (ptr,newString[i] - '0');
		}	
		if (newString[i] == '+') 
		{
			StackPop (ptr,&item2);
			StackPop (ptr,&item);
			StackPush (ptr, item + item2);
		}
			if ( newString[i] == '-') 
		{
			StackPop (ptr,&item2);
			StackPop (ptr,&item);
			StackPush (ptr, item - item2);
		}
			if (newString[i] == '*' ) 
		{
			StackPop (ptr,&item2);
			StackPop (ptr,&item);
			StackPush (ptr, item * item2);
		}
			if (newString[i] == '/') 
		{
			StackPop (ptr,&item2);
			StackPop (ptr,&item);
			StackPush (ptr, item / item2);
		}
	}
	StackPop (ptr,&item);
	printf("Answer is: %d\n",item);
	return 1;
}
