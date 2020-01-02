#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma pack(push, 1)

typedef struct a
{
	char c2;
	long c3;
	char c1;
}b;
#pragma pack(pop)

typedef struct b
{
	char c2;
	long c3;
	char c1;
}c;

struct Student
{
	short id;
	short age;
	short len;
	char name[1];
};

typedef struct Student Student;

Student* saveStudent(Student* _addr, short _id, short _age, char* _name)
{
	_addr->id = _id;
	_addr->age = _age;
	_addr->len = strlen(_name);
	strcpy(_addr->name,_name);
	printf("%p\n%d %d %d %s\n",(void*)_addr, _addr->id, _addr->age, _addr->len, _addr->name);
	return (_addr+7+_addr->len);
}



/*swaps*/
void charSwap1(char* a, char* b) 
{
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}

void charSwap2(char* a, char* b) 
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void charSwap3(char* a, char* b) 
{
	*a = *a - *b;
	*b = *a + *b;
	*a = *b - *a;
} 

/* Math */
int intSign(int a)
{
	a = a >> 31;
	return a&1;
}

int AbsNum1(int a)
{
	int b;
	b = intSign(a);
	return (a^b) - b;
}

int AbsNum2(int a)
{
	int b;
	b = intSign(a);
	return (a+b) ^ b;
}

int isPowerOf2(int a)
{
	int flag = 1;
	while(a>0)
	{
		if (a%2 != 0)
		{
			flag = 0;
			break;
		}
		a /= 2;
	}
	return flag;
}

int Add(int a, int b)
{
	int carry = 1;
	while(carry != 0)
	{
		carry = a&b;
		a = a^b;
		b = carry << 1;
	}
	return a;
}

void BinPrint(int a)
{
	int c = 0;
	int count = 0;
	while(count < 32)
	{
		c = c | (a&1);
		c = c<<1;
		a = a>>1;
		count++;
	}
	count = 0;
	while(count < 32)
	{
		printf("%d",c&1);
		c = c>>1;
		count++;
	}
	return;
}

/* BitCount */
int HowManyBitsOn(int a)
{
	int count = 0;
	int count2 = 0;
	while(count < 32)
	{
		if (a&1)
		{
			count2++;
		}
		a = a>>1;
		count++;
	}
	return count2;
}

/* Bit Manipulation */
int flipBits(int a)
{
	return ~a;
}
int FlipBitN(int a,int n)
{	
	return a ^ (1<<(n));
}
int FlipBitsNM(int a,int n, int m)
{	
	return a ^ ( (1<<n) | (1<<m) );
}

int RotateRight(int a,int n)
{
	int count = 0;
	while (count < n)
	{
		if (a&1)
		{
			a = (a>>1) & -0;
			a | (1<<31);
		}
		a = (a>>1)
	}
	return a;
}

int main()
{
	Student* std1 = (Student*) malloc (2000);
	printf("%ld\n",sizeof(b));
	printf("%ld\n",sizeof(c));	
	std1 = saveStudent(std1,1,11,"Avi");
	std1 = saveStudent(std1,2,22,"Shlomo");
	std1 = saveStudent(std1,3,33,"Shaniqua");
	std1 = saveStudent(std1,4,44,"Netta");
	BinPrint(-0);
	return 1;
}

