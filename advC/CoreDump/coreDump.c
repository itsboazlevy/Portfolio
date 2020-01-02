#include <stdio.h>
#include <stdlib.h>
#define ABORT abort()
#define ASSERT(x) ((x)==5?printf("Assertion fail : expression: %d, %s, line: %d\n", (x), __FILE__,__LINE__),ABORT:(void)0);

int main()
{
	int x = 5;
	ASSERT(x)
	return 1;
}
