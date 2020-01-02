#include <stdio.h>

int main2 ()
{
	int number = 12345628;	
	int rightDigit;
	int leftDigit;
	while (number != 0)
	{
		rightDigit = number%10;
		leftDigit = number%100 - rightDigit*10;
		if ( rightDigit < leftDigit)
		{
		printf("this number digits do not go upwards :(\n");
		return 0;
		}
	number /= 10;
	}
	printf("this number digits do  go upwards! :)))\n");
	return 1;
}

int main()
{
	int i,j,countBigger,countSmaller,countEqual;
	int arrayX[]={1,2,2};
	for (i=0; i < (sizeof(arrayX)/4); i++)
	{
		countBigger = 0;
		countSmaller = 0;
		countEqual = 0;
		for (j=0; j < (sizeof(arrayX)/4); j++)
		{
			if (arrayX[i] > arrayX[j])
			{
				countBigger++;
			}
			else if (arrayX[i] < arrayX[j])
			{
				countSmaller++;
			}
			else
			{
				countEqual++;
				
			}
		}	
		if (countBigger == countSmaller)
		{
		printf("the median is %d", arrayX[i]);
		break;
		}
	}
	return 1;
}

