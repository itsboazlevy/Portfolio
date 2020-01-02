#include "multi.h"

int main()
{	
	MsgBuff myMsgBuff;
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
		printf("C1 RECIEVED %s with type %ld \n",myMsgBuff.m_text, myMsgBuff.m_type);
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
