#ifndef __VECTOR_H__
#define  __VECTOR_H__
	#include "container.h"
template <class T>
class vector_t: public container_t
{
	public:
		vector_t(size_t _initialCapacity = 16, size_t _blockSize = 8); // has to be default above 0 for block
		virtual ~vector_t();
		virtual bool append(const T* _elemPtr, size_t _index);
		virtual bool prepend(const T* _elemPtr, size_t _index);
		virtual bool contains(const T* _elemPtr) const;
		//size_t count() const {return m_nItems;}
		virtual const T* find(const T& _elem) const;
		virtual int index(const T* _elemPtr) const;
		//bool isEmpty() const {return (m_nItems == 0);}
		virtual bool insert(const T* _elemPtr);
		virtual T* remove(const T& _elem);
		virtual T* removeAndDelete(const T& _elem);
		virtual bool removeAll();
		virtual bool removeAndDeleteAll();
	private:
		vector_t(const vector_t& _vecRef);
		vector_t& operator = (const vector_t& _vecRef);
		T**	   m_items;
		size_t m_originalSize;  
		size_t m_size;      
		//size_t m_nItems;
		size_t m_blockSize;
};

#endif //__VECTOR_H__

template <class T>
vector_t<T>::vector_t(size_t _initialCapacity, size_t _blockSize)
{
	m_items = new T*[_initialCapacity];
	m_originalSize =_initialCapacity;	
	m_blockSize = _blockSize;
	m_size = _initialCapacity;
	this->m_nItems = 0;
}

template <class T>
vector_t<T>::~vector_t()
{
	delete[] m_items;
}

template <class T>
bool vector_t<T>::append(const T* _elemPtr, size_t _index)
{
	if (_index > this->m_nItems+1 || _elemPtr == NULL)
	{
		return false;
	}
	if (this->m_nItems == m_size  )
	{
		m_size += m_blockSize;
		T** temp = new T*[m_size];
		memcpy((void*)temp,(const void*)m_items,(this->m_nItems*sizeof(T*))); 
		delete[] m_items;
		m_items = temp;
	}
	for (size_t i = 0; i < this->m_nItems - _index -1; i++)
	{
		*(m_items + this->m_nItems -i) = *(m_items + this->m_nItems -i -1);
	}
	*(m_items + _index+1) = _elemPtr;
	this->m_nItems++;
	return true;
}

template <class T>
bool vector_t<T>::prepend(const T* _elemPtr, size_t _index)
{
	return append(_elemPtr,_index-1);
}
	
template <class T>
bool vector_t<T>::contains(const T* _elemPtr) const
{
	size_t i;
	bool result = false;
	for (i = 0; i < this->m_nItems; i++)
	{
		if (_elemPtr == m_items[i])
		{
			result = true;
			break;
		}
	}
	return result;
}

template <class T>
const T* vector_t<T>::find(const T& _elem) const
{
	size_t i;
	for (i = 0; i < this->m_nItems; i++)
	{
		if (_elem == *(m_items[i]))
		{
			return m_items[i];
		}
	}
	return NULL;
}

template <class T>
int vector_t<T>::index(const T* _elemPtr) const
{
	size_t i;
	for (i = 0; i < this->m_nItems; i++)
	{
		if (_elemPtr == m_items[i])
		{
			return i;
		}
	}
	return -1;
}

template <class T>
bool vector_t<T>::insert(const T* _elemPtr)
{
	return prepend(_elemPtr, this->m_nItems);
}

template <class T>
T* vector_t<T>::remove(const T& _elem)
{
	size_t i;
	for (i = 0; i < this->m_nItems; i++)
	{
		if (_elem == *(m_items[i]))
		{
			break;
		}
	}
	for (i; i < this->m_nItems-1; i++)
	{
		*(m_items + i) = *(m_items+i+1);	
	}
	this->m_nItems--;
	
	if(this->m_nItems + m_blockSize*2 < m_size)
	{
		m_size -= m_blockSize;
		T** temp = new T*[m_size];
		memcpy((void*)temp,(const void*)m_items,(this->m_nItems*sizeof(T*))); 
		delete[] m_items;
		m_items = temp;
	}
	return m_items[this->m_nItems];	
}

template <class T>
T* vector_t<T>::removeAndDelete(const T& _elem)
{
	T* tmp = remove(T _elem);
	delete[] tmp;
	return tmp;
}

template <class T>
bool vector_t<T>::removeAll()
{
	this->m_nItems = 0;
	m_size = m_originalSize;
	delete[] m_items;
	m_items = new T*[m_originalSize];
	return true;
}

template <class T>
bool vector_t<T>::removeAndDeleteAll()
{
	for(i=0; i<this->m_nItems;i++)
	{
		delete[] m_items[i];
	}
	removeAll();
	return true;
}

