/*	
This application allows you to create a daily appointment diary
Written by BL 10.2
*/ 
#include <stdio.h>
#include "ADproj.h"

int main()
{
	char userCommand;
	ERRList status;
	float giventime;
	float findTime;
	float startTime;
	float endTime;
	int roomNum;
	ApDiary* userPtr = NULL;
	PrintCommands();
	while(1)
	{
		userCommand = getchar();
		switch(userCommand)
		{
		case 'c':	userPtr=CreateApDiary(5);
					printf("\n Given Pointer Address: %p\n",(void*)userPtr);	
					break;
		case 'd':	status = DestroyApDiary(userPtr);
					printf("\n Status: %d\n",status);
					break;
		case 'a': 	if (userPtr==NULL)
					{
						printf("no Appointment Diary in memory, create yours now!\n");
						break;	
					}
					printf("\nCreate a new meeting!\nEnter Start Time, End Time and Room Number:\n");
					scanf("%f%f%d",&startTime,&endTime,&roomNum);
					status = CreateAp(userPtr,startTime,endTime,roomNum);
					printf("\n Status: %d\n",status);
					break;
		case 'p':	PrintApDiary(userPtr);
					break;
		case 'r':	printf("Enter Start Time of your Appointment\n");
					scanf("%f",&giventime);
					status = removeA(userPtr, giventime);
					printf("\n Status: %d\n",status);
					break;
		case 'f':	printf("Enter Start Time of your Appointment\n");
					scanf("%f",&findTime);
					status = FindAp(userPtr, findTime);
					printf("\n Status: %d\n",status);
					break;
		case 'x':	PrintCommands();
					break;
		case 'q':	printf("\nGoodBye!\n");
					return 1;
		case '\n': 	break;
		case 's':	status=SaveApDiary(userPtr);
					printf("\n Status: %d\n",status);
					break;
		case 'l':	status=LoadApDiary(userPtr);
					printf("\n Status: %d\n",status);
					break;
		default:	printf("\nNo Such Command, for list of commands enter x\n");
					break;
		}
	
	}
}



