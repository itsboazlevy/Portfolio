#include <stdio.h>
#include <stdarg.h>
#define arrSize 10
#define NULL_ERR 0
#define INDEX_ERR -1
#define MAX_NUM_DIGITS 20
#define DEFAULT_DIGITS_AFTER_POINT 3

float Average(int _n, ...)
{
	double total = 0;
	int i;
	va_list myList;
	va_start (myList, _n);
	for (i = 0; i < _n; i++)
	{
		total += va_arg(myList, double);
	}
	va_end(myList);
	if (_n==0)
	{
		return 0;
	}
	return total/_n;
}

int UpdateArr(int *_arr, int _size, int _n,...)
{
	int count;
	int temp;
	va_list myList;
	if (_arr == 0)
	{
		return NULL_ERR;
	}
	va_start (myList, _n);
	for (count = 0; count < _n; count++)
	{
		temp = va_arg(myList, int);
		if (temp > _size-1)
		{
			return INDEX_ERR;
		}
		_arr[temp] = va_arg(myList, int);
	}
	va_end(myList);
	return 1;
}

int PrintArray(int* _arr,int _size)
{
	int count;
	for(count = 0; count < _size; count++)
	{
		printf("%d ",_arr[count]);
	}
	printf("\n");
	return 1;
}

int PrintString(char* _string)
{
	int count;
	for (count = 0; _string[count] != '\0'; count++)
	{
		putchar(_string[count]);
	}
	return 1;
}


int Itoa (int _num, char *_str)
{	
	int reversedNumber = 1,i = 0; 
	if (_str == NULL)
	{
		return 0;
	}
	if (_num < 0)
	{
		*_str = '-';
		_str++;
		_num *= -1;
	}
	while(_num != 0)
	{
		reversedNumber = (reversedNumber*10) + (_num%10);
		_num /= 10;
	}
	while (reversedNumber != 1)
	{
		*(_str+i) = reversedNumber%10 + '0';
		reversedNumber /= 10;
		i++;
	}
	*(_str+i) = '\0';
	return 1;	
}

int Ftoa (double _num, char *_str,int _digitsAfterPoint)
{
	int floatLeft;
	float floatRight;
	if (_str == NULL)
	{
		return 0;
	}
	floatLeft = (int)_num;
	floatRight = _num - floatLeft;
	Itoa(floatLeft,_str);
	while (*_str != '\0')
	{
	 _str++;
	}
	*_str = '.';
	_str++;
	while (_digitsAfterPoint > 0)
	{
		*_str = (int)(floatRight*10) + '0';
		floatRight = (floatRight*10) - (int)(floatRight*10);
		_str++;
		_digitsAfterPoint--;
	}
	_str = '\0';
	return 1;
}

int Spaces(int _num)
{
	while(_num!=0)
	{
		putchar(' ');
		_num--;
	}
	return 1;
}

void MiniPrintf(char* _format,...)
{
	va_list myString;
	int count;
	char* tempCharPtr;
	char tempCharPtr2[MAX_NUM_DIGITS];

	if (_format == NULL)
	{
		return;
	}
	va_start (myString, _format);
	for (count = 0; _format[count] != '\0'; count++)
	{
		if ( _format[count] == '%' && (_format[count+1] == 'd' || _format[count+1] == 'c' || _format[count+1] == 's' || _format[count+1] == 'f') )
		{
			switch (_format[count+1])
			{	
				case 'c':	putchar(va_arg(myString, int));
							break;
				case 's':	tempCharPtr = va_arg(myString, char*); 
							PrintString(tempCharPtr);
							break;
				case 'f':	Ftoa(va_arg(myString, double),tempCharPtr2,DEFAULT_DIGITS_AFTER_POINT);
							PrintString(tempCharPtr2);
							break;
				case 'd':	Itoa(va_arg(myString, int),tempCharPtr2);
							PrintString(tempCharPtr2);
							break;
			};
		count++;
		continue;
		}
		if ( _format[count] == '%' && (_format[count+1]>='0' && _format[count+1]<='9') && (_format[count+2] == 'd' || _format[count+2] == 'f') )
		{
			switch (_format[count+2])
			{	
				case 'f':	Ftoa(va_arg(myString, double),tempCharPtr2, _format[count+1]-'0');
							PrintString(tempCharPtr2);
							break;
				case 'd':	Itoa(va_arg(myString, int),tempCharPtr2);
							Spaces(_format[count+1]-'0');
							PrintString(tempCharPtr2);
							break;
			};
		count+=2;
		continue;
		}
		putchar(_format[count]);
	}
	printf("\n");
	va_end(myString);
	return;
}

int main()
{
	int array[arrSize] = {1,2,3,4,5,6,7,8,9,10};
	printf("%.3f\n",Average(5,1.2,2.4,3.6,4.1,5.7));
	printf("%.3f\n",Average(3,10.0,19.3,12.5));
	PrintArray(array,arrSize);
	UpdateArr(array,arrSize,2,2,24,6,25);
	PrintArray(array,arrSize);
	MiniPrintf("abcd %c fg %s pqrstuvwxyz %5d %d %f %f  %f %5f",'e',"hijklmno",1,2345,6.789, 0.123, 9.0, 9.0);
	return 1;
}
