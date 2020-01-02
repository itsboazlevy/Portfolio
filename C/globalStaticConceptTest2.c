#include <stdio.h>
int Baby();
int Baby()
{
	extern int g_num;
	printf("g_num %d",g_num);
	return 1;
	
}
