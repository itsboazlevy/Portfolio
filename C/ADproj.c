#include "ADproj.h"
#include <stdlib.h>
#include <stdio.h>

#define MAGIC_NUM 1234567890
#define MAX_ROOM_NUM 20
#define MIN_ROOM_NUM 1
#define MAX_TIME 24
#define MIN_TIME 0 
#define BLOCK_SIZE 2 

struct ApDiary
{
	Ap** m_listOfApPtr; 
	int m_numOfAp;
	size_t m_size; 
	int m_magicNum; 
};

struct Ap
{
	float m_startTime;
	float m_endTime;
	int m_roomNum;
};

ApDiary* CreateApDiary(size_t _size)
{
	ApDiary* myApDiary;
	myApDiary = (ApDiary*)malloc(sizeof(ApDiary));
	if (myApDiary == NULL)
	{
		return NULL;
	}
	myApDiary->m_listOfApPtr = (Ap**)malloc(sizeof(Ap*)*_size);	
	if (myApDiary->m_listOfApPtr == NULL)
	{	
		free (myApDiary);
		return NULL;
	}
	myApDiary->m_numOfAp = 0;
	myApDiary->m_size = _size;
	myApDiary->m_magicNum = MAGIC_NUM;
	return myApDiary;
}

ERRList DestroyApDiary(ApDiary* _myApDiary)
{
	size_t count;
	if (_myApDiary == NULL || _myApDiary->m_magicNum != MAGIC_NUM)
	{
		return NULL_ERR;	
	}
	count = 0;
	while (count < _myApDiary->m_numOfAp)
	{
		free(_myApDiary->m_listOfApPtr[count]);
		count++;
	}
	_myApDiary->m_numOfAp = 0;
	_myApDiary->m_magicNum = 0;
	free(_myApDiary->m_listOfApPtr);
	free(_myApDiary);
	return SUCCESS;
}

ERRList CheckApDetails(Ap* _myApPtr)
{
	if (_myApPtr->m_roomNum > MAX_ROOM_NUM || _myApPtr->m_roomNum < MIN_ROOM_NUM)
	{
		return ROOM_ERR;
	}
	if (_myApPtr->m_startTime < MIN_TIME || _myApPtr->m_startTime >= MAX_TIME || _myApPtr->m_endTime < MIN_TIME || _myApPtr->m_endTime >= MAX_TIME)
	{
		return TIME_ERR;
	}
	if (_myApPtr->m_startTime >= _myApPtr->m_endTime)
	{
		return LENGTH_ERR;
	}
	return SUCCESS;
}

/*
this function checks overlaps, returns -1 if there is overlap. 
if no overlap exists it returns a number which represents the right sorted location for the Appointment
*/
int OverlapCheckSort(ApDiary* _myApDiary, Ap* _myApPtr)
{
	int count;
	for (count=0; count < (_myApDiary->m_numOfAp); count++)
	{
		if ((_myApPtr->m_startTime) >= (*(_myApDiary->m_listOfApPtr) + count)->m_endTime)
		{
			continue;
		}
		if ((_myApPtr->m_endTime) > (*(_myApDiary->m_listOfApPtr) + count)->m_startTime)
		{
			return -1;
			break;
		}
		break;
	}  
	return count;
}

ERRList InsertAp(ApDiary* _myApDiary, Ap* _myApPtr)
{
	int count;
	int overlapCheckSortResult = OverlapCheckSort(_myApDiary, _myApPtr);
	if(overlapCheckSortResult == -1)
	{
		return OVERLAP_ERR;	
	}
	if (_myApDiary->m_size == _myApDiary->m_numOfAp)
	{
		_myApDiary->m_listOfApPtr = (Ap**)realloc(_myApDiary->m_listOfApPtr,sizeof(Ap*)*(_myApDiary->m_size + BLOCK_SIZE));
		_myApDiary->m_size += BLOCK_SIZE;	
	}
	if (_myApDiary->m_listOfApPtr == NULL)
	{	
		return REALLOC_ERR;
	}
	for (count = _myApDiary->m_numOfAp - 1; count >= overlapCheckSortResult; count--)
	{
		*(*_myApDiary->m_listOfApPtr +count +1 ) = *(*_myApDiary->m_listOfApPtr +count);
	}
	*(_myApDiary->m_listOfApPtr + overlapCheckSortResult) = _myApPtr;
	_myApDiary->m_numOfAp++;
	return SUCCESS;	
}

ERRList CreateAp(ApDiary* _myApDiary,float _startTime,float _endTime,int _roomNum)
{
	int CheckApDetailsResult;
	int InsertApResult;
	Ap* myApPtr;
	if (_myApDiary == NULL || _myApDiary->m_magicNum != MAGIC_NUM)
	{
		return NULL_ERR;	
	}
	myApPtr = *(_myApDiary->m_listOfApPtr) + _myApDiary->m_numOfAp;
	myApPtr = (Ap*)malloc(sizeof(struct Ap)); 
	if (myApPtr == NULL)
	{
		return ALLOC_ERR;
	}
	myApPtr->m_startTime = _startTime;
	myApPtr->m_endTime = _endTime;
	myApPtr->m_roomNum = _roomNum;
	CheckApDetailsResult = CheckApDetails(myApPtr);
	if(CheckApDetailsResult != SUCCESS)
	{
		free(myApPtr);
		return CheckApDetailsResult;
	}
	InsertApResult = InsertAp(_myApDiary, myApPtr);
	if(InsertApResult != SUCCESS)
	{
		free(myApPtr);
		return InsertApResult;
	}
	return SUCCESS;
}

void PrintCommands()
{
	printf("List of commands:\n");
	printf("Create Appointment Diary - c\n");
	printf("Create Appointment - a\n");
	printf("Destroy Appointment Diary - d\n");
	printf("Print Appointment Diary  - p\n");
	printf("Remove Appointment - r\n");
	printf("Search Appointment - f\n");
	printf("Save Appointment Diary - s\n");
	printf("Load Appointment Diary - l\n");
	printf("Print Commands - x\n");
	printf("Quit - q\n\n");
}

ERRList removeA(ApDiary* _myApDiary, float _givenStartTime)
{
	int count;
	int flag;
	if (_myApDiary == NULL || _myApDiary->m_magicNum != MAGIC_NUM)
	{
		return NULL_ERR;	
	}
	flag = 0;
	for(count = 0; count < _myApDiary->m_numOfAp; count++)
	{
		if (_givenStartTime == _myApDiary->m_listOfApPtr[count]->m_startTime)
		{
			_myApDiary->m_listOfApPtr[count] = _myApDiary->m_listOfApPtr[count+1];
			flag = 1;
		}
	}
	if (flag == 0)
	{
		return NO_SUCH_AP_ERR;
	}
	_myApDiary->m_listOfApPtr = (Ap**)realloc(_myApDiary->m_listOfApPtr,sizeof(Ap*)*(_myApDiary->m_size -1));
	if (_myApDiary->m_listOfApPtr == NULL)
	{	
		return REALLOC_ERR;
	}
	_myApDiary->m_size--;
	_myApDiary->m_numOfAp--;
	return SUCCESS;
}

ERRList FindAp(ApDiary* _myApDiary,float _givenStartTime)
{
	int count;
	if (_myApDiary == NULL || _myApDiary->m_magicNum != MAGIC_NUM)
	{
		return NULL_ERR;	
	}
	for(count= _myApDiary->m_numOfAp -1; count >= 0; count--)
	{
		if (_givenStartTime == ( *(_myApDiary->m_listOfApPtr)+count)->m_startTime)
		{
			return SUCCESS;
		}
	}
	return NO_SUCH_AP_ERR;
}

void PrintApDiary(ApDiary* _myApDiary)
{
	int count;
	if (_myApDiary == NULL || _myApDiary->m_magicNum != MAGIC_NUM)
	{
		printf("no Appointment Diary in memory, create yours now!\n");	
		return;
	}
	printf("----Appointments Diary for Today----\n");
	printf("Number of Appointments: %d\n", _myApDiary->m_numOfAp);
	printf("Size Allocated for Appointments: %ld\n", _myApDiary->m_size);
	for(count=0; count < _myApDiary->m_numOfAp; count++)
	{
		printf("\nAppointment #%d\n",count+1);
		printf("Starts at: %.2f\n",_myApDiary->m_listOfApPtr[count]->m_startTime);
		printf("Ends at: %.2f\n",_myApDiary->m_listOfApPtr[count]->m_endTime);
		printf("Room: %d\n",_myApDiary->m_listOfApPtr[count]->m_roomNum);
	}
	return;
}

ERRList SaveApDiary(ApDiary* _myApDiary)
{
	FILE* fptr;
	int count;
	fptr = fopen("ADsave.txt","w");
	if (fptr == NULL)
	{
		return NULL_ERR;
	}
	count = _myApDiary->m_numOfAp;
	fprintf(fptr,"%d\n",count);
	for (count = 0; count < _myApDiary->m_numOfAp; count++)
	{
		fprintf(fptr,"%.2f   %.2f   %d\n",_myApDiary->m_listOfApPtr[count]->m_startTime,_myApDiary->m_listOfApPtr[count]->m_endTime,_myApDiary->m_listOfApPtr[count]->m_roomNum);
	}
	fclose(fptr);
	return SUCCESS;		
}

ERRList LoadApDiary(ApDiary* _myApDiary)
{
	FILE* fptr;
	int count;
	int index;
	float startTime;
	float endTime;
	int roomNum;
	fptr = fopen("ADsave.txt","r");
	if (fptr == NULL)
	{
		return NULL_ERR;
	}
	fscanf(fptr,"%d",&count);
	CreateApDiary(5);
	for(index = 0; index < count; index++)
	{
		fscanf(fptr,"%f%f%d",&(startTime),&(endTime),&(roomNum));
		CreateAp(_myApDiary,startTime,endTime,roomNum);
	}
	fclose(fptr);
	return SUCCESS;		
}

