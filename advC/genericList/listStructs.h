#ifndef __LISTSTRUCTS_H__
#define __LISTSTRUCTS_H__

typedef struct Node Node; 

struct Node
{
	void* m_item;
	Node* m_next;
	Node* m_prev;
};

struct List
{
	Node m_head;
	Node m_tail;
};

void List_Push(Node* _newNode, Node* _nextNode);

void List_Pop(void** _pItem, Node* _node);

#endif /* __LISTSTRUCTS_H__ */

