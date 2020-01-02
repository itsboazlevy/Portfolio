#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedList.h"
#define MAGIC_NUM 123456789
typedef struct Node Node; 
struct Node
{
	int m_data;
	Node* m_next;
	Node* m_prev;
};

struct List
{
	Node m_head;
	Node m_tail;
};

List* ListCreate(void)
{
	List* myList = (List*)malloc(sizeof(List));
	if (myList == NULL)
	{
		return NULL;
	}
	myList->m_head.m_next = &myList->m_tail;
	myList->m_tail.m_prev = &myList->m_head;
	myList->m_head.m_data = MAGIC_NUM;
	return myList;
}

void ListDestroy(List* _list)
{
	int count;
	Node* temp;
	if (_list != NULL && _list->m_head.m_data == MAGIC_NUM)
	{
		for (count = ListCountItems(_list); count > 0; count--)
		{
			temp = _list->m_head.m_next;
			_list->m_head.m_next = temp->m_next;
			free(temp);
		}
		_list->m_head.m_data = 0;
		free(_list);
	}
}

static Node* NodeCreate(List* _list, int _data)
{
	Node* newNode;
	if (_list == NULL)
	{
		return NULL;
	}
	newNode = (Node*)malloc(sizeof(Node));
	if ( newNode == NULL)
	{
		return NULL;
	}
	newNode->m_data = _data;
	return newNode;
}

ADTErr ListPushHead(List* _list, int _data)
{
	Node* newNode = NodeCreate(_list,_data);
	if (newNode == NULL)
	{
		return FAIL;
	}
	newNode->m_prev = &_list->m_head;
	newNode->m_next = _list->m_head.m_next;
	_list->m_head.m_next->m_prev = newNode;
	_list->m_head.m_next = newNode;
	return SUCCESS;
}

ADTErr ListPushTail(List* _list, int _data)
{
	Node* newNode = NodeCreate(_list,_data);
	if (newNode == NULL)
	{
		return FAIL;
	}
	newNode->m_prev = _list->m_tail.m_prev;
	newNode->m_next = &_list->m_tail;
	_list->m_tail.m_prev->m_next = newNode;
	_list->m_tail.m_prev = newNode;
	return SUCCESS;
}

ADTErr ListPopHead(List* _list, int* _data)
{
	Node* temp;
	if (_list == NULL || _data == NULL)
	{
		return FAIL;
	}
	temp =_list->m_head.m_next;
	*_data = _list->m_head.m_next->m_data;
	_list->m_head.m_next->m_next->m_prev = &_list->m_head;
	_list->m_head.m_next = _list->m_head.m_next->m_next;
	free (temp);
	return SUCCESS;
}

ADTErr ListPopTail(List* _list, int* _data)
{
	Node* temp;
	if (_list == NULL || _data == NULL)
	{
		return FAIL;
	}
	temp =_list->m_head.m_next;
	*_data = _list->m_tail.m_prev->m_data;
	_list->m_tail.m_prev->m_prev->m_next = &_list->m_tail;
	_list->m_tail.m_prev = _list->m_tail.m_prev->m_prev;
	free (temp);
	return SUCCESS;	
}
size_t ListCountItems(List* _list)
{
	int count = 0;
	Node* temp;
	if (_list == NULL)
	{
		return count; 
	}
	temp = _list->m_head.m_next;
	while ( temp != &_list->m_tail)
	{
		count++;
		temp = temp->m_next;
	}
	return count;
}

int ListIsEmpty(List* _list)
{
	if (_list == NULL)
	{
		return 0; 
	}
	if (_list->m_head.m_next == &_list->m_tail)
	{
		return 1;
	}
	return 0;
}

void ListPrint(List* _list)
{
	Node* temp;
	int count;
	int index;
	if (_list == NULL)
	{
		printf("Create a List First");
	}
 	count = ListCountItems(_list);
 	printf("List Items:\n");
 	temp = _list->m_head.m_next;
 	index = 1;
	while (index <= count)
	{
 		printf("\nItem # %d\n",index);
 		printf("Node: %p\n",(void*)temp);
 		printf("Data: %d\n",temp->m_data);
		printf("Previous Node: %p\n",(void*)temp->m_prev);
 		printf("Next Node: %p\n",(void*)temp->m_next);
		temp = temp->m_next;
		index++;
	}
}

