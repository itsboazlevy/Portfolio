#include "Mutex.h"
#include <assert.h> 

Mutex::Mutex() throw (std::invalid_argument)
{	
	if ( pthread_mutex_init(&m_mutex, NULL) != 0)
	{
		throw std::invalid_argument("Mutex Init Failure");
	}
}

Mutex::~Mutex()
{	
	if (pthread_mutex_destroy(&m_mutex) != 0)
	{
		assert("Mutex Destr Failure");
	}
}

void Mutex::Lock()
{	
	pthread_mutex_lock(&m_mutex);
}

void Mutex::Unlock()
{	
	pthread_mutex_unlock(&m_mutex);
}


