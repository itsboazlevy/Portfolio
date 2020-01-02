#include <stdio.h>

int isPalindrom (int number)
{
	int originalNumber = number;	
	int reversedNumber = 0;
	while( number != 0)
	{
		reversedNumber = (reversedNumber*10) + (number%10);
		number /= 10;
	}
	if (reversedNumber == originalNumber)
	{
	printf("the number is a palindrome!\n");
	}
	else
	{	
	printf("the number is not a palindrom!\n");
	}
	return 1;	
}

int isPrime(int number)
{
	if (number < 2)
	{
		printf("the number is not a primary number!\n");
	}
	else
	{
		for(int i = 2; i < number; i++)
		{
			if ((number%i) == 0)
			{
				printf("the number is not a primary number!\n");
				return 0;
			}
		}
	}
	printf("the number is a primary number!\n");
	return 1;
}

int main()
{
	int num = 193;
	isPalindrom(num);
	isPrime(num);
	return 1;
}





