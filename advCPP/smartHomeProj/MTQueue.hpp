template <typename T>
MTQueue<T>::MTQueue(size_t _queueSize) throw (std::invalid_argument)
{

}

template <typename T>
void MTQueue<T>::Enqueue(const T& element)
{
	m_mutex.Lock();
	try
	{
		m_queue.push_back(element);
	}
	catch(...)
	{
		m_mutex.Unlock();
		throw;
	}
	m_condition.Signal();
	m_mutex.Unlock();
}

template <typename T>
T MTQueue<T>::Dequeue()
{
	m_mutex.Lock();
	while ( m_queue.empty() )
	{
		m_condition.Wait(m_mutex);
	}
	T retVal = m_queue.front();
	try
	{
		m_queue.pop_front();
	}
	catch(...)
	{
		m_mutex.Unlock();
		throw;
	}
	m_mutex.Unlock();
	return retVal;
}
