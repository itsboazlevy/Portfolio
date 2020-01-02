#include <stdio.h>
#include "doubleLinkedList.h"
#define MAGIC_NUM 123456789
int main()
{
	List* listA = NULL;
	int data;
	listA = ListCreate();
	if (listA != NULL) printf("SUCCESS!\n"); else printf("FAIL!\n");
	if (ListCountItems(listA) == 0 ) printf("SUCCESS!\n"); else printf("FAIL!\n");
	if (ListCountItems(NULL) == 0 ) printf("SUCCESS!\n"); else printf("FAIL!\n");
	if (ListIsEmpty(NULL) == 0 ) printf("SUCCESS!\n"); else printf("FAIL!\n");
	if (ListIsEmpty(listA) == 1 ) printf("SUCCESS!\n"); else printf("FAIL!\n");
	if (ListPushHead(listA, 50) == SUCCESS) printf("SUCCESS!\n"); else printf("FAIL!\n");
	if (ListIsEmpty(listA) == 0 ) printf("SUCCESS!\n"); else printf("FAIL!\n");
	if (ListCountItems(listA) == 1)printf("SUCCESS!\n"); else printf("FAIL!\n");
	ListDestroy(listA);
	listA = ListCreate();
	ListPushTail(listA, 1);
	ListPushTail(listA, 2);
	ListPushTail(listA,3);
	ListPushHead(listA,13);
	ListPushHead(listA,14);
	ListPushHead(listA,15);
	ListPushTail(listA, 4);
	ListPushTail(listA, 5);
	ListPopTail(listA, &data);
	ListPopTail(listA, &data);
	ListPopHead(listA, &data);
	ListPopHead(listA, &data);
	ListPrint(listA);
	return 1;
}
