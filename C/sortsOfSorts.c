#include <stdio.h>	
#include <stdlib.h>	
#include <time.h>
#include <math.h>		
#include "stack.h"
#define VECTOR_SIZE 10000
#define LINEAR_TEMP_ARR_SIZE 10000
#define GENERAL_BLOCK_SIZE 50
#define VECTOR_COUNT 10

static void Partition(Vector* _vec,int _leftIndex,int _rightIndex, int* _pivotIndex)
{
	int leftNum,rightNum,pivotNum, tempNum;
	*_pivotIndex = _leftIndex;
	_leftIndex++;
	VectorGet(_vec, *_pivotIndex, &pivotNum);
	VectorGet(_vec, _leftIndex, &leftNum);
	VectorGet(_vec, _rightIndex, &rightNum);
	while (_leftIndex < _rightIndex)
	{
		while(leftNum <= pivotNum && _leftIndex < _rightIndex)
		{
			_leftIndex++;
			VectorGet(_vec, _leftIndex, &leftNum);
		}
		while(rightNum > pivotNum )
		{
			_rightIndex--;
			VectorGet(_vec, _rightIndex, &rightNum);
		}
		if (leftNum > rightNum && _leftIndex < _rightIndex)
		{
			VectorSet(_vec,_rightIndex, leftNum);
			VectorSet(_vec,_leftIndex, rightNum);
			tempNum = rightNum;
			rightNum = leftNum;
			leftNum = tempNum;
		}
	}
	if (rightNum < pivotNum)
	{
		VectorSet(_vec,_rightIndex, pivotNum);
		VectorSet(_vec,*_pivotIndex, rightNum);
		*_pivotIndex = _rightIndex;
	}
	return;
}

static void QuickRecursion(Vector* _vec,int _leftIndex,int _rightIndex)
{
	int pivotIndex;
	if(_leftIndex >= _rightIndex ||  _rightIndex < 0 )
	{
		return;
	}
	Partition(_vec,_leftIndex,_rightIndex, &pivotIndex);
	QuickRecursion(_vec,_leftIndex,pivotIndex-1);
	QuickRecursion(_vec,pivotIndex+1,_rightIndex);
	return;
}

ADTErr QuickSortRec(Vector* _vec)
{
	int vecSize,rightIndex;
	if( _vec == NULL )
	{
		return ERR_NULL;
	}
	VectorGetItemsNum(_vec, &vecSize);
	rightIndex = vecSize-1;
	QuickRecursion(_vec,0,rightIndex); 
	return ERR_OK;
}

/*	TODO fix here, push edges and pull to partition*/
/*
ADTErr QuickSort(Vector* _vec)
{
	int vecSize,rightIndex,leftIndex,pivotIndex,count,tempItem,leftNum,rightNum;
	Stack* stack;
	if( _vec == NULL )
	{
		return ERR_NULL;
	}
	VectorGetItemsNum(_vec, &vecSize);
	leftIndex = 0;
	rightIndex = vecSize-1;
	VectorGet(_vec,leftIndex, leftNum);
	VectorGet(_vec,rightIndex, rightNum);
	stack = StackCreate (rightIndex-leftIndex+1, 500);

	StackPush (stack,leftNum);
	while( leftIndex != rightIndex && rightIndex>0)
	{
		Partition(_vec,leftIndex,rightIndex, &pivotIndex);	
	
		leftIndex =  pivotIndex+1;
		rightIndex = rightIndex;
		
		for(count=leftIndex; count<= rightIndex ;count++)
		{
			VectorGet(_vec, count, &tempItem);
			StackPush (stack, tempItem);
		}
		
		leftIndex = 0; 
		rightIndex = pivotIndex-1;
		
	}
	return ERR_OK;
}
*/

ADTErr InsertionSortWithGap(Vector* _vec, int _gap, int _offset)
{
	int count,count2,vecSize,numA,numB;
	if( _vec == NULL )
	{
		return ERR_NULL;
	}
	VectorGetItemsNum(_vec, &vecSize);
	for(count = _gap+_offset; count < vecSize; count+=_gap)
	{
		for (count2 = count; count2 > _offset; count2 -= _gap)
		{
			VectorGet(_vec, count2, &numA);
			VectorGet(_vec, count2-_gap, &numB);
			if(numA<numB)
			{
				VectorSet(_vec,count2-_gap, numA);
				VectorSet(_vec,count2, numB);
			}
			else
			{
				break;
			}
		}
	}
	return ERR_OK;
}

ADTErr ShellSort(Vector* _vec)
{
	int vecSize,offset;
	if( _vec == NULL )
	{
		return ERR_NULL;
	}
	VectorGetItemsNum(_vec, &vecSize);
	vecSize /= 2;
	while (vecSize > 0)
	{
		for(offset = 0; offset < vecSize ;offset++)
		{
			InsertionSortWithGap(_vec,vecSize,offset);
		}
	vecSize /= 2;
	}
	return ERR_OK;
}

ADTErr InsertionSort(Vector* _vec)
{
	if( _vec == NULL )
	{
		return ERR_NULL;
	}
	InsertionSortWithGap(_vec,1,0);
	return ERR_OK;
}

ADTErr BubbleSort(Vector* _vec)
{
	int count,count2,flag,vecSize,numA,numB;
	if( _vec == NULL )
	{
		return ERR_NULL;
	}
	VectorGetItemsNum(_vec, &vecSize);
	for(count = 0; count < vecSize-1; count++)
	{
		flag = 0;
		for (count2 = 0; count2 < vecSize-count-1; count2++)
		{
			VectorGet(_vec, count2, &numA);
			VectorGet(_vec, count2+1, &numB);
			if(numA>numB)
			{
				VectorSet(_vec,count2+1, numA);
				VectorSet(_vec,count2, numB);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return ERR_OK;
		}
	}
	return ERR_OK;
}

ADTErr ShakeSort(Vector* _vec)
{
	int count,count2,flag,vecSize,numA,numB;
	if( _vec == NULL )
	{
		return ERR_NULL;
	}
	VectorGetItemsNum(_vec, &vecSize);
	for(count = 0; count < (vecSize-1)/2; count++)
	{
		flag = 0;
		for (count2 = count; count2 < vecSize-count-1; count2++)
		{
			VectorGet(_vec, count2, &numA);
			VectorGet(_vec, count2+1, &numB);
			if(numA>numB)
			{
				VectorSet(_vec,count2+1, numA);
				VectorSet(_vec,count2, numB);
				flag++;
			}
		}
		if (flag == 0)
		{
			return ERR_OK;
		}
		flag = 0;
		for (count2 = vecSize-count-2; count2 > count; count2--)
		{
			VectorGet(_vec, count2, &numA);
			VectorGet(_vec, count2-1, &numB);
			if(numA<numB)
			{
				VectorSet(_vec,count2-1, numA);
				VectorSet(_vec,count2, numB);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return ERR_OK;
		}
	}
	return ERR_OK;
}
int IsSorted(Vector* _vec)
{
	int count,vecSize,numA,numB;
	if( _vec == NULL )
	{
		return ERR_NULL;
	}
	VectorGetItemsNum(_vec, &vecSize);
	for(count = 0; count < vecSize-1; count++)
	{
		VectorGet(_vec, count, &numA);
		VectorGet(_vec, count+1, &numB);
		if (numA>numB)
		{
			return 0;
		}
	}
	return 1;
}

int SelectionSort(Vector* _vec)
{
	int count,count2,vecSize,comparedNum,currentMinNum;
	if( _vec == NULL )
	{
		return ERR_NULL;
	}
	VectorGetItemsNum(_vec, &vecSize);
	for(count = 0; count < vecSize-1; count++)
	{
		VectorGet(_vec, count, &currentMinNum);
		for (count2 = count+1; count2 < vecSize-1; count2++)
		{
			VectorGet(_vec, count2, &comparedNum);
			if(comparedNum<currentMinNum)
			{
				VectorGet(_vec, count2, &currentMinNum);
			}
		}
		VectorSet(_vec,count, currentMinNum);
		VectorSet(_vec,count2, comparedNum);
	}
	return ERR_OK;
}
/*TODO change some var names to understand better*/
static void Merge(Vector* _vec, int* _tempArr, int _leftIndex, int _rightIndex, int _middleIndex)
{
	int leftNum, rightNum, count,count2, range, originalRightIndex,originalLeftIndex;
	originalLeftIndex = _leftIndex;
	originalRightIndex = _rightIndex; 
	range = _rightIndex - _leftIndex;
	_rightIndex = _middleIndex;
	for(count = _leftIndex, count2 = 0; count2 <= range; count++, count2++)
	{
		VectorGet(_vec, _leftIndex, &leftNum);
		VectorGet(_vec, _rightIndex, &rightNum);
		if((leftNum <= rightNum && _leftIndex != _middleIndex) || _rightIndex <= _leftIndex )
		{
			_tempArr[count] = leftNum; 
			_leftIndex++;
		}
		else
		{
			_tempArr[count] = rightNum;
			if(_rightIndex == originalRightIndex)
			{
				_rightIndex = _leftIndex;
				continue;
			}
			_rightIndex++;
		}
	}
	for(count = originalLeftIndex, count2 = 0; count2 <= range; count++, count2++)
	{
		VectorSet(_vec,count,_tempArr[count]);
	}
	return;
}

static void MergeRecursion(Vector* _vec, int* _tempArr, int _leftIndex, int _rightIndex)
{ 
	int middleIndex;
	if(_leftIndex == _rightIndex)
	{
		return;
	}
	middleIndex =  (_rightIndex+_leftIndex)/2 + 1;
	MergeRecursion(_vec, _tempArr, _leftIndex, middleIndex -1);
	MergeRecursion(_vec,_tempArr,middleIndex,_rightIndex);
	Merge(_vec, _tempArr, _leftIndex, _rightIndex, middleIndex);
}

ADTErr MergeSort(Vector* _vec)
{
	int vecSize;
	int* tempArr;
	if( _vec == NULL )
	{
		return ERR_NULL;
	}
	VectorGetItemsNum(_vec, &vecSize);
	tempArr = (int*)calloc(vecSize,sizeof(int));
	if (tempArr == NULL)
	{
		return ERR_ALLOCATION_FAILED;
	}
	MergeRecursion(_vec, tempArr, 0, vecSize-1);
	free(tempArr);
	return ERR_OK;
}

ADTErr CountingSort(Vector* _vec, int _range)
{
	int *tempArr,*tempArr2;
	int vecSize,count,tempItem;
	if( _vec == NULL )
	{
		return ERR_NULL;
	}
	VectorGetItemsNum(_vec, &vecSize);
	tempArr = (int*)calloc(_range,sizeof(int));
	if (tempArr == NULL)
	{
		return ERR_ALLOCATION_FAILED;
	}
	tempArr2 = (int*)calloc(vecSize,sizeof(int));
	if (tempArr2 == NULL)
	{
		free(tempArr);
		return ERR_ALLOCATION_FAILED;
	}
	for(count = 0; count < vecSize ;count++)
	{
		VectorGet(_vec, count, &tempItem);
		tempArr[tempItem]++;
	}
	for(count = 1; count < _range;count++)
	{
		tempArr[count] += tempArr[count-1];
	}
	for(count = _range-1; count > 0;count--)
	{
		tempArr[count] = tempArr[count-1];
	}
	tempArr[0] = 0;
	for(count = 0; count < vecSize;count++)
	{
		VectorGet(_vec, count, &tempItem);
		tempArr2[tempArr[tempItem]] = tempItem;
		tempArr[tempItem]++;
	}
	for(count = 0; count < vecSize;count++)
	{
		VectorSet(_vec, count, tempArr2[count]);
	}
	free(tempArr);
	free(tempArr2);
	return ERR_OK;
}

static int CountingSortForRadix(Vector* _vec, int _range, int _level)
{
	int* tempArr,*tempArr2;
	int vecSize,count,tempItem;
	VectorGetItemsNum(_vec, &vecSize);
	tempArr = (int*)calloc(_range,sizeof(int));
	if (tempArr == NULL)
	{
		return ERR_ALLOCATION_FAILED;
	}
	tempArr2 = (int*)calloc(vecSize,sizeof(int));
	if (tempArr2 == NULL)
	{
		free(tempArr);
		return ERR_ALLOCATION_FAILED;
	}
	for(count = 0; count < vecSize ;count++)
	{
		VectorGet(_vec, count, &tempItem);
		tempArr[(tempItem/_level)%10]++;
	}
	for(count = 1; count < _range;count++)
	{
		tempArr[count] += tempArr[count-1];
	}
	for(count = _range-1; count > 0;count--)
	{
		tempArr[count] = tempArr[count-1];
	}
	tempArr[0] = 0;
	for(count = 0; count < vecSize;count++)
	{
		VectorGet(_vec, count, &tempItem);
		tempArr2[tempArr[(tempItem/_level)%10]] = tempItem;
		tempArr[(tempItem/_level)%10]++;
	}
	for(count = 0; count < vecSize;count++)
	{
		VectorSet(_vec, count, tempArr2[count]);
	}
	free(tempArr);
	free(tempArr2);
	return ERR_OK;
}

ADTErr RadixSort (Vector* _vec, int _range)
{
	int count, level,vecSize;
	if( _vec == NULL )
	{
		return ERR_NULL;
	}
	VectorGetItemsNum(_vec, &vecSize);
	for (count = 0; count < _range; count++)
	{
		level = pow(10,count);
		CountingSortForRadix(_vec, _range, level);
	}
	return ERR_OK;
}
int main()
{
	int start,end,count,count2,item;
	Vector* VecPtrArr[VECTOR_COUNT];
	for (count=0;count<VECTOR_COUNT;count++)
	{
		VecPtrArr[count] = VectorCreate (VECTOR_SIZE, GENERAL_BLOCK_SIZE);
	}
	for(count = 0; count < VECTOR_SIZE; count++)
	{
		item = rand();
		for(count2=0;count2<VECTOR_COUNT;count2++)
		{
			VectorAdd (VecPtrArr[count2],item);
		}
	}

	start = clock();
	BubbleSort(VecPtrArr[0]);
	end = clock();
	printf("Time for Bubble sort: %.3f		Sort status: %d.\n",(end - start)/1000000.0, IsSorted(VecPtrArr[0]) );
	
	start = clock();
	ShakeSort(VecPtrArr[1]);
	end = clock();
	printf("Time for Shake sort: %.3f		Sort status: %d.\n",(end - start)/1000000.0,IsSorted(VecPtrArr[1]));

	start = clock();
	InsertionSort(VecPtrArr[2]);
	end = clock();
	printf("Time for Insertion sort: %.3f		Sort status: %d.\n",(end - start)/1000000.0,IsSorted(VecPtrArr[2]));

	start = clock();
	SelectionSort(VecPtrArr[6]);
	end = clock();
	printf("Time for Selection sort: %.3f		Sort status: %d.\n",(end - start)/1000000.0,IsSorted(VecPtrArr[6]));

	start = clock();
	ShellSort(VecPtrArr[3]);
	end = clock();
	printf("Time for Shell sort: %.3f		Sort status: %d.\n",(end - start)/1000000.0,IsSorted(VecPtrArr[3]));
	
	start = clock();
	QuickSortRec(VecPtrArr[4]);
	end = clock();
	printf("Time for Quick sort (Rec): %.3f	Sort status: %d.\n",(end - start)/1000000.0,IsSorted(VecPtrArr[4]));
/*TODO when quicksort id fixed this can be removed*/
/*
	start = clock();
	QuickSort(VecPtrArr[5]);
	end = clock();
	printf("Time for Quick sort (Stack): %.3f	Sort status: %d.\n",(end - start)/1000000.0,IsSorted(VecPtrArr[5]));
*/	
	
	start = clock();
	MergeSort(VecPtrArr[7]);
	end = clock();
	printf("Time for Merge sort: %.3f		Sort status: %d.\n",(end - start)/1000000.0,IsSorted(VecPtrArr[7]));
	
	VectorDestroy (VecPtrArr[8]);
	VecPtrArr[8] =  VectorCreate (LINEAR_TEMP_ARR_SIZE, GENERAL_BLOCK_SIZE);
	for(count = 0; count < LINEAR_TEMP_ARR_SIZE; count++)
	{
		item = rand()%LINEAR_TEMP_ARR_SIZE;
		VectorAdd (VecPtrArr[8],item);
	}

	start = clock();
	CountingSort(VecPtrArr[8], LINEAR_TEMP_ARR_SIZE);
	end = clock();
	printf("Time for Count sort : %.3f		Sort status: %d.\n",(end - start)/1000000.0,IsSorted(VecPtrArr[8]));

	VectorDestroy (VecPtrArr[9]);
	VecPtrArr[9] =  VectorCreate (LINEAR_TEMP_ARR_SIZE, GENERAL_BLOCK_SIZE);
	for(count = 0; count < LINEAR_TEMP_ARR_SIZE; count++)
	{
		item = rand()%LINEAR_TEMP_ARR_SIZE;
		VectorAdd (VecPtrArr[9],item);
	}
	
	start = clock();
	RadixSort(VecPtrArr[9], LINEAR_TEMP_ARR_SIZE);
	end = clock();
	printf("Time for Radix sort : %.3f		Sort status: %d.\n",(end - start)/1000000.0,IsSorted(VecPtrArr[9]));

	return 1;

}

