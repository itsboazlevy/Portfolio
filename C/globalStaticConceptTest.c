#include <stdio.h>

int g_num = 6;
static int num = 6;
static int statFunc()
{
	printf("IM A STATIC FUNCTION");
	return 1;
}
 


int main()
{
	int static staticNum5 = 5;
	int static staticNum;
	int num = 5;
	
	printf("staticNum5 %d\n",staticNum5);
	printf("staticNum %d\n",staticNum);
	printf("num %d\n",num);
	staticNum5 = 7;
	staticNum = 7;
	num = 7;
	printf("staticNum5 %d\n",staticNum5);
	printf("staticNum %d\n",staticNum);
	printf("num %d\n",num);
	staticNum5 = 9;
	staticNum = 9;
	num = 9;
	Baby();
	return 1;
}
