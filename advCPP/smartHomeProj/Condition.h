#ifndef CONDITION_H
#define CONDITION_H

#include <stdexcept>
#include <pthread.h>
#include "Mutex.h"

class Condition
{
public:
	Condition() throw (std::invalid_argument);
	~Condition();
	void Wait(Mutex& _mutex);
	void Signal();
private:
	pthread_cond_t m_condition;
};

#endif //CONDITION_H
