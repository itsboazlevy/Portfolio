#include <assert.h>
#include "Condition.h"

Condition::Condition() throw (std::invalid_argument)
{	
	if ( pthread_cond_init(&m_condition, NULL) != 0 )
	{
		throw std::invalid_argument("Cond Init Failure");
	}
}

Condition::~Condition()
{	
	if ( pthread_cond_destroy(&m_condition) != 0 )
	{
		assert("Cond Destr Failure");
	}
}

void Condition::Wait(Mutex& _mutex)
{
	pthread_cond_wait(&m_condition,&(_mutex.m_mutex));   
}

void Condition::Signal()
{
	pthread_cond_signal(&m_condition);
}



