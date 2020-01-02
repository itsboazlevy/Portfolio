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

int main()
{	
	struct MsgBuff myMsgBuff;
	int msgQ;
	msgQ = msgget(1, ALL_PERM | IPC_CREAT);
	myMsgBuff.m_type = 2;
	if(msgQ == -1)
	{
		return -1;
	}
	while(1)
	{
		if ( msgrcv(msgQ, &myMsgBuff, sizeof(myMsgBuff.m_text), 1, MSG_NOERROR) == -1)
		{
			printf("msgrcv returns -1\n");
			return -1;
		}
		printf("PONG RECIEVED %s with type %ld \n",myMsgBuff.m_text, myMsgBuff.m_type);
		if (!strcmp(myMsgBuff.m_text,"DONE"))
		{
			return 1;
		}
		myMsgBuff.m_type = 2;
		if(msgsnd(msgQ, &myMsgBuff, sizeof(myMsgBuff.m_text), IPC_NOWAIT) == -1)
		{
			printf("msgsnd returns -1\n");
			return -1;
		}
		usleep(SLEEP_TIME);
	}
}
#endif /*_XOPEN_SOURCE*/
