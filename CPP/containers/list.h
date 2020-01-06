#ifndef __LIST_H__
#define  __LIST_H__
#include "container.h"
template <class T>
class list_t: public container_t
{
	public:
		list_t();
		virtual ~list_t();
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
		list_t(const list_t& _lisRef);
		list_t& operator = (const list_t& _lisRef);
		//size_t m_nItems;
		class Node
		{
			T* m_item;
			Node* m_next;
			Node* m_prev;
		};
		Node m_head;
		Node m_tail;
		void push(Node* _newNode, Node* _nextNode);
};

#endif // __LIST_H__

template <class T>
list_t<T>::list_t()
{
	m_head.m_next = &(m_tail);
	m_head.m_prev = NULL; 
	m_tail.m_prev = &(m_head);
	m_tail.m_next = NULL; 
}

template <class T>
list_t<T>::~list_t()
{
	removeAll();
}

template <class T>
bool list_t<T>::append(const T* _elemPtr, size_t _index)
{
	if (_index < this->m_nItems)
	{
		return false;
	}
	int i;
	Node* newNode  = new Node;
	Node tmp = m_head;
	for (i=0; i< _index; i++)
	{
		tmp = tmp.m_next;
	}
	push(newNode,tmp.m_next);
	newNode->m_item = _elemPtr;
	this->m_nItems++;
	return true;
}

template <class T>
void list_t<T>::push(Node* _newNode, Node* _nextNode)
{
	_newNode->m_next = _nextNode;
	_newNode->m_prev = _nextNode->m_prev;
	_nextNode->m_prev->m_next = _newNode;
	_nextNode->m_prev = _newNode;
	return;
}

template <class T>
bool list_t<T>::prepend(const T* _elemPtr, size_t _index)
{
	append(_elemPtr,_index-1);	
}

template <class T>
bool list_t<T>::contains(const T* _elemPtr) const
{
	bool flag = false;
	Node tmp = m_head;
	while (tmp.m_next != m_tail)
	{
		if (tmp.m_next.m_item == _elemPtr)
		{
			flag = true;
			break;
		} 
	}
	return flag;
}

template <class T>
const T* list_t<T>::find(const T& _elem) const
{
	Node tmp = m_head;
	while (tmp.m_next != m_tail)
	{
		if (*(tmp.m_next.m_item) == _elem)
		{
			return tmp.m_next;
		} 
	}
	return 0;
}

template <class T>
int list_t<T>::index(const T* _elemPtr) const
{
	Node tmp = m_head;
	int i = 0;
	while (tmp.m_next != m_tail)
	{
		if (tmp.m_next.m_item == _elemPtr)
		{
			return i;
		}
		i++;
	}
	return -1;
}

template <class T>	
bool list_t<T>::insert(const T* _elemPtr)
{
	return append(_elemPtr,this->m_nItems-1);
}

template <class T>
T*  list_t<T>::remove(const T& _elem)
{
	Node* tmpNode = find(_elem);
	if( tmpNode == 0)
	{
		return NULL;
	}
	tmpNode->m_next->m_prev = tmpNode->m_prev;
	tmpNode->m_prev->m_next = tmpNode->m_next;
	T* tmpT = tmpNode->m_item;
	delete tmpNode;
	this->m_nItems--;
	return tmpT;
}

template <class T>
T* list_t<T>::removeAndDelete(const T& _elem)
{
	T* tmpT = remove(_elem);
	delete tmpT;
	return tmpT;
}

template <class T>
bool list_t<T>::removeAll()
{
	Node tmp = m_head;
	Node tmpNext = m_head.m_next;
	while (tmpNext != m_tail)
	{
		remove(*tmp.m_item);
		tmp = tmpNext;
		tmpNext = tmpNext.m_next;
	}
	return true;
}

template <class T>
bool list_t<T>::removeAndDeleteAll()
{
	Node tmp = m_head;
	Node tmpNext = m_head.m_next;
	while (tmpNext != m_tail)
	{
		removeAndDelete(*tmp.m_item);
		tmp = tmpNext;
		tmpNext = tmpNext.m_next;
	}
	return true;
}

	

