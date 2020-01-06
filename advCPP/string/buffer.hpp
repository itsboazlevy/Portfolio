#include <algorithm>
#include "../include/buffer.h"

template <typename T>
double Buffer<T>::growFactor = 1.3;

template <typename T>
Buffer<T>::Buffer(size_t _size)
: m_size(_size)
, m_capacity(_size*GrowFactor)
, m_data( size == 0 ? 0, new byte[sizeof(T)*m_capacity])
{}

template <typename T>
Buffer<T>::Buffer(const Buffer& _buffer)
: m_size(_buffer.Size())
, m_capacity(_buffer.Capacity())
, m_data( size == 0 ? 0, new byte[sizeof(T)*m_capacity])
{
	std::copy( Begin(), End(), m_data);
}

template <typename T>
Buffer& Buffer<T>::operator = (const Buffer& _buffer)
{
	GrowIfNeed(_buffer.Size());
	std::copy( _buffer.Begin(), _buffer.End(), m_data);
}
	
template <typename T>
Buffer<T>::~Buffer(size_t _size)
{
	delete[] m_data;
}

template <typename T>
size_t Buffer<T>::Size() const
{
	return m_size;
}

template <typename T>
size_t Buffer<T>::Capacity() const
{
	return m_capacity;
}

template <typename T>
byte* Buffer<T>::Begin() const
{
	return m_data; 
}

template <typename T>
byte* Buffer<T>::End() const
{
	return ( m_data + sizeof(T)*m_size ); 
}

template <typename T>
void Buffer<T>::GrowIfNeed((size_t _size))
{
	if ( _size > m_size)
	{
		size = _size;
		m_capacity = _size*growFactor;
		byte* newBytePtr = new byte[sizeof(T)*m_capacity]);
		std::copy( Begin(), End(), newBytePtr);
		delete[] m_data;
		m_data = newBytePtr;
	}
}

template <typename T>
double Buffer<T>::GrowFactor()
{
	return growFactor;
}

template <typename T>
void Buffer<T>::GrowFactor(double _growFactor)
{
	growFactor = _growFactor;
}
	
	
	
	
