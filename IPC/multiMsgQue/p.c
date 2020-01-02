#include "multi.h"

int main(int argC, char* argV[])
{	
	MsgBuff myMsgBuff;
	int count, msgQ, msgLen;
	char* msgList[] =  {"M1", "M2", "M3", "M4", "M5", "DONE"};
	char ident[3];
	strcpy(ident, argV[argC-1]);
	msgQ = msgget(1, ALL_PERM | IPC_CREAT);

	myMsgBuff.m_type = P_TYPE;
	if (!strcmp(ident,"P1"))
	{
		strcpy(myMsgBuff.m_text, "P0");
		msgsnd(msgQ, &myMsgBuff, strlen(ident)+1, IPC_NOWAIT);	
	}
	strcpy(myMsgBuff.m_text, ident);
	msgsnd(msgQ, &myMsgBuff, strlen(ident)+1, IPC_NOWAIT);

	for(count = 0 ; count < sizeof(msgList)/sizeof(char*); count++)
	{
		myMsgBuff.m_type = 1;
		strcpy(myMsgBuff.m_text, msgList[count]);
		msgLen = strlen(msgList[count]);
		printf("%s sends %s with type %ld \n",ident, myMsgBuff.m_text, myMsgBuff.m_type);
		msgsnd(msgQ, &myMsgBuff, msgLen + 1, IPC_NOWAIT);
		usleep(SLEEP_TIME);
	}
	
	msgrcv(msgQ, &myMsgBuff, sizeof(myMsgBuff.m_text), P_TYPE, MSG_NOERROR);
	if ( msgrcv(msgQ, &myMsgBuff, sizeof(myMsgBuff.m_text), P_TYPE, IPC_NOWAIT) == -1)
	{
		myMsgBuff.m_type = EOF_TYPE;
		msgsnd(msgQ, &myMsgBuff, strlen(ident)+1, IPC_NOWAIT);	
	}
	else
	{
		msgsnd(msgQ, &myMsgBuff, strlen(ident)+1, IPC_NOWAIT);	
	}
	
	return 1;
}
