#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define arrSize 10
#define arr2Size 10000
#define SWAP(dt,a,b)\
{\
dt temp = a;\
a = b;\
b = temp;\
}

static void PrintArray (int array[], int size)
{
	int count;
	for (count = 0; count < size; count++)
	{
		printf("%d ",array[count]);		
	}
	printf("\n");		
}

int tabulate ( double (*funcPTR)(double) )
{
	int count;
	for (count = 0 ; count <= 90; count++)
	{
		printf("%d    %f\n",count,funcPTR(count));
	}
	printf("\n");
	return 1;
}

/* sorts types */
int SmallToBig(int first, int second)
{
	if(first>second)
	{
		return 1;
	}
	return 0;
}

int BigToSmall(int first, int second)
{
	if(first<second)
	{
		return 1;
	}
	return 0;
}

int UnevenToEven(int first, int second)
{
	if(first%2 == 0 && second%2 != 0)
	{
		return 1;
	}
	return 0;
}

int EvenToUneven(int first, int second)
{
	if(first%2 != 0 && second%2 == 0)
	{
		return 1;
	}
	return 0;
}

int SmallToBigLastDigit(int first, int second)
{
	if (first < 0)
	{
		first *= -1;
	}
	if (second < 0)
	{
		second *= -1;
	}
	if(first%10 > second%10)
	{
		return 1;
	}
	return 0;
}

int BigToSmallLastDigit(int first, int second)
{
	if (first < 0)
	{
		first *= -1;
	}
	if (second < 0)
	{
		second *= -1;
	}
	if(first%10 < second%10)
	{
		return 1;
	}
	return 0;
}

int BigToSmallDigitsNumber(int first, int second)
{
	while (first != 0 && second != 0)
	{
		first = first/10;
		second = second/10;
	}
	if(first == 0 && second!= 0)
	{
		return 1;
	}
	return 0;
}

int SmallToBigDigitsNumber(int first, int second)
{
	
	while (first != 0 && second != 0)
	{
		first = first/10;
		second = second/10;
	}
	if(second == 0 && first!= 0)
	{
		return 1;
	}
	return 0;
}
/* generic sort functions with Swap function or SWAP macro  */
static void Swap(int * x, int * y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int GenericBubble (int *arr, int size,int (*SwapDesc)(int first, int second))
{
	int flag;
	int testFlag;
	int count;
	int count2;
	if ( arr == NULL || SwapDesc == NULL)
	{
		return 0;
	}
	for (count = 0; count < size-1; count++)
	{
		flag = 0;
		for (count2 = 0; count2 < size-1-count; count2++)
		{
			if (SwapDesc(*(arr+count2),*(arr+count2+1)))
			{
			Swap(arr+count2,arr+count2+1);
			flag = 1;
			testFlag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
	if (testFlag == 0)
	{
		return 0;
	}
	return 1;
}

int GenericBubbleWithDefineSwap (int *arr, int size,int (*SwapDesc)(int first, int second))
{
	int flag;
	int testFlag;
	int count;
	int count2;
	if ( arr == NULL || SwapDesc == NULL)
	{
		return 0;
	}
	testFlag = 0;
	for (count = 0; count < size-1; count++)
	{
		flag = 0;
		for (count2 = 0; count2 < size-1-count; count2++)
		{
			if (SwapDesc(*(arr+count2),*(arr+count2+1)))
			{
			SWAP(int,*(arr+count2),*(arr+count2+1));
			flag = 1;
			testFlag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
	if (testFlag == 0)
	{
		return 0;
	}
	return 1;
}

int main()
{
	int array[arrSize] = {5,-3,16,1005,0,14567,-205,-900,28,-21};
	int array2[arr2Size];
	int count;
	int endTime;
	int startTime;
	tabulate(sin);
	tabulate(cos);
	tabulate(tan);
	/* sorts on short array */
	printf("Original Array: \n");
	PrintArray(array,arrSize);
	GenericBubble(array,arrSize,SmallToBig);
	printf("SmallToBig Sort: \n");
	PrintArray(array,arrSize);
	GenericBubble(array,arrSize,BigToSmall);
	printf("BigToSmall Sort: \n");
	PrintArray(array,arrSize);
	GenericBubble(array,arrSize,UnevenToEven);
	printf("UnevenToEven Sort: \n");
	PrintArray(array,arrSize);
	GenericBubble(array,arrSize,EvenToUneven);
	printf("EvenToUneven Sort: \n");
	PrintArray(array,arrSize);
	GenericBubble(array,arrSize,SmallToBigLastDigit);
	printf("SmallToBigLastDigit Sort: \n");
	PrintArray(array,arrSize);
	GenericBubble(array,arrSize,BigToSmallLastDigit);
	printf("BigToSmallLastDigit Sort: \n");
	PrintArray(array,arrSize);
	GenericBubble(array,arrSize,BigToSmallDigitsNumber);
	printf("BigToSmallDigitsNumber Sort: \n");
	PrintArray(array,arrSize);
	GenericBubble(array,arrSize,SmallToBigDigitsNumber);
	printf("SmallToBigDigitsNumber Sort: \n");
	PrintArray(array,arrSize);
	/* creation of long random array with negative numbers */
	for (count = 0; count < arr2Size; count++)
	{
		array2[count] = rand()%1000;
		if (rand()%1000 > 500)
		{
			array2[count] *= -1;
		}
	}
	/* time check for sort with Swap function */
	startTime = clock();
	GenericBubble(array2,arr2Size,SmallToBig);
	GenericBubble(array2,arr2Size,BigToSmall);
	GenericBubble(array2,arr2Size,UnevenToEven);
	GenericBubble(array2,arr2Size,EvenToUneven);
	GenericBubble(array2,arr2Size,SmallToBigLastDigit);
	GenericBubble(array2,arr2Size,BigToSmallLastDigit);
	GenericBubble(array2,arr2Size,BigToSmallDigitsNumber);
	GenericBubble(array2,arr2Size,SmallToBigDigitsNumber);
	endTime = clock();
	printf("Time for genericBubble function to complete sorts: %d\n",endTime-startTime);
	/* time check for sort with SWAP macro */
	startTime = clock();
	GenericBubbleWithDefineSwap(array2,arr2Size,SmallToBig);
	GenericBubbleWithDefineSwap(array2,arr2Size,BigToSmall);
	GenericBubbleWithDefineSwap(array2,arr2Size,UnevenToEven);
	GenericBubbleWithDefineSwap(array2,arr2Size,EvenToUneven);
	GenericBubbleWithDefineSwap(array2,arr2Size,SmallToBigLastDigit);
	GenericBubbleWithDefineSwap(array2,arr2Size,BigToSmallLastDigit);
	GenericBubbleWithDefineSwap(array2,arr2Size,BigToSmallDigitsNumber);
	GenericBubbleWithDefineSwap(array2,arr2Size,SmallToBigDigitsNumber);
	endTime = clock();
	printf("Time for genericBubbleWithDefineSwap function to complete sorts: %d\n",endTime-startTime);
	/* tests	 */
	GenericBubbleWithDefineSwap(array2,arr2Size,SmallToBig);
	if (GenericBubbleWithDefineSwap(array2,arr2Size,SmallToBig) == 0)
	{
		printf("SUCCCESS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	GenericBubbleWithDefineSwap(array2,arr2Size,BigToSmall);
	if (GenericBubbleWithDefineSwap(array2,arr2Size,BigToSmall) == 0)
	{
		printf("SUCCCESS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	GenericBubbleWithDefineSwap(array2,arr2Size,UnevenToEven);
	if (GenericBubbleWithDefineSwap(array2,arr2Size,UnevenToEven) == 0)
	{
		printf("SUCCCESS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	GenericBubbleWithDefineSwap(array2,arr2Size,EvenToUneven);
	if (GenericBubbleWithDefineSwap(array2,arr2Size,EvenToUneven) == 0)
	{
		printf("SUCCCESS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	GenericBubbleWithDefineSwap(array2,arr2Size,SmallToBigLastDigit);
	if (GenericBubbleWithDefineSwap(array2,arr2Size,SmallToBigLastDigit) == 0)
	{
		printf("SUCCCESS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	GenericBubbleWithDefineSwap(array2,arr2Size,BigToSmallLastDigit);
	if (GenericBubbleWithDefineSwap(array2,arr2Size,BigToSmallLastDigit) == 0)
	{
		printf("SUCCCESS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	GenericBubbleWithDefineSwap(array2,arr2Size,BigToSmallDigitsNumber);
	if (GenericBubbleWithDefineSwap(array2,arr2Size,BigToSmallDigitsNumber) == 0)
	{
		printf("SUCCCESS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	GenericBubbleWithDefineSwap(array2,arr2Size,SmallToBigDigitsNumber);
	if (GenericBubbleWithDefineSwap(array2,arr2Size,SmallToBigDigitsNumber) == 0)
	{
		printf("SUCCCESS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	return 1;
}
