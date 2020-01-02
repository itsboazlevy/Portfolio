#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include "MsgQueue.h"
#include "MyMalloc.h"
#include "cyclicQueue.h"
#define SHM_MIN_SIZE 2000
#define RW_PERM 0666

struct MQ
{
	Queue* m_queue;
	void* m_mesData;
	int m_memSize;
	pthread_mutex_t m_mutex;
	pthread_cond_t m_cond;
};

MQ_t* MsgQueueCreate (char* _msgQueueName, size_t _msgMax, size_t _memSize)
{       
	int mqID;
	MQ_t* mqPtr;
	key_t myKey;
	/* minimum size requirement */
	if (_memSize < SHM_MIN_SIZE)
	{
		return NULL;
	}
	/* generates key based on given MQ name */
	myKey = ftok(_msgQueueName, 0);
	if ( errno != 0)
	{
		printf ("ftok error : %s\n",strerror(errno));
		return NULL;
	} 
	/* allocates SHM segment by given size */
	mqID = shmget(myKey, _memSize, IPC_CREAT | RW_PERM );
	if ( errno != 0)
	{
		printf ("shmget error : %s\n",strerror(errno));
		return NULL;
	} 
	/* attaches pointer to SHM segment */
	mqPtr = (MQ_t*)shmat(mqID, NULL, 0);
	if ( errno != 0)
	{
		printf ("shmat error : %s\n",strerror(errno));
		return NULL;
	} 
	/* initialize struct MQ at start of SHM */
	mqPtr->m_memSize = _memSize;
	mqPtr->m_queue = (Queue*)((char*)mqPtr + sizeof(MQ_t));
	mqPtr->m_mesData = (void*)((char*)(mqPtr->m_queue) + Queue_Size(mqPtr->m_queue));
	pthread_mutex_init(&(mqPtr->m_mutex), NULL);
	pthread_cond_init(&(mqPtr->m_cond), NULL);
	/* initialize Queue at matching offset */
	Queue_Init(_msgMax,mqPtr->m_queue);
	/* initialize Message Data at matching offset */
	MyMallocInit(mqPtr->m_mesData, _memSize - sizeof(MQ_t) - Queue_Size(mqPtr->m_queue));
	return mqPtr; 
}

MQ_t* MsgQueueConnect (char *_msgQueueName)
{
	int mqID;
	MQ_t* mqPtr;
	key_t myKey;
	myKey = ftok(_msgQueueName, 0);
	mqID = shmget(myKey, 0, RW_PERM);	
	mqPtr = (MQ_t*)shmat(mqID, NULL, 0);
	return mqPtr;	
}

void MsgQueueDestroy (MQ_t *_msqQue)
{		
	pthread_mutex_destroy(&(_msqQue->m_mutex));
	pthread_cond_destroy(&(_msqQue->m_cond));
	shmdt(_msqQue);
	return;
}

int MsgQueueSend (MQ_t *_msgQue, void* _buffer, size_t _length)
{
	void* msgPtr;
	/* allocates chunk of memory for message data, if no more space return 0 */
	pthread_mutex_lock(&(_msgQue->m_mutex));
	msgPtr = MyMalloc(_msgQue->m_mesData, _length);
	if (msgPtr == NULL)
	{
		return 0;
	}
	/* copy message to allocated space */
	memcpy(msgPtr, _buffer, _length);
	/* insert message pointer into queue, if no more space return 0 */
	if (Queue_Enqueue(_msgQue->m_queue, msgPtr) == QUEUE_OVERFLOW)
	{
		MyFree(msgPtr);
		return 0;
	}
	pthread_cond_broadcast(&(_msgQue->m_cond));
	pthread_mutex_unlock(&(_msgQue->m_mutex));
	return _length;	
}

int MsgQueueRecv (MQ_t *_msgQue, void* _buffer, size_t _size)
{
	void* msgPtr;
	pthread_mutex_lock(&(_msgQue->m_mutex));
	while ( Queue_IsEmpty((const Queue*)_msgQue) )
	{
		pthread_cond_wait(&(_msgQue->m_cond),&(_msgQue->m_mutex));
	}
	if (Queue_Dequeue(_msgQue->m_queue, &msgPtr) != QUEUE_SUCCESS)
	{
		return 0;
	}
	memcpy(_buffer, msgPtr, _size);
	MyFree(msgPtr);
	pthread_mutex_unlock(&(_msgQue->m_mutex));
	return _size;
}

int	IsMsgQueueEmpty (MQ_t *_msgQue)
{
	return Queue_IsEmpty(_msgQue->m_queue);
}

static int PrintAction (void* _element, size_t _index, void* _context)
{
	printf("%s\n",(char*)_element);
	return 1;
}

void MsgQueuePrint (MQ_t* _msgQue)
{
	Queue_ForEach(_msgQue->m_queue,PrintAction, NULL);
}
