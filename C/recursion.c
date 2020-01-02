#include <stdio.h>

int Power(int _n, int _k)
{
	if(_k == 0)
	{
		return 1;
	}
	return Power(_n,_k-1)*_n;
}

int Sum(int _arr[],int _n)
{
	if (_n == 1)
	{
		return _arr[0];
	}
	return _arr[0] + Sum(_arr+1, _n-1);
}

int Biggest(int _arr[],int _n)
{
	int size;
	if (_n == 1)
	{
		return _arr[0];
	}
	size = Biggest(_arr,_n-1);
	if (_arr[_n-1] >= size)
	{
		return _arr[_n-1];
	}
	return size;	
}

int Fibonachi (int _n)
{
	int a;
	int b;
	if (_n == 1)
	{
		return a = 0;
	}
	if (_n == 2)
	{
		a = 0;
		b = 1;
		return a+b;
	}
	return Fibonachi (_n-1) + Fibonachi (_n-2);
}

char LastInString(char str[])
{
	if ( str[0] == '\0')
	{
		return *(str - 1);
	}
	return LastInString(++str);
}

float Average(int _arr[],float _n)
{	
	if (_n == 1)
	{
		return _arr[0];
	}
	return (_arr[0] + Average(_arr+1, _n-1)*(_n-1))/_n;
}

int Reverse(char _str[], int _size)
{
	int temp; 
	if (_size <= 0 )
	{
		return 1;
	}
	temp = *_str;
	*_str = *(_str+_size-1);
	*(_str+_size-1) = temp;
	return Reverse(++_str,_size-2);
}

int Triangles (int _size)
{
	int i;
	if (_size == 0)
	{
		return 1;
	}
	for(i=0;i<_size;i++)
	{
		printf("*");
	}
	printf("\n");
	return Triangles (_size-1);
}  

int Triangles2 (int _size)
{
	int i;
	if (_size == 0)
	{
		return 1;
	}
	Triangles2(_size-1);
	for(i=0;i<_size;i++)
	{
		printf("*");
	}
	printf("\n");
	return 1;
}  

int Palindrom(char _str[], int _size)
{
	if (_size <= 0 )
	{
		return 1;
	}
	if(*_str != *(_str+_size-1))
	{
		return 0;
	}
	return Palindrom(++_str,_size-2);
}

int MulTable(int _size,int _x,int _y)
{
	if ( _x <= _size)
	{
		printf("%4d",(_x)*(_y));
		return MulTable(_size,_x+1,_y);
	}
	if (_y < _size)
	{
		printf("\n");
		return MulTable(_size,_x-_size,_y+1);
	}
	return 1;
}

int main()
{
	int arr[6] = {1,2,3,4,5,6};
	char str[] = "acbdhthdbca";
	printf("Power %d\n",Power(3,3));
	printf("Sum %d\n",Sum(arr,29)); 
	printf("Biggest %d\n", Biggest(arr,6));
	printf("Fibonachi %d\n", Fibonachi(15));	
	printf("LastInString %c\n", LastInString(str));
	printf("Average %f\n",Average(arr,6)); 
	Reverse(str,11);
	printf("Reverse %s\n",str); 
	printf("Palindrom if 1: %d\n",Palindrom(str,11));
	Triangles (5);
	Triangles2 (5);
	MulTable (9,1,1);
	/* bigger cannot be on top of smaller, 3 pillars, move 5 Blocks from A to B. C helps. void Hanoi(int_n,char_from, char_to,char_via), complexity? */
	/*how to position 8 queens on a 64 chess board - there are many solution. */	
	/*all possible orders of a string*/	
	return 1;
}




