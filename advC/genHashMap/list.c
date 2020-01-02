#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "listStructs.h"

void List_Push(Node* _newNode, Node* _nextNode)
{
	_newNode->m_next = _nextNode;
	_newNode->m_prev = _nextNode->m_prev;
	_nextNode->m_prev->m_next = _newNode;
	_nextNode->m_prev = _newNode;
	return;
}
	
void List_Pop(void** _pItem, Node* _node)
{
	_node->m_next->m_prev = _node->m_prev;
	_node->m_prev->m_next = _node->m_next;
	*_pItem = _node->m_item;
	free(_node);
	return;
}
	
static List_Result Parameters_Check(List* _list, void* _item)
{
	if (_list == NULL)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	if (_item == NULL)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}
	return LIST_SUCCESS;
}

List* List_Create(void)
{
	List* pList = (List*)malloc(sizeof(List));
	if (pList == NULL)
	{
		return NULL;
	}
	pList->m_head.m_next = &(pList->m_tail);
	pList->m_head.m_prev = NULL; 
	pList->m_tail.m_prev = &(pList->m_head);
	pList->m_tail.m_next = NULL; 
	return pList;
}

void List_Destroy(List** _pList, void (*_elementDestroy)(void* _item))
{
	Node* temp;
	if (_pList != NULL && *_pList != NULL)
	{
		if ( (*_elementDestroy) == NULL)
		{
			while ((*_pList)->m_head.m_next != &((*_pList)->m_tail))
			{
				temp = (*_pList)->m_head.m_next;
				(*_pList)->m_head.m_next = temp->m_next;
				free(temp);
			}
		}
		else
		{
			while ((*_pList)->m_head.m_next != &((*_pList)->m_tail))
			{
				temp = (*_pList)->m_head.m_next;
				(*_pList)->m_head.m_next = temp->m_next;
				(*_elementDestroy)(temp->m_item);
				free(temp);
			}
		}
		free(*_pList);
		*_pList = NULL;
	}
	return;
}

List_Result List_PushTail(List* _list, void* _item)
{
	Node* newNode;
	if (_list == NULL)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	newNode = (Node*)malloc(sizeof(Node));
	if ( newNode == NULL)
	{
		return LIST_ALLOCATION_ERROR;
	}
	List_Push(newNode, &(_list->m_tail));
	newNode->m_item = _item;
	return LIST_SUCCESS;
}

List_Result List_PushHead(List* _list, void* _item)
{
	Node* newNode;
	if (_list == NULL)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	newNode = (Node*)malloc(sizeof(Node));
	if ( newNode == NULL)
	{
		return LIST_ALLOCATION_ERROR;
	}
	List_Push(newNode,_list->m_head.m_next);
	newNode->m_item = _item;
	return LIST_SUCCESS;
}

List_Result List_PopHead(List* _list, void** _pItem)
{
	int ParametersResult;
	ParametersResult = Parameters_Check(_list,_pItem);
	if (ParametersResult != LIST_SUCCESS)
	{
		return ParametersResult;
	}
	if (_list->m_head.m_next == &(_list->m_tail))
	{
		return LIST_UNDERFLOW;
	}
	List_Pop(_pItem, _list->m_head.m_next);
	return LIST_SUCCESS;
}

List_Result List_PopTail(List* _list, void** _pItem)
{
	int ParametersResult;
	ParametersResult = Parameters_Check(_list,*_pItem);
	if (ParametersResult != LIST_SUCCESS)
	{
		return ParametersResult;
	}
	if (_list->m_head.m_next == &(_list->m_tail))
	{
		return LIST_UNDERFLOW;
	}
	List_Pop(_pItem, _list->m_tail.m_prev);
	return LIST_SUCCESS;
}

size_t List_Size(const List* _list)
{
	int count = 0;
	Node* temp;
	if (_list == NULL)
	{
		return count; 
	}
	temp = _list->m_head.m_next;
	while ( temp != &(_list->m_tail))
	{
		count++;
		temp = temp->m_next;
	}
	return count;
}

