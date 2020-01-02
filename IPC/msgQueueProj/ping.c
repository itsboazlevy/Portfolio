#include "MsgQueue.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct valPac valPac;
struct valPac
{
	int m_sleepT;
	int m_msgsNum;
	int m_capOfMsgs;
	int m_memSize;
};

int Ping(valPac* _valPac)
{
	MQ_t* messageMQ;
	MQ_t* handshakeMQ;
	char sendBuffer[10] = "PING MSG!";
	char recvBuffer[10];
	/* MQs creation */
	messageMQ = MsgQueueCreate ("MQping.txt", _valPac->m_capOfMsgs, _valPac->m_memSize);  
	handshakeMQ = MsgQueueCreate ("MQpong.txt", _valPac->m_capOfMsgs, _valPac->m_memSize);
	MsgQueueRecv (handshakeMQ, (void*) recvBuffer, 10);
	/* 	write msgs to msgQ, check handshakeQ for more pongs, increase msg amount accordingly, 
		when finished wait for bye bye signal, flag destruction and destroy all 				*/
	return 1;
}

int main(int argc, char** argv)
{
	FILE* filePtr;
	int i = 1;
	/* default valPac initialization */
	valPac myValPac;
	myValPac.m_sleepT = 2;
	myValPac.m_msgsNum = 24;
	myValPac.m_capOfMsgs = 200;
	myValPac.m_memSize = 3000;

	/* command line variables input */
	while ( i < argc)
	{
		switch (argv[i][0])
		{
			case '-':
				switch (argv[i][1])
				{
					case 's': myValPac.m_sleepT = atoi(&argv[i][2]);
							  break;
					case 'm': myValPac.m_msgsNum = atoi(&argv[i][2]);
							  break;
					case 'M': myValPac.m_memSize = atoi(&argv[i][2]);
							  break;
					case 'c': myValPac.m_capOfMsgs = atoi(&argv[i][2]);
				}
		}
		i++;
	}
	
	/* files initialization for ftok */
	filePtr = fopen("MQping.txt","w+");
	fprintf(filePtr,"initialise");
	fclose(filePtr);
	filePtr = fopen("MQpong.txt","w+");
	fprintf(filePtr,"initialise");
	fclose(filePtr);
	
	Ping(&myValPac);
	return 1;
}

