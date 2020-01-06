#ifndef MTQUEUE_H
#define MTQUEUE_H

#include <deque>
#include "Mutex.h"
#include "Condition.h"

template <typename T>
class MTQueue
{
public:
	MTQueue(size_t _queueSize = 0) throw (std::invalid_argument);
	void Enqueue(const T& element);
	T Dequeue();
private:
	std::deque<T> m_queue; 
	Mutex m_mutex;
	Condition m_condition;  
};

#include "MTQueue.hpp"

#endif //MTQUEUE_H



