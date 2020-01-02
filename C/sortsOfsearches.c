#define SIZE  1000000
#include <time.h>
#include <stdlib.h>	
#include <stdio.h>	

int SimpleSearch (int* _array, int _item)
{
	
	int count;
	for(count = 0; count < SIZE; count++)
	{
		if (_array[count] == _item)
		{
			return 1;
		}
	}
	return 0;
}

int EndFoundSearch (int* _array, int _item)
{
	int count;
	count = 0;
	while(_array[count++]!=_item);
	return (count<=SIZE)?1:0;	 
}

int BinarySearch (int* _array, int _item)
{
	int count;
	count = 0;
	while(_array[count++]!=_item);
	return (count<=SIZE)?1:0;	 
}

int main()
{
	int start, end;
	int array[SIZE];
	int result, count, item;
	item = 0;
	for(count = 0; count < SIZE; count++)
	{
		array[count] = count+1;
	}
	array[count] = item;
	
	start = clock();
	result = SimpleSearch(array,item);
	end = clock();
	printf("Time for SimpleSearch  : %d		Search result: %d\n",(end - start),result);
	
	start = clock();
	result = EndFoundSearch(array,item);
	end = clock();
	printf("Time for EndFoundSearch  : %d		Search result: %d\n",(end - start),result);
	
	start = clock();
	result = BinarySearch(array,item);
	end = clock();
	printf("Time for BinarySearch  : %d		Search result: %d\n",(end - start),result);
	
	return 1;

}

