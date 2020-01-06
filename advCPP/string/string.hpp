#ifndef STRING_HPP
#define STRING_HPP
#include <cstring>
#include <iostream>
#include <locale>
#include <algorithm>
#include "../include/string.h"

template <typename T>
String<T>::String(const T* _tPtr)
: m_size(strlen(_tPtr))
, m_data(m_size)
{
	
}

template <typename T>
T* String<T>::Data() const
{
	return reinterpret_cast<char*>(m_data.Begin());
}

template <typename T>
void String<T>::Data(T* _tPtr)
{
	size_t length = strlen(_tPtr);
	m_data.GrowIfNeed(length);
	std::copy( _tPtr, _tPtr + length, m_data.Begin());
}

template <typename T>
size_t String<T>::Size() const
{
	return m_data.Size();
}

template <typename T>
T String<T>::operator [] (size_t _index) const
{
	return m_data.Begin()[_index];
}
/*
template <typename T>
T& String<T>::operator [] (size_t _index)
{
	return m_data.Begin()[_index];
}*/

template <typename T>
T String<T>::At(size_t _index) const throw(int)
{
	if (_index >= Size()) { throw (1); } else { return (*this)[_index]; }	
}

template <typename T>
T& String<T>::At(size_t _index) throw(int)
{
	if (_index >= Size()) { throw (1); } else { return (*this)[_index]; }	
}

template <typename T>
String<T>::operator bool() const
{
	return m_data.Size() != 0;
}

template <typename T>
String<T>& String<T>::operator += (const String<T>& _S1)
{
	m_data.GrowIfNeed( _S1.Size() + Size() );
	std::copy( _S1.Begin(), _S1.End(), m_data.Begin() + Size());
}

//_________________________________________________out classed______________________________________________________\\

template <typename T>
bool operator == (const String<T>& _S1, const String<T>& _S2) 
{ 
	return strcmp(_S1.Data(),_S2.Data()) == 0; 
}

template <typename T>
bool operator > (const String<T>& _S1, const String<T>& _S2)
{
	return strcmp(_S1.Data(),_S2.Data()) > 0 ; 
}

template <typename T>
bool operator != (const String<T>& _S1, const String<T>& _S2) 
{
	return !(_S1 == _S2); 
}

template <typename T>
bool operator < (const String<T>& _S1, const String<T>& _S2)
{
	return !( _S1 > _S2 || _S1 == _S2);
}

template <typename T>
bool operator >= (const String<T>& _S1, const String<T>& _S2)
{
	return ( _S1 > _S2 || _S1 == _S2);
}

template <typename T>
bool operator <= (const String<T>& _S1, const String<T>& _S2)
{
	return !(_S1 > _S2);
}

template <typename T>
bool Contain(const String<T>& _S1, T _t)
{
	bool flag = 0;
	int i;
	for (i = 0; i < _S1.Size(); i++)
	{
		if ( _t == _S1[i] )
		{
			flag = 1;
			break;
		}
	}
	return flag;
}

template <typename T>
void ToUpper(String<T>& _S1)
{
	int i;
	T c;
	for (i = 0; i < _S1.Size(); i++)
	{
		c = toupper(_S1[i]);
		_S1[i] = c;
	}	
}

template <typename T>
void ToLower(String<T>& _S1)
{
	int i;
	T c;
	for (i = 0; i < _S1.Size(); i++)
	{
		c = tolower(_S1[i]);
		_S1[i] = c;
	}	
}

template <typename T>
String<T>& operator + (const String<T>& _S1, const String<T>& _S2)
{
	String<T> newString;
	newString.m_data.GrowIfNeed(_S1.Size() + _S2.Size());
	std::copy( _S1, _S1 + _S1.Size(), newString.m_data.Begin());
	std::copy( _S2, _S2 + _S2.Size(), newString.m_data.Begin() + _S1.Size() +1 );
	return newString;
}

template <typename T>
void Print(String<T>& _S1) 
{
	std::cout << _S1.Data();
}

	
#endif //STRING_HPP

