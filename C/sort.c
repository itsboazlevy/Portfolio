#include <stdio.h>

int checkParameters(int arr[],int size)
{
	if (arr == NULL || size <= 0)
	{
	return 1;
	}
	return 0;
}

int printArray(int arr[],int size)
{
	for (int i = 0; i < size; i++)
	{
	printf("%d ",arr[i]);
	}
	printf("\n");
}

void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int sort (int arr[],int size)
{
	int i,j,swapFlag;
	if (checkParameters(arr,size))
	{
		return 0;
	}
	for (i = 0; i < size-1; i++)
	{
		for (j = 0, swapFlag = 0; j < size-1-i ; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(&arr[j],arr+j+1);
				swapFlag = 1;
			}
		}
		if (swapFlag == 0)
		{
			break;
		}	
	}	
	return 1;
}  

int sortEvenOdd (int arr[],int size)
{
	int i,j,flagSwap;
	if (checkParameters(arr,size))
		{
			return 0;
		}
	for (i = 0, flagSwap = 0; i < size-1; i++)
		{
			for ( j = 0; j < size-1 ; j++)
			{
				if (arr[j]%2 && !(arr[j+1]%2))
				{
					swap(&arr[j],arr+j+1);
					flagSwap = 1;
				}
			}
			if (flagSwap == 0)
			{
				break;
			}
 	
		}		
	return 1;
}  

int mostPopular (int *arr, int size)
{	
	int mostPopularNum, i, j;
	int localCount = 0;
	int count = 0;
	if (checkParameters(arr,size))
	{
		return 0;
	}
	
	for (i = 0; i < size; i++)
		{
			localCount = 0;
			for (j = i; j < size; j++)
			{
				if (arr[i] == arr[j])
				{
					localCount ++;
				}
			}
			if (localCount > count)
			{
				count = localCount;
				mostPopularNum = arr[i];
			} 	
		}		
	return mostPopularNum;
}



