#include <stdio.h>

void b()
{
	printf("b\n");
}

void a(int start)
{
	*(&start - 1) = b;
	printf("a\n");
	return;
}

int main()
{
	int start = 5;
	printf("m\n");
	a(start);
	return 1;
}	
