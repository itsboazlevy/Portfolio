/* when executing add flags. out file - P# / C#, start from 1 example: ./a.out P1 */

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
#define SLEEP_TIME 1000000
#define P_TYPE 10
#define C_TYPE 20
#define EOF_TYPE 30

typedef struct MsgBuff MsgBuff;

struct MsgBuff
{
	long m_type;
	char m_text[100];
};

#endif /*_XOPEN_SOURCE*/
