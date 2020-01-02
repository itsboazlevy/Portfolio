/* written by BL on 9.2.19 */

#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

typedef struct Person Person; 
struct Person
{
	int m_id;
	char m_name[128];
	int m_age;
	Person* m_next;
};

/*
Description: inserts new node as head of the linked list, if same ID exists will execute anyway
Input:	pointer to head node, pointer to node to be inserted
Output: pointer to the new head node, if new pointer to insert is NULL returns head node
		Address
		NULL
*/
Person* ListInsertHead(Person* _head,Person* _p);

/*
Description: removes head node from linked list if it exists
Input:	pointer to head node, pointer to pointer - to move the removed node to 
Output: pointer to the new head node
		Address
		NULL
*/
Person* ListRemoveHead(Person* _head,Person** _p);

/*
Description: Inserts node by Key. if same ID exists will not execute
Input:	pointer to head node, Key of new node and the node 
Output: pointer to the new head node
		Address
		NULL
*/
Person* ListInsertByKey(Person* _head, int key, Person* _p);
Person* ListInsertByKeyRec(Person* _head, int key, Person* _p);

/*
Description: Removes node by Key, if 2 nodes with same key exist removes first, if null pointer or no matching id wont execute
Input:	pointer to head node, Key of node to be removed, pointer to pointer - to move the removed node to   
Output: pointer to the new head node
		Address
		NULL
*/
Person* ListRemoveByKey(Person* _head, int key, Person** _p);
Person* ListRemoveByKeyRec(Person* _head, int key, Person** _p);


int IsListIdentical(Person* _head, Person* _head2);
Person* ListTail(Person* _head);
Person* MergeLists(Person* _head, Person* _head2);
Person* IsListLooped(Person* _head, Person* head2);

/*
Description: Prints all nodes in the Linked list, prints a message if head node is NULL
Input:	pointer to head node. 
Output: none
*/
void PrintList(Person* _head);

#endif /* __LINKEDLIST_H__ */
 
