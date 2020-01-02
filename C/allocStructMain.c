#include <stdio.h>
#include <stdlib.h>
#include "allocStruct.h"

int main ()
{
	struct da *myStruct;
	int status;
	int data = 2020;
	int size = 1;
	int incrementBlockSize = 0;	
	myStruct = create(size, incrementBlockSize);
	insert1(myStruct, data);
	insert1(myStruct, data);
	insert1(myStruct, data);
	data = 0;
	printf("data %d\n",data);
	remove1 (myStruct, &data);
	printf("data %d\n",data);
	destroy(myStruct);
	return 1;
	  		
}
