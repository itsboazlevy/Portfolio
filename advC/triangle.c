#include <stdio.h>


int checkParameters (char symbol, int size)
{
	if (size < 1 || size > 100)
	{
		printf("Entered number is out of bounds! Goodbye.\n");
		return 0;
	}
	else
	{
		return 1;
	} 
}

int uprighttriangle(char symbol, int size)	
{
	int i,j;
	if (!checkParameters(symbol,size))
	{
		return 0;
	}	
	for (i = 0; i < size; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%c",symbol);
		}
		printf("\n");
	}
	return 1;
}

int downrighttriangle(char symbol, int size)
{
	int i,j;
	if (!checkParameters(symbol,size))
	{
		return 0;
	}	
	for (i = 0; i < size; i++)
	{
		for (j = size; j > i; j--)
		{
			printf("%c",symbol);
		}
		printf("\n");
	}
	return 1;	
}

int righttriangle(char symbol, int size)
{
	if (!checkParameters(symbol,size))
	{
		return 0;
	}	
	uprighttriangle(symbol,size);
	downrighttriangle(symbol,size-1);
	return 1;	
}

int uptriangle(char symbol, int size)
{
	int i,k,j;
	if (!checkParameters(symbol,size))
	{
		return 0;
	}	
	for (i = 0; i < size; i++)
	{
		for (k = size; k > i; k--)
		{
			printf(" ");
		}		
		for (j = 0; j <= i; j++)
		{
			printf("%c ",symbol);
		}
		printf("\n");
	}
	return 1;	
}

int downtriangle(char symbol, int size)
{
	int i,k,j;
	if (!checkParameters(symbol,size))
	{
		return 0;
	}
	for (i = 0; i < size; i++)
		{
		printf(" ");		
		for (k = 0; k < i; k++)
		{
			printf(" ");
		}		
		for (j = size; j > i; j--)
		{
			printf(" %c",symbol);
		}
		printf("\n");
	}	
	return 1;
}

int updowntriangle(char symbol, int size)
{
	if (!checkParameters(symbol,size))
	{
		return 0;
	}	
	uptriangle(symbol,size);
	downtriangle(symbol,size-1);
	return 1;
}

