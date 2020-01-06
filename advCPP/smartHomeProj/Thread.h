#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>
#include "Runnable.h"

class Thread 
{
public:
	Thread(Runnable* prun);
	void Join();
private:
	static void* ThreadFunc(void* arg)
	{
		Runnable* runner =  static_cast<Runnable*>(arg);
		runner->Run();
		return 0;
	}
	pthread_t m_thread;
};

#endif //THREAD_H
