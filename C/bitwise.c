#include <stdio.h>
int Checks(unsigned int _num)
{
	printf("%u\n",_num & _num);
	printf("%u\n",_num | _num);
	printf("%u\n",_num ^ _num);
	printf("%u\n",~_num);
	printf("%u\n",_num>>2);
	printf("%u\n",_num<<2);
	return 1;
}

int TurnOnBitN(unsigned int _num,int _n)
{	
	return _num | 1<<(_n-1);
}

int HowManyBitsOn(unsigned int _num)
{
	int count = 0;
	while(_num != 0)
	{
		if ((1 | _num) == _num)
		{
			count++;
		}
		_num = _num>>1;
	}
	return count;
}

int HowManyBitsDiffrent(unsigned int _num, unsigned int _num2)
{
	return HowManyBitsOn(_num ^ _num2);		
}

int OffsetOf3Bit(unsigned int _num)
{
	int count = 0;
	int offset = 0;
	while(_num != 0)
	{
		if ((1 | _num) == _num)
		{
			count++;
		}
		offset++;
		if (count == 3)
		{
			return offset;
		}
		_num = _num>>1;
	}
	return 0;
}

int InvertBits(unsigned char _ch)
{
	int i;
	unsigned char invertedCh = ~_ch;
	printf("Given Char: %c %d  \n",_ch,_ch);
	for(i = 0; i < sizeof(char)*8; i++)
	{
		if ( (_ch & 128) != 0)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		_ch = _ch<<1;
	}
	printf("\nInverted Char:       \n");
	for(i = 0; i < sizeof(char)*8; i++)
	{
		if ( (invertedCh & 128) != 0)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		invertedCh = invertedCh<<1;
	}
	printf("\n");
	return 1;
}

int RotateRight(unsigned char _ch,int n)
{
	int i;
	unsigned char rotatedCh;
	rotatedCh = _ch;
	for(i = 0; i < n; i++)
	{
		if ((rotatedCh & 1) == 0)
		{
			rotatedCh = rotatedCh>>1;

		}
		else
		{
			rotatedCh = rotatedCh>>1;
			rotatedCh = rotatedCh | 128;
		}
	}
	printf("Given Char: %c %d  \n",_ch,_ch);
	for(i = 0; i < sizeof(char)*8; i++)
	{
		if ( (_ch & 128) != 0)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		_ch = _ch<<1;
	}
	printf("\nChar rotated by n:       \n");
	for(i = 0; i < sizeof(char)*8; i++)
	{
		if ( (rotatedCh & 128) != 0)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		rotatedCh = rotatedCh<<1;
	}
	printf("\n");
	return 1;
}
unsigned int SetBits(unsigned int _num,int i,int j,int value)
{	
	int k;
	int originalI = i;
	unsigned int tempNum;
	unsigned int tempNum2 = 0;
	unsigned int result;
	if( i >= 0 && i <= 31 && j >= 0 && j <= 31)
	{
		for(i = originalI; i <= j; i++)
		{
			tempNum = 1;
			for(k = 1; k < i; k++)
			{
				tempNum *= 2;
			}
			tempNum2 += tempNum;
		}	
		if (value == 0)
		{
			result = _num & (~tempNum2);

		}
		else
		{
			result = _num | tempNum2;
		}
	}
	return result;
}
int isNegative(int _a)
{
	_a = _a >> (sizeof(int)*8 - 1);
	return _a &= 1;
}

int Max(int _a, int _b)
{
	int result = isNegative(_a - _b); 
	return result*_b + (!result)*_a;
}

int IsBigEndian()
{
	int check = 1;
	char* ptr = (char*)&check;
	if (*ptr == check)
	{
		return 0;
	}
	return 1;
}
typedef struct Bit Bit;
struct Bit
{
	unsigned int int1 :1;
	unsigned int int2 :2;
	unsigned int:0;	
	unsigned int int6 :6;
	unsigned int:5;
	unsigned int int9 :9;	
}; 

int main()
{
	unsigned int num = 12;
	unsigned int num2 = 13;
	int n = 3;
	unsigned char ch = 'A';
	Bit temp;
	Bit* BitStruct = &temp;
	
	Checks(num);
	printf("%d\n",TurnOnBitN(num,n));
	printf("%d\n",HowManyBitsOn(num));
	printf("%d\n",HowManyBitsDiffrent(num,num2));
	printf("%d\n",OffsetOf3Bit(num));
	InvertBits(ch);
	RotateRight(ch,n);
	printf("%u\n",SetBits(num,6,8,1));
	printf("%d\n",Max(13, 8));
	printf("%d\n",IsBigEndian());
	printf("------\n");
	BitStruct->int1 = 1;
	BitStruct->int2 = 3;
	BitStruct->int6 = 12;
	BitStruct->int9 = 12;
	printf("%d\n",BitStruct->int1);
	printf("%d\n",BitStruct->int2);
	printf("%d\n",BitStruct->int6);
	printf("%d\n",BitStruct->int9);
	printf("%ld\n",sizeof(Bit));
	
	
	return 1;
}
