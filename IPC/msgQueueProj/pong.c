#include "MsgQueue.h"
#include <stdlib.h>
#include <stdio.h>

int Pong(int _sleepT)
{
	MQ_t* messageMQ;
	MQ_t* handshakeMQ;
	char sendBuffer[10] = "PONG MSG!";
	char recvBuffer[10];
	messageMQ = MsgQueueConnect ("MQping.txt");
	handshakeMQ = MsgQueueConnect ("MQpong.txt");
	MsgQueueSend (handshakeMQ, (void*) sendBuffer, 10);
	/* 	wait for msgs in msgQ, read them as they appear until no more, 
		propogate bye bye signal and self destruct, last signal to ping */
	return 1;
}

int main(int argc, char** argv)
{
	int i = 1;
	int sleepT = 2;

	/* command line sleepT input */
	while ( i < argc)
	{
		switch (argv[i][0])
		{
			case '-':
				switch (argv[i][1])
				{
					case 's': sleepT = atoi(&argv[i][2]);
							  break;
				}
		}
		i++;
	}
	Pong(sleepT);
	return 1;
}

