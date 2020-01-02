#include <pthread.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <string.h> 
#define NUM_OF_READERS 3
#define READ_MAX_SIZE 100
#define NUM_OF_ITERATIONS 5
pthread_mutex_t mutex;
pthread_cond_t cond;
volatile int rFlag;
volatile int wFlag;
char scanBuff[100];

void* Reader (void* _args)
{	
	pthread_mutex_lock(&mutex);
	++rFlag;
	pthread_mutex_unlock(&mutex);
	pthread_cond_signal(&cond);
	
	pthread_mutex_lock(&mutex);
	while (wFlag)
	{
        pthread_cond_wait(&cond, &mutex);
	}
	printf("Reader number %ld reads %s\n",(size_t)_args, scanBuff);
	pthread_mutex_unlock(&mutex);
	return (void*)1;
}

void* Writer (void* _args)
{	
	
	pthread_mutex_lock(&mutex);
	while (rFlag)
	{
        pthread_cond_wait(&cond, &mutex);   
	}
	pthread_mutex_unlock(&mutex);
	
	pthread_mutex_lock(&mutex);
	memset(scanBuff,'a',READ_MAX_SIZE-1);
	++wFlag;
	pthread_mutex_unlock(&mutex);
	pthread_cond_broadcast(&cond);
	
	return (void*)1;
}

int main()
{	
	size_t i,j;
	pthread_t readID[NUM_OF_READERS];
	pthread_t writeID;

	for (j=0; j< NUM_OF_ITERATIONS; j++)
	{
		rFlag = 0;
		wFlag = 0;
		/* initialises threads */
		pthread_create(&writeID, NULL, Writer, NULL); 
		for (i=0;i<NUM_OF_READERS;i++)
		{
				pthread_create(&readID[i], NULL, Reader, (void*)i); 
		}
	
		/* terminates threads */
		pthread_join(writeID,NULL);
		for (i=0;i<NUM_OF_READERS;i++)
		{
			pthread_join(readID[i],NULL);
		}
	}
	pthread_mutex_destroy(&mutex);
	return 1;
}

