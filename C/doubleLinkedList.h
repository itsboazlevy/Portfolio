/* 
written by BL on 9.2.19
Double Linked List ADT
 */

#ifndef __DOUBLELINKEDLIST_H__
#define __DOUBLELINKEDLIST_H__

typedef enum {FAIL, SUCCESS, ALOC_ERR, NULL_ERR} ADTErr;
typedef struct List List; 

/*
Description: creates a new List, allocates memory. 
Input:	none.
Output: pointer to the new List, NULL if failed to allocate memory.
		Address
		NULL
*/
List* ListCreate(void);

/*
Description: destroys a list. frees memory of all nodes within it and frees list structure 
Input:	pointer to list.
Output: none.
*/
void ListDestroy(List* _list);

/*
Description: checks number of items between head and tail of list
Input:	pointer to list
Output: items count, if pointer is NULL count is 0
*/
size_t ListCountItems(List* _list);

/*
Description: Node Push to Head/Tail of list
Input:	pointer to list, data.
Output: SUCCESS or FAIL
*/
ADTErr ListPushHead(List* _list, int _data);
ADTErr ListPushTail(List* _list, int _data);

/*
Description: Node Pop from Head/Tail of list
Input:	pointer to list, pointer to data.
Output: SUCCESS or FAIL
*/
ADTErr ListPopHead(List* _list, int* _data);
ADTErr ListPopTail(List* _list, int* _data);

/*
Description: checks if list is empty
Input:	pointer to list
Output: returns 1 if empty, 0 if not or null pointer
*/
int ListIsEmpty(List* _list);

/*
Description: prints list, if null pointer to list prints a message
Input:	pointer to list
Output: none
*/
void ListPrint(List* _list);

#endif /* __DOUBLELINKEDLIST_H__ */
