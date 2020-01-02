#include "heap.h"

Vector* sortHeap(Vector* _vec)
{ /*need to sort the vector, can use vector commands and heap commands */
	int data;
	int count;
	int vecNumOfItems;
	Heap* myHeap = NULL;
	myHeap = HeapBuild(_vec);
	HeapExtractMax (myHeap, &data);
	VectorSet(_vec,0,data);
	VectorGetItemsNum(_vec,&vecNumOfItems);
	for(count = 0; count < vecNumOfItems; count++)
	{
		VectorGet(_vec,count,&data);
		printf("%d",data);
	}
	return _vec;
}
int main()
{
	int initialVectorSize = 5;
	int vectorExtensionBlockSize = 2;
	Vector* myVector = NULL;
	myVector = VectorCreate (initialVectorSize,vectorExtensionBlockSize);
	VectorAdd (myVector,3);	
	VectorAdd (myVector,1);
	VectorAdd (myVector,2);
	return 1;
}
