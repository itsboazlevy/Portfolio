#include "cyclicQueue.h"
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define QUEUE_MAX_SIZE 100
#define NUM_OF_P_THREADS 2
#define NUM_OF_C_THREADS 2
#define NUM_OF_THREADS (NUM_OF_P_THREADS+NUM_OF_C_THREADS)
#define NUM_OF_ITEMS 3
#define MSG_ARR_SIZE 5

/* same values for all threads */
struct sameVals
{
	Queue* m_myQueue;
	pthread_mutex_t m_mutex;
	sem_t m_semFull;
	sem_t m_semEmpty;	
};

struct valPac
{
	struct sameVals* m_mySameVals; 
	int m_nOfItems;
	int m_nOfT;
};

void* Producer(void* _myValPac)
{
	int i;
	size_t msgArr[MSG_ARR_SIZE] = {1,2,3,4,5};

	for (i = 0; i < ((struct valPac*)_myValPac)->m_nOfItems; i++)
	{
		sem_wait(&(((struct valPac*)_myValPac)->m_mySameVals->m_semEmpty));
		pthread_mutex_lock(&(((struct valPac*)_myValPac)->m_mySameVals->m_mutex));
		Queue_Enqueue(((struct valPac*)_myValPac)->m_mySameVals->m_myQueue, (void*) msgArr[i%MSG_ARR_SIZE]);
		printf("Thread %d sent message %ld to queue\n",((struct valPac*)_myValPac)->m_nOfT, msgArr[i%MSG_ARR_SIZE]);
		sem_post(&(((struct valPac*)_myValPac)->m_mySameVals->m_semFull));
		pthread_mutex_unlock(&(((struct valPac*)_myValPac)->m_mySameVals->m_mutex));
	}
	return (void*)1;
}

void* Consumer(void* _myValPac)
{
	size_t item;
	while(1)
	{
		sem_wait(&(((struct valPac*)_myValPac)->m_mySameVals->m_semFull));
		pthread_mutex_lock(&(((struct valPac*)_myValPac)->m_mySameVals->m_mutex));
		Queue_Dequeue(((struct valPac*)_myValPac)->m_mySameVals->m_myQueue, (void**)&item);
		printf("Thread %d got message %lu from queue\n",((struct valPac*)_myValPac)->m_nOfT, item);		
		pthread_mutex_unlock(&(((struct valPac*)_myValPac)->m_mySameVals->m_mutex));
		sem_post(&(((struct valPac*)_myValPac)->m_mySameVals->m_semEmpty));
	}
	return (void*)1;
}

int main()
{
	size_t i;
	struct valPac myValPac[NUM_OF_THREADS];
	struct sameVals mySameVals;
	pthread_t thread_id[NUM_OF_THREADS]; 
	
	/* common vals initialization */
	mySameVals.m_myQueue = Queue_Create(QUEUE_MAX_SIZE);
	sem_init(&(mySameVals.m_semFull), 0, 0);
	sem_init(&(mySameVals.m_semEmpty), 0, QUEUE_MAX_SIZE);
	pthread_mutex_init(&(mySameVals.m_mutex), NULL);
	
	/* producer threads creation */
	for (i = 0; i<NUM_OF_P_THREADS; i++)
	{
		myValPac[i].m_mySameVals = &mySameVals;
		myValPac[i].m_nOfItems = NUM_OF_ITEMS;
		myValPac[i].m_nOfT = i;
	    pthread_create(&thread_id[i], NULL, Producer, (void*)&myValPac[i]); 
	}
	
	/* consumer threads creation */
	for (i = NUM_OF_P_THREADS; i<NUM_OF_THREADS; i++)
	{
		myValPac[i].m_mySameVals = &mySameVals;
		myValPac[i].m_nOfT = i;
		pthread_create(&thread_id[i], NULL, Consumer, (void*)&myValPac[i]); 
	}
	
	/* let threads finish */
	sleep(1);
	
	/* producer memory release */
	for (i = 0; i<NUM_OF_P_THREADS; i++)
	{
		pthread_join(thread_id[i],NULL);
	}
	
	/* consumer thread deletion and memory release */
	for (i = NUM_OF_P_THREADS; i<NUM_OF_C_THREADS; i++)
	{
		pthread_cancel(thread_id[i]);
		pthread_join(thread_id[i],NULL);
	}
	
	return 1;
}

