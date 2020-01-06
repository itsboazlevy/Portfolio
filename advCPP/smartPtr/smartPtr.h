#ifndef SMARTPTR_H
#define SMARTPTR_H

template <typename T = size_t>
class AtomicCounter
{
public:
	AtomicCounter(T _count = T(0));
	T& operator++();
	T operator++(int);
	T& operator--();
	T operator--(int);	
private:
	AtomicCounter& operator=(const AtomicCounter& _ref);
	AtomicCounter(const AtomicCounter& _ref);
private:
	T m_count;
};


template <typename T, typename C = AtomicCounter >
class SmartPointer
{
public:
	explicit SmartPointer(T* _ptr = 0);
	SmartPointer(const SmartPointer& _ref);
	SmartPointer& operator=(const SmartPointer& _ref);
	~SmartPointer();
public:
	T& operator*();
	T* operator->();
	void Release();
	T* Get() const;
	void Reset(T* _ptr);
	bool operator !()
	
private:
	T* m_ptr;
	C* m_acPtr;
};

#include "smartPtr.hpp"

#endif //SMARTPTR_H
