#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int IntDec (void* _ptr1, void* _ptr2)
{
	int* tempPtr1 = (int*)_ptr1;
	int* tempPtr2 = (int*)_ptr2;
	return *tempPtr2-*tempPtr1;
}

int DoubleDec (void* _ptr1, void* _ptr2)
{
	double* tempPtr1 = (double*)_ptr1;
	double* tempPtr2 = (double*)_ptr2;
	return *tempPtr2-*tempPtr1;
}

int CharDec (void* _ptr1, void* _ptr2)
{
	char* tempPtr1 = (char*)_ptr1;
	char* tempPtr2 = (char*)_ptr2;
	return *tempPtr2-*tempPtr1;
}


int GenSort(void* _data, size_t _elementSize, size_t _numOfElements, int (*decFunc) (void* first, void* sec))
{
	if( _data == NULL)
	{
		return 0;
	}
	int count, count2, flag;
	char * tempCharPtr = _data;
	char * tempChar = (char*)malloc(_elementSize);
	for(count = 0; count < _numOfElements-1; count++)
	{
		flag = 0;
		for (count2 = 0; count2 < _numOfElements-count-1; count2++)
		{
			if(decFunc(tempCharPtr +count2*_elementSize,tempCharPtr +(count2+1)*_elementSize) > 0)
			{
				memcpy(tempChar, tempCharPtr +count2*_elementSize, _elementSize);
				memcpy(tempCharPtr +count2*_elementSize,tempCharPtr +(count2+1)*_elementSize, _elementSize);
				memcpy(tempCharPtr +(count2+1)*_elementSize,tempChar, _elementSize);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return 1;
		}
	}
	return 1;
}

int main()
{
	int count;
	int intArr[10] = {1,4,5,6,2,3,4,9,7,15};
	GenSort(intArr,sizeof(intArr)/sizeof(int),sizeof(int), IntDec);
	for (count = 0; count < sizeof(intArr)/sizeof(int); count++)
	{
		printf("%d  ",intArr[count]);
	}
	return 1;
}

