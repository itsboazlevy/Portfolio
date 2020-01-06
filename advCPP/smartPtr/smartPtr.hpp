#include "smartPtr.h"

template <typename T>
AtomicCounter<T>::AtomicCounter(T _count)
: m_count(_count) //init atomically
{
	__sync_add_and_fetch(&m_count,_count);
}

template <typename T>
T& AtomicCounter<T>::operator++()
{
	return __sync_add_and_fetch(&m_count,T(1));
}

template <typename T>
T AtomicCounter<T>::operator++(T)
{
	return __sync_fetch_and_add(&m_count,T(1));
}


template <typename T>
T& AtomicCounter<T>::operator--()
{
	return __sync_sub_and_fetch(&m_count,T(1));
}

template <typename T>
T AtomicCounter<T>::operator--(T)
{
	return __sync_fetch_and_add(&m_count,T(1));
}

/////////////////////////////////////////////////////////////

template <typename T, typename C>
SmartPointer<T,C>::SmartPointer(T* _ptr)
:m_ptr(_ptr)
{
	m_acPtr = new C(1);
}

template <typename T, typename C>
SmartPointer<T,C>::~SmartPointer()
{
	if(--*m_acPtr == 0)
	{
		delete m_ptr;
		delete m_acPtr;
	}
}


template <typename T, typename C>
SmartPointer<T,C>::SmartPointer(const SmartPointer<T,C>& _ref)
: m_acPtr(_ref.m_acPtr)
, m_ptr(_ref.m_ptr)
}
	++*m_acPtr;
}

template <typename T, typename C>
SmartPointer<T,C>& SmartPointer<T,C>::operator=(const SmartPointer& _ref)
{
	if (this != &_ref)
	{
		if(--*m_acPtr == 0)
		{
			delete m_ptr;
			delete m_acPtr;
		}
	m_acPtr = _ref.m_acPtr;
	m_ptr = _ref.m_ptr;
	++*m_acPtr;
	}
}

template <typename T, typename C>
T& SmartPointer<T,C>::operator*()
{
	return *m_acPtr;
}

template <typename T, typename C>
T* SmartPointer<T,C>::operator->()
{
	return m_acPtr;
}

template <typename T, typename C>
void SmartPointer<T,C>::Release()
{
	if(--*m_acPtr == 0)
	{
		delete m_ptr;
		delete m_acPtr;
	}
	m_ptr = 0;
	m_acPtr = 0;
}

template <typename T, typename C>
T* SmartPointer<T,C>::Move()
{
	T* temp = m_ptr;
	Reset(0);
	return temp;
}

template <typename T, typename C>
void SmartPointer<T,C>::Reset(T* _ptr)
{
	if(--*m_acPtr == 0)
	{
		delete m_ptr;
		delete m_acPtr;
	}
	m_ptr = 0;
	m_acPtr = new C;
	++*m_acPtr;
	m_ptr = _ptr;
}



