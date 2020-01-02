/**************************************************************************************
    Author :			Alex Katz  (alexanderk@experis.co.il)		
    Created :      		10.1.12
    Updated :			4.4.19 by Boaz
    Description : 		Message Queue over Shared Memory in multi-process interlock
***************************************************************************************/
#ifndef __MSG_QUEUE_H_
#define __MSG_QUEUE_H_
#include <stdlib.h>
typedef struct MQ MQ_t;

/* Message Queue API */
MQ_t* MsgQueueCreate (char *_msgQueueName, size_t _msgMax, size_t _memSize);  
MQ_t* MsgQueueConnect (char *_msgQueueName);
void MsgQueueDestroy (MQ_t *_msqQue);

/* Message Manupulation */
/* return number of bytes actually written, 0 if message queue full */
int MsgQueueSend (MQ_t *_msgQue, void* _buffer, size_t _length);
/* return number of bytes actually read, 0 if message queue unavailable */ 
int MsgQueueRecv (MQ_t *_msgQue, void* _buffer, size_t _size);

int IsMsgQueueEmpty (MQ_t *_msgQue);

/* Utility Functions for debugging and unit testing */
void MsgQueuePrint (MQ_t* _msgQue);

#endif /* __MSG_QUEUE_H_ */
