#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h> 
  
void *myThreadFun(void * i) 
{ 
    printf("thread %ld prints thread ID: %p \n",(size_t)i, (void*)pthread_self());  
    return NULL; 
} 
   
int main() 
{ 
	size_t i;
	pthread_t thread_id1; 
	printf("Before Threads\n"); 
	for (i = 0; i<50; i++)
	{
	    pthread_create(&thread_id1, NULL, myThreadFun, (void*)i); 
	    
	}
	sleep(1);
	printf("After Threads\n"); 
	exit(0);
}

