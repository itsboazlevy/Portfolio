#ifndef MUTEX_H
#define MUTEX_H

#include <stdexcept>
#include <pthread.h>

class Condition;

class Mutex
{
	friend class Condition;
public:
	Mutex() throw (std::invalid_argument);
	~Mutex(); 
	void Lock();
	void Unlock();
private:
	pthread_mutex_t m_mutex;
};

#endif //MUTEX_H
