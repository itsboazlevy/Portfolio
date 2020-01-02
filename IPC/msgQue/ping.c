#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h> 
#define ALL_PERM 0666
#define MAX_MSG_LENGTH 100
#define SLEEP_TIME 1000000

struct MsgBuff
{
	long m_type;
	char m_text[MAX_MSG_LENGTH];
};

static const char* msgList[] =  {"Message 1", "Message 2", "Message 3", "Message 4", "Message 5",
				 "Message 6", "Message 7", "Message 8", "Message 9", "Message 10",
				 "Message 11", "Message 12", "Message 13", "Message 14", "Message 15", "DONE"};
int main()
{	
	struct MsgBuff myMsgBuff;
	int count, msgQ, msgLen;
	msgQ = msgget(1, ALL_PERM | IPC_CREAT);
	
	if(msgQ == -1)
	{
		return -1;
	}
	for(count = 0 ; count < sizeof(msgList)/sizeof(char*); count++)
	{
		myMsgBuff.m_type = 1;      /* type has to be bigger than 0 in msgsnd because 0 im msgrcv is all types*/
		strcpy(myMsgBuff.m_text, msgList[count]);
		msgLen = strlen(msgList[count]);
		printf("PING SENDS %s with type %ld \n",myMsgBuff.m_text, myMsgBuff.m_type);
		if (msgsnd(msgQ, &myMsgBuff, msgLen + 1, IPC_NOWAIT) == -1)
		{
			printf("msgsnd returns -1\n");
			return -1;
		}
		if (!strcmp(myMsgBuff.m_text,"DONE"))
		{
			return 1;
		}
		usleep(SLEEP_TIME);
		if (msgrcv(msgQ, &myMsgBuff, sizeof(myMsgBuff.m_text), 2, MSG_NOERROR) == -1)
		{
			printf("msgrcv returns -1\n");
			return -1;
		}
	}

	if (msgctl(msgQ, IPC_RMID, NULL) == -1)
	{
		printf("msgctl returns -1\n");
		return -1;
	}
	return 1;
}
#endif /*_XOPEN_SOURCE*/
