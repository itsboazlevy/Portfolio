//design is complete implementation still need to be fixed, without element
#ifndef STRING_H
#define STRING_H
#include <cstddef>
#include "../include/buffer.h"

template <typename T>
class String
{
public:
	String(const T* _tPtr = 0); 
	// String(const String<T>& _String) = default;
	// String& operator = (const String<T>& _String) = default;
	// ~String() = default;
	
	T* Data() const;
	void Data(T* _tPtr);
	
	size_t Size() const;

	T operator [] (size_t _index) const;
	T& operator [] (size_t _index); 
	
	T At(size_t _index) const throw(int);
	T& At(size_t _index) throw(int); 
	
	operator bool() const;
	
	String& operator += (const String<T>& _String);
	
private:
	Buffer<T> m_data;
	size_t m_size;

};

template <typename T>
bool operator == (const String<T>& _S1, const String<T>& _S2); //this needs modification when adding other string types 

template <typename T>
bool operator > (const String<T>& _S1, const String<T>& _S2); //this needs modification when adding other string types

template <typename T>
bool operator != (const String<T>& _S1, const String<T>& _S2);

template <typename T>
bool operator < (const String<T>& _S1, const String<T>& _S2); 

template <typename T>
bool operator >= (const String<T>& _S1, const String<T>& _S2); 

template <typename T>
bool operator <= (const String<T>& _S1, const String<T>& _S2); 

template <typename T>
bool Contain(const String<T>& _S1, T _t);

template <typename T>
void ToUpper(String<T>& _S1);

template <typename T>
void ToLower(String<T>& _S1);

template <typename T>
T* operator + (const String<T>& _S1, const String<T>& _S2); //this needs modification when adding other string types
	
template <typename T>
void Print(String<T>& _S1); 

#include "../string/string.hpp"
#endif // STRING_H

