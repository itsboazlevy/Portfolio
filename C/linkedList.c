#include "linkedList.h"
#include <stdio.h>


Person* ListInsertHead(Person* _head,Person* _p)
{
 	
 	if(_p == NULL)
	{
		return _head;
	}
	_p->m_next = _head;
 	return _p;
}
 
Person* ListRemoveHead(Person* _head,Person** _p)
{
	if( _head == NULL || _p == NULL )
	{
		return _head;
	}
	*_p = _head;
	_head = _head->m_next;
	return _head;
}

void PrintList(Person* _head)
{
	int i = 1;
	printf("\n");
	if( _head == NULL )
	{
		printf("No Items in Your Linked List\n");
	}
	while(_head != NULL)
	{
		printf("Item #%d\n",i);
		printf("Address in memory: %p\n",(void*)_head);
		printf("ID: %d\n",_head->m_id);
		printf("Age: %d\n",_head->m_age);
		printf("Item: %s\n\n",_head->m_name);
		i++;
		_head = _head->m_next;
	}
}

Person* ListInsertByKey(Person* _head, int key, Person* _p)
{
	Person* prevHead;
	Person* originalHead = _head;
	if(_p == NULL)
	{
		return originalHead;
	}
	/*if list is empty or key is smaller than the head of it - insert to head and return it */
	if (_head == NULL || key < _head->m_id)
	{
		return ListInsertHead(_head, _p);
	}
	/*if key is bigger than current node key advances to next node */
	while(_head != NULL && key > _head->m_id)
	{
		prevHead = _head;
		_head = _head->m_next;
	}
	/*if key is the same as current node key returns NULL */
	if (_head != NULL && _head->m_id == key)
	{
		return originalHead;
	}
	/*inserts node to list */	
	prevHead->m_next = _p;
	_p->m_next = _head;
	return originalHead;
}

Person* ListInsertByKeyRec(Person* _head, int key, Person* _p)
{
	if (_head == NULL || key < _head->m_id )
	{
		return ListInsertHead(_head, _p);
	}
	if (key > _head->m_id)
	{
		_head->m_next =  ListInsertByKeyRec(_head->m_next, key, _p);
		return _head;
	}		
	return _head;
}

Person* ListRemoveByKey(Person* _head, int key, Person** _p)
{
	Person* prevHead;
	Person* originalHead = _head;
	if( _head == NULL || _p == NULL )
	{
		return originalHead;
	}
	/*if first node matches the key - removes it */
	if (key == _head->m_id)
	{
		return ListRemoveHead(_head,_p);
	}
	/*if key is not the current node key advances to next node */
	while(_head != NULL && key != _head->m_id )
	{
		if (key < _head->m_id)
		{
			return originalHead;
		}
		prevHead = _head;
		_head = _head->m_next;
	}
	/*if key is not in list returns NULL */
	if(_head == NULL)
	{
		return originalHead;
	}
	else
	{
		prevHead->m_next = _head->m_next;
		*_p = _head;
	}
	return originalHead;
}

Person* ListRemoveByKeyRec(Person* _head, int key, Person** _p)
{
	if (_head == NULL || key == _head->m_id)
	{
		return ListRemoveHead(_head, _p);
	}
	if (key != _head->m_id)
	{
		if ( (*_p)->m_next == ListRemoveByKeyRec(_head->m_next, key, _p))
		{
			_head->m_next = _head->m_next->m_next;
		}
		return _head;
	}		
	return _head;
}

Person* ListTail(Person* _head)
{

	if (_head == NULL)
	{
		return NULL;
	}
	if (_head->m_next == NULL)
	{
		return _head;
	}
	return ListTail(_head->m_next);
}

int IsListIdentical(Person* _head, Person* _head2)
{
	if (_head != _head2)
	{
		return 0;
	}
	if (_head == _head2 && _head == NULL &&  _head2 == NULL )
	{
		return 1;
	}
	if (_head->m_next == _head2->m_next)
	{
		return 1;
	}
	return IsListIdentical(_head->m_next, _head2->m_next);
}

Person* MergeLists(Person* _head, Person* _head2)
{
	if (_head == NULL && _head2 == NULL)
	{
		return NULL;
	}
	if (_head2 == NULL || _head < _head2)
	{
		_head->m_next = MergeLists(_head->m_next, _head2);
		return _head;
	}
	if (_head == NULL || _head > _head2)
	{
		_head2->m_next = MergeLists(_head, _head2->m_next);
		return _head2;
	}
	return _head;
}


