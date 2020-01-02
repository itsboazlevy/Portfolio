#ifndef __ADproj_h__
#define __ADproj_h__
#include <stdlib.h>
#include <stdio.h>

typedef enum {NULL_ERR, SUCCESS, ALLOC_ERR, ROOM_ERR, TIME_ERR, LENGTH_ERR, OVERLAP_ERR, REALLOC_ERR, NO_SUCH_AP_ERR} ERRList;
typedef struct ApDiary ApDiary;
typedef struct Ap Ap;

/* 
Description: allocates memory for a new appointment diary
Input: size of Appointments pointers list
Output: NULL if creation failed
	pointer to AD structure
*/
ApDiary* CreateApDiary(size_t _size);

/* 
destroys AD makes pointer to AD null to allow recreation and not allow double destruction
input: pointer to struct AD
output: status
*/
ERRList DestroyApDiary(ApDiary* _myApDiary);

/* 
Description: allocates memory to new A creation, Checks if given details are valid, if valid checks there is no overlap - if there is frees memory
allocates more memory in list of appointments, inserts created A, increases num of A, frees memory, sorts listOfA
Input: pointer to struct AD
Output: status
*/
ERRList CreateAp(ApDiary* _myApDiary,float _startTime,float _endTime,int _roomNum);

/* 
Description: prints list of possible user commands
input: none
output: none
*/
void PrintCommands();

/* 
Description: prints AD if exists
input: pointer to struct AD
output: status
*/
void PrintApDiary(ApDiary* _myApDiary);

/* 
Description: checks A exists by startTime
input: start time, pointer to struct AD
output: status
*/
ERRList FindAp(ApDiary* _myApDiary,float _givenStartTime);

/* 
Description: check A exist by startTime, if exist swaps it to end of list and reallocates memory + updates numOfA to remove it.
input: pointer to struct AD, start time
output: status
*/
ERRList removeA(ApDiary* _myApDiary,float _givenStartTime);

/* 
Description: Saves the appointment diary.
input: pointer to struct AD.
output: status
*/
ERRList SaveApDiary(ApDiary* _myApDiary);

/* 
Description: Loads the appointment diary.
input: pointer to struct AD.
output: status
*/
ERRList LoadApDiary(ApDiary* _myApDiary);

#endif /*__ADproj_h__*/
