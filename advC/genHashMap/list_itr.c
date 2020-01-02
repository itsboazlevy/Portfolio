#include "list_itr.h"
#include "listStructs.h"

ListItr ListItr_Begin(const List* _list)
{
	return (void*)(_list->m_head.m_next);
}

ListItr ListItr_End(const List* _list)
{
	return (void*)&(_list->m_tail);
}

int ListItr_Equals(const ListItr _a, const ListItr _b)
{
	return ((int*)_a - (int*)_b);
}

ListItr ListItr_Next(ListItr _itr)
{
	if (((Node*)_itr)->m_next == NULL)
	{
		return _itr;
	}
	return (void*)(((Node*)_itr)->m_next);
}

ListItr ListItr_Prev(ListItr _itr)
{
	if (((Node*)_itr)->m_prev->m_prev == NULL)
	{
		return _itr;
	}
	return (void*)(((Node*)_itr)->m_prev);
}

void* ListItr_Get(ListItr _itr)
{
	if (((Node*)_itr)->m_next == NULL)
	{
		return NULL;
	}
	return ((Node*)_itr)->m_item;
}

void* ListItr_Set(ListItr _itr, void* _element)
{
	void* temp = ((Node*)_itr)->m_item;
	((Node*)_itr)->m_item = _element;
	return temp;
}

ListItr ListItr_InsertBefore(ListItr _itr, void* _element)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->m_item = _element;
	List_Push(newNode, (Node*)_itr);
	return (void*)newNode;
}

void* ListItr_Remove(ListItr _itr)
{
	void* temp;
	List_Pop(&temp, (Node*)_itr);
	return temp;
}



