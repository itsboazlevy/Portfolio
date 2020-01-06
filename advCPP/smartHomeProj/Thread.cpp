#include "Thread.h"

Thread::Thread(Runnable *prun)
{
	pthread_create(&m_thread, 0, ThreadFunc, prun);
}

void Thread::Join() 
{
		pthread_join(m_thread, 0);
}


