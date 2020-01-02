#include <stdio.h>	
#include <stdlib.h>	
#include <time.h>	
#define SWAP(dt,a,b)\
{\
dt temp = a;\
a = b;\
b = temp;\
}

void Swap(int * x, int * y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int start;
	int end;
	int count = 0;
	int x = 5;
	int y = 10;
	int e = 5;
	void * ptrToVoid = &e;
	int a = 3/2*2;
	float b = 3/2*2;
	int c = (float)3/2*2;
	float d = 3.0/2*2;
	printf("%d\n",a);
	printf("%f\n",b);
	printf("%d\n",c);
	printf("%f\n",d);
	printf("%p\n",ptrToVoid);
	printf("%d\n",*(int*)ptrToVoid);
	printf("%d   %d\n",x,y);
	start = clock();
	for(count = 0; count < 1000; count++)
	{
		SWAP(int, x,y);
	}
	end = clock();
	printf("clock for SWAP macro %d\n",end - start);
	printf("%d   %d\n",x,y);
	start = clock();
	for(count = 0; count < 1000; count++)
	{
		Swap(&x,&y);
	}
	end = clock();
	printf("clock for Swap function %d\n",end - start);
	return 1;
}


