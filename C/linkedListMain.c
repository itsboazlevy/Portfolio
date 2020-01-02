#include "linkedList.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
 	Person initialItem;
	Person* tail = NULL;
	Person* head = NULL;
	Person* head2 = NULL;
	Person* item = &initialItem;	
	Person* a;
	Person* b;
	Person* c;
	Person* d;
	Person* e;

 	a = (Person*)malloc(sizeof(Person)); 
 	a->m_id = 14;
	a->m_age = 40;
	strcpy(a->m_name,"arturo");
 	a->m_next = NULL;

	b = (Person*)malloc(sizeof(Person)); 
 	b->m_id = 13;
	b->m_age = 50;
	strcpy(b->m_name,"buzaglo");
 	b->m_next = NULL;

	c = (Person*)malloc(sizeof(Person)); 
 	c->m_id = 15;
	c->m_age = 30;
	strcpy(c->m_name,"compadre");
 	c->m_next = NULL;
 	
 	
	d = (Person*)malloc(sizeof(Person)); 
 	d->m_id = 14;
	d->m_age = 20;
	strcpy(d->m_name,"jesus");
 	d->m_next = NULL;

	e = (Person*)malloc(sizeof(Person)); 
 	e->m_id = 11;
	e->m_age = 60;
	strcpy(e->m_name,"jasmin");
 	e->m_next = NULL;
 	
 	
	/* ListInsertHead Tests */
	head = NULL;
	head = ListInsertHead(head,a);
	item = &initialItem;
	if ( a == head)
	{
		printf("SUCCESS\n");
	}
	else
	{
		printf("FAIL\n");
	}
 	head = ListInsertHead(head,b);
 	if ( b == head)
	{
		printf("SUCCESS\n");
	}
	else
	{
		printf("FAIL\n");
	}
 	head = ListInsertHead(head,c);
 	if ( c == head)
	{
		printf("SUCCESS\n");
	}
	else
	{
		printf("FAIL\n");
	}
 	if( head->m_next == b )
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	}
 	if( head->m_next->m_next == a )
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	}
 	if( head->m_next->m_next->m_next == NULL )
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	}

 	head = ListInsertHead(NULL,a);
 	if(a==head)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 	
 	head = ListInsertHead(head,NULL);
 	if(head == a)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 	
 	printf("-------\n"); 
 	/* ListRemoveHead Tests */
 	head = ListInsertHead(head,a);
 	head = ListInsertHead(head,b);
 	head = ListInsertHead(head,c);
	head =	ListRemoveHead(head, &item);
	if(b==head)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 	
	if(item==c)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 	
	head =	ListRemoveHead(b, NULL);
	if(b == head)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 	
 	head =	ListRemoveHead(NULL, &item);
 	if(NULL == head)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 	
 	printf("-------\n"); 
 	/* ListInsertByKey Tests */
 	head = NULL;
 	head = ListInsertByKey(head,a->m_id, a);
 	if(a==head)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	head = ListInsertByKey(head,b->m_id, b);
 	if(b==head)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	head = ListInsertByKey(head,c->m_id, c);
 	if(b==head)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
	
	if(ListInsertByKey(head,d->m_id, d)==b)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	head = ListInsertByKey(head,e->m_id, e);
 	if(head==e)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
	if(ListInsertByKey(head,e->m_id, NULL)==e)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	printf("-------\n"); 
 	/* ListRemoveByKey Tests */
 	head = ListRemoveByKey(head,e->m_id, &item);
 	if(head==b)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	if(e==item)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	head = ListRemoveByKey(head,a->m_id, &item);
 	if(b==head)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	if(a==item)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	head = ListRemoveByKey(head,c->m_id, &item);
	if(b==head)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	if(c==item)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	head = ListRemoveByKey(head,c->m_id, &item);
	if(head==b)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
	if(c==item)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
	head = ListInsertByKey(head,e->m_id, e);
 	head = ListRemoveByKey(head,e->m_id, NULL);
 	if(head==e)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
	if(c==item)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	head = ListRemoveByKey(NULL,e->m_id, &item);
 	if(head==NULL)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	}
	if(c==item)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	printf("-------\n"); 
 	/* ListInsertByKeyRec Tests */
 	head = NULL;
 	head = ListInsertByKeyRec(head,a->m_id, a);
 	if(a==head)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	head = ListInsertByKeyRec(head,b->m_id, b);
 	if(b==head)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	head = ListInsertByKeyRec(head,c->m_id, c);
 	if(b==head)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
	
	if(ListInsertByKeyRec(head,d->m_id, d)==b)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	head = ListInsertByKeyRec(head,e->m_id, e);
 	if(head==e)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
	if(ListInsertByKeyRec(head,e->m_id, NULL)==e)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	printf("-------\n"); 
 	/* ListRemoveByKeyRec Tests */
 	head = ListRemoveByKeyRec(head,e->m_id, &item);
 	if(head==b)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	if(e==item)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	head = ListRemoveByKeyRec(head,a->m_id, &item);
 	if(b==head)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	if(a==item)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	head = ListRemoveByKeyRec(head,c->m_id, &item);
	if(b==head)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	if(c==item)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	head = ListRemoveByKeyRec(head,c->m_id, &item);
	if(head==b)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
	if(c==item)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
	head = ListInsertByKeyRec(head,e->m_id, e);
 	head = ListRemoveByKeyRec(head,e->m_id, NULL);
 	if(head==e)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
	if(c==item)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	head = ListRemoveByKeyRec(NULL,e->m_id, &item);
 	if(head==NULL)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	}
	if(c==item)
 	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	} 
 	printf("-------\n"); 
 	
 	/* PrintList Tests */
 	head = NULL;
 	PrintList(head);
 	head = ListInsertHead(head,a);
 	PrintList(head);
 	head = ListInsertHead(head,b);
 	PrintList(head);  
	

	/* ListTail Tests */
	head = NULL;
	head = ListInsertHead(head,a);
	head = ListInsertHead(head,b);
	head = ListInsertHead(head,c);
	tail = ListTail(head);
	if (tail == a) 
	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	}

	/* IsListIdentical Tests */
	head = NULL;
	head2=  NULL;
	if (IsListIdentical(head,head2)) 
	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	}
	head = ListInsertHead(head,a);
	head = ListInsertHead(head,b);
	head = ListInsertHead(head,c);
	head2 = ListInsertHead(head2,a);
	head2 = ListInsertHead(head2,b);
	head2 = ListInsertHead(head2,c);
	if (IsListIdentical(head,head2)) 
	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	}
	head2 = ListRemoveHead(head2,&item);
	if (!IsListIdentical(head,h	ad2)) 
	{
 		printf("SUCCESS\n");
 	}
 	else
	{
		printf("FAIL\n");
	}

	/* MergeLists Tests */
	head = NULL;
	head2=  NULL;
	head = ListInsertByKeyRec(head,c->m_id, c);
	head = ListInsertByKeyRec(head,e->m_id, e);
	head = ListInsertByKeyRec(head,a->m_id, a);

	head2 = ListInsertByKeyRec(head2,b->m_id, b);
	PrintList(head);
	PrintList(head2);
	head = MergeLists(head,head2);
	PrintList(head);
 	return 1;
}
 
