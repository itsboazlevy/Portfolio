#include "multiThreadQueue.h"
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define QUEUE_MAX_SIZE 100
#define NUM_OF_P_THREADS 2
#define NUM_OF_C_THREADS 2
#define NUM_OF_THREADS (NUM_OF_P_THREADS+NUM_OF_C_THREADS)
#define NUM_OF_ITEMS 3
#define MSG_ARR_SIZE 5

struct valPac
{
	Queue* m_myQ;
	int m_nOfItems;
	int m_nOfT;
};

void* Producer(void* _myValPac)
{
	int i;
	int status;
	size_t msgArr[MSG_ARR_SIZE] = {1,2,3,4,5};
	struct valPac* pac = (struct valPac*)_myValPac;
	for (i = 0; i < pac->m_nOfItems; i++)
	{
		status = Queue_Enqueue(pac->m_myQ, (void*) msgArr[i%MSG_ARR_SIZE]);
		printf("Thread %d sent message %ld to queue. status 0 if success: %d\n",pac->m_nOfT, msgArr[i%MSG_ARR_SIZE], status);
	}
	return (void*)1;
}

void* Consumer(void* _myValPac)
{
	size_t item;
	int status;
	struct valPac* pac = (struct valPac*)_myValPac;
	while(1)
	{
		status = Queue_Dequeue(pac->m_myQ, (void**)&item);
		printf("Thread %d got message %lu from queue. status 0 if success: %d\n",pac->m_nOfT, item, status);		
	}
	return (void*)1;
}

int main()
{
	size_t i;
	struct valPac myValPac[NUM_OF_THREADS];
	pthread_t thread_id[NUM_OF_THREADS]; 
	Queue* myQ = Queue_Create(QUEUE_MAX_SIZE);
	
	/* producer threads creation */
	for (i = 0; i<NUM_OF_P_THREADS; i++)
	{
		myValPac[i].m_myQ = myQ;
		myValPac[i].m_nOfItems = NUM_OF_ITEMS;
		myValPac[i].m_nOfT = i;
	    pthread_create(&thread_id[i], NULL, Producer, (void*)&myValPac[i]); 
	}
	
	/* consumer threads creation */
	for (i = NUM_OF_P_THREADS; i<NUM_OF_THREADS; i++)
	{
		myValPac[i].m_myQ = myQ;
		myValPac[i].m_nOfT = i;
		pthread_create(&thread_id[i], NULL, Consumer, (void*)&myValPac[i]); 
	}
	
	/* allow threads to execute before destruction */
	sleep(3);
	
	/* threads release */
	for (i = 0; i<NUM_OF_P_THREADS; i++)
	{
		pthread_join(thread_id[i],NULL);
	}
	sleep(3);\
	
	Queue_Destroy(&myQ,NULL); 


	for (i = NUM_OF_P_THREADS; NUM_OF_P_THREADS<NUM_OF_C_THREADS; i++)
	{
		pthread_join(thread_id[i],NULL);
	}

	return 1;
}

