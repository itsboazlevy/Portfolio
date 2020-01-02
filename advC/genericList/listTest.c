#include <stdio.h>
#include <stdlib.h>
#include "list_functions.h"

typedef struct RandStruc RandStruc;
struct RandStruc
{
	int m_randInt;
	char m_randChar;
	float m_randFloat;
};

void RandStrucDestroy (void* _item)
{
	free((RandStruc*)_item);
	return;	
}

/*predicate function*/
int RandStrucIsIntEqual(void * _element, void* _context)
{
	if ( _element == NULL || _context == NULL)
	{
		return 0;
	}
	if (((RandStruc*)_element)->m_randInt == ((RandStruc*)_context)->m_randInt)
	{
		return 1;
	}
	return 0;
}

/*action function*/
int RandStrucIntAdd(void * _element, void* _context)
{
	if ( _element == NULL || _context == NULL)
	{
		return 0;
	}
	((RandStruc*)_element)->m_randInt += ((RandStruc*)_context)->m_randInt;
	return 1;
}

/*less function*/
int RandStrucIsIntLess(void* _a, void* _b)
{
	if (_a == NULL || _b == NULL)
	{
		return 0;
	}
	if ( ((RandStruc*)_a)->m_randInt < ((RandStruc*)_b)->m_randInt )
	{
		return 1;
	}
	return 0;
}

/*equal function */
int RandStrucIsEqual(void* _a, void* _b)
{
	if (_a == NULL || _b == NULL)
	{
		return 0;
	}
	if (_a == _b)
	{
		return 1;
	}
	return 0;
}

void CreateTest()
{
	List* myList = List_Create();
	if (myList != NULL)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_Destroy(&myList, NULL);
}

void DestroyTest()
{
	List* myList;
	List_Destroy(NULL, NULL);
	myList = List_Create();
	List_Destroy(&myList, NULL);
	if (myList == NULL)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_Destroy(&myList, NULL);
	List_Destroy(&myList, NULL);
}

void DestroyTest2()
{
	List* myList = List_Create();
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s2p = (RandStruc*)malloc(sizeof(RandStruc));
	List_PushTail(myList,(void*)s1p);
	List_PushHead(myList,(void*)s2p);
	List_Destroy(&myList, RandStrucDestroy);
	if (myList == NULL)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_Destroy(&myList, RandStrucDestroy);
	List_Destroy(&myList, RandStrucDestroy);
}

void PushTailTest()
{
	List* myList = List_Create();
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	s1p->m_randInt = 5;
	s1p->m_randChar = 'c';
	s1p->m_randFloat = 644.5;
	if ( List_PushTail(NULL,(void*)s1p) == LIST_UNINITIALIZED_ERROR)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( List_PushTail(myList,s1p) == LIST_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_Destroy(&myList, RandStrucDestroy);
}

void PushHeadTest()
{
	List* myList = List_Create();
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	s1p->m_randInt = 5;
	s1p->m_randChar = 'c';
	s1p->m_randFloat = 644.5;
	if ( List_PushHead(NULL,(void*)s1p) == LIST_UNINITIALIZED_ERROR)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( List_PushHead(myList,s1p) == LIST_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_Destroy(&myList, RandStrucDestroy);
}

void PushHeadTest2()
{
	List* myList = List_Create();
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s2p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s3p = (RandStruc*)malloc(sizeof(RandStruc));
	if ( List_PushHead(myList,s1p) == LIST_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( List_PushHead(myList,s2p) == LIST_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( List_PushHead(myList,s3p) == LIST_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_Destroy(&myList, RandStrucDestroy);
}

void PushTailTest2()
{
	List* myList = List_Create();
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s2p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s3p = (RandStruc*)malloc(sizeof(RandStruc));
	if ( List_PushTail(myList,s1p) == LIST_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( List_PushTail(myList,s2p) == LIST_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( List_PushTail(myList,s3p) == LIST_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_Destroy(&myList, RandStrucDestroy);
}

void PushHeadTailTest()
{
	List* myList = List_Create();
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s2p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s3p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s4p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s5p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s6p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s7p = (RandStruc*)malloc(sizeof(RandStruc));
	if ( List_PushTail(myList,s1p) == LIST_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( List_PushHead(myList,s2p) == LIST_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( List_PushTail(myList,s3p) == LIST_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( List_PushHead(myList,s4p) == LIST_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( List_PushHead(myList,s5p) == LIST_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( List_PushTail(myList,s6p) == LIST_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( List_PushTail(myList,s7p) == LIST_SUCCESS)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_Destroy(&myList, RandStrucDestroy);
}

void ListSizeTest()
{
	List* myList = List_Create();
	void* temp;
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s2p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s3p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s4p = (RandStruc*)malloc(sizeof(RandStruc));
	List_PushTail(myList,s1p);
	if (List_Size(myList) == 1)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_PushHead(myList,s2p);
	List_PushTail(myList,s3p);
	List_PushTail(myList,s4p);
	if (List_Size(myList) == 4)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_PopHead(myList, &temp);
	if (List_Size(myList) == 3)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_PopHead(myList, &temp);
	List_PopHead(myList, &temp);
	List_PopHead(myList, &temp);
	if (List_Size(myList) == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_PopHead(myList, &temp);
	if (List_Size(myList) == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_Destroy(&myList, RandStrucDestroy);
}

void PopTest()
{
	List* myList = List_Create();
	void* temp;
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s2p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s3p = (RandStruc*)malloc(sizeof(RandStruc));
	List_PushTail(myList,s1p);
	List_PushTail(myList,s2p);
	List_PushTail(myList,s3p);
	List_PopHead(myList, &temp);
	if (temp == s1p)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_PopTail(myList, &temp);
	if (temp == s3p)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_PopHead(myList, &temp);
	if (temp == s2p)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if (List_PopHead(myList, &temp) == LIST_UNDERFLOW)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if (List_PopHead(NULL, &temp) == LIST_UNINITIALIZED_ERROR)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if (List_PopHead(myList,NULL) == LIST_NULL_ELEMENT_ERROR)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
}

void ListItr_BeginTest()
{
	List* myList = List_Create();
	ListItr iterator;
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s2p = (RandStruc*)malloc(sizeof(RandStruc));
	iterator = ListItr_Begin(myList);
	if(iterator == ListItr_Begin(myList))
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_PushTail(myList,s1p);
	List_PushTail(myList,s2p);
	iterator = ListItr_Begin(myList);	
	if(ListItr_Get(iterator) == s1p)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_Destroy(&myList, RandStrucDestroy);
}

void ListItr_EndTest()
{
	ListItr iterator;
	List* myList = List_Create();
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s2p = (RandStruc*)malloc(sizeof(RandStruc));
	iterator = ListItr_End(myList);
	if(iterator == ListItr_Begin(myList))
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_PushTail(myList,s1p);
	List_PushTail(myList,s2p);
	if(iterator == ListItr_End(myList))
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_Destroy(&myList, RandStrucDestroy);
}

void ListItr_EqualsTest()
{
	List* myList = List_Create();
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	if (ListItr_Equals(ListItr_End(myList),ListItr_Begin(myList)) == 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_PushTail(myList,s1p);
	if (ListItr_Equals(ListItr_End(myList),ListItr_Begin(myList)) != 0)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_Destroy(&myList, RandStrucDestroy);
}

void ListItr_NextTest()
{
	List* myList = List_Create();
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s2p = (RandStruc*)malloc(sizeof(RandStruc));
	if (ListItr_Next(ListItr_Begin(myList)) == ListItr_End(myList))
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_PushTail(myList,s1p);
	if (ListItr_Next(ListItr_Begin(myList)) == ListItr_End(myList))
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_PushTail(myList,s2p);
	if (ListItr_Next(ListItr_Begin(myList)) != ListItr_End(myList))
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_Destroy(&myList, RandStrucDestroy);
}

void ListItr_PrevTest()
{
	List* myList = List_Create();
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	if (ListItr_Prev(ListItr_End(myList)) == ListItr_End(myList))
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_PushTail(myList,s1p);
	if (ListItr_Prev(ListItr_End(myList)) == ListItr_Begin(myList))
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_Destroy(&myList, RandStrucDestroy);
}

void ListItr_GetSetTest()
{
	List* myList = List_Create();
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s2p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s3p = (RandStruc*)malloc(sizeof(RandStruc));
	List_PushTail(myList,s1p);
	List_PushTail(myList,s2p);
	if (ListItr_Get(ListItr_Next(ListItr_Begin(myList))) == s2p)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if (ListItr_Get(ListItr_Begin(myList)) == s1p)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if (ListItr_Get(ListItr_End(myList)) == NULL)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( ListItr_Set (ListItr_Begin(myList),s3p) == s1p)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if (ListItr_Get(ListItr_Begin(myList)) == s3p)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	free(s1p);
	List_Destroy(&myList, RandStrucDestroy);
}

void ListItr_InsertBeforeTest()
{
	List* myList = List_Create();
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	if ( ListItr_InsertBefore(ListItr_Begin(myList),s1p) == ListItr_Begin(myList))
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	List_Destroy(&myList, RandStrucDestroy);
}

void ListItr_RemoveTest()
{
	List* myList = List_Create();
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	ListItr_InsertBefore(ListItr_Begin(myList),s1p);
	if ( ListItr_Remove(ListItr_Begin(myList)) == s1p)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	free(s1p);
	List_Destroy(&myList, RandStrucDestroy);
}

void ListItr_FindFirstTest()
{
	List* myList = List_Create();
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s2p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s3p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s4p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s5p = (RandStruc*)malloc(sizeof(RandStruc));
	s1p->m_randInt = 10;
	s2p->m_randInt = 20;
	s3p->m_randInt = 30;
	s4p->m_randInt = 20;
	s5p->m_randInt = 50;
	List_PushTail(myList,s1p);
	List_PushTail(myList,s2p);
	List_PushTail(myList,s3p);
	if (ListItr_FindFirst(ListItr_Begin(myList), ListItr_End(myList), RandStrucIsIntEqual , s5p) == ListItr_End(myList))
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if (ListItr_FindFirst(ListItr_Begin(myList), ListItr_End(myList), RandStrucIsIntEqual , s4p) != ListItr_End(myList))
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	free(s4p);
	free(s5p);
	List_Destroy(&myList, RandStrucDestroy);
}

void ListItr_CountIfTest()
{
	List* myList = List_Create();
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s2p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s3p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s4p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s5p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s6p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s7p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s8p = (RandStruc*)malloc(sizeof(RandStruc));
	s1p->m_randInt = 10;
	s2p->m_randInt = 20;
	s3p->m_randInt = 30;
	s4p->m_randInt = 10;
	s5p->m_randInt = 10;
	s6p->m_randInt = 50;
	s7p->m_randInt = 10;
	s8p->m_randInt = 10;
	List_PushTail(myList,s1p);
	List_PushTail(myList,s2p);
	List_PushTail(myList,s3p);	
	List_PushTail(myList,s4p);
	List_PushTail(myList,s5p);
	List_PushTail(myList,s6p);	
	List_PushTail(myList,s7p);
	if ( ListItr_CountIf(ListItr_Begin(myList), ListItr_End(myList), RandStrucIsIntEqual , s4p) == 4)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	free(s8p);
	List_Destroy(&myList, RandStrucDestroy);
}

void ListItr_ForEachTest()
{
	List* myList = List_Create();
	RandStruc* s1p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s2p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s3p = (RandStruc*)malloc(sizeof(RandStruc));
	RandStruc* s4p = (RandStruc*)malloc(sizeof(RandStruc));
	s1p->m_randInt = 10;
	s2p->m_randInt = 20;
	s3p->m_randInt = 30;
	s4p->m_randInt = 5;
	List_PushTail(myList,s1p);
	List_PushTail(myList,s2p);
	List_PushTail(myList,NULL);
	List_PushTail(myList,s3p);
	if (ListItr_ForEach(ListItr_Begin(myList), ListItr_End(myList), RandStrucIntAdd , s4p) == ListItr_Next ( ListItr_Next( ListItr_Begin(myList) )))
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( s1p->m_randInt == 15)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( s2p->m_randInt == 25)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	if ( s3p->m_randInt == 30)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	free(s4p);
	List_Destroy(&myList, RandStrucDestroy);
}

int main()
{
	printf("\nCreateTest\n");
	CreateTest();
	printf("\nDestroyTest\n");
	DestroyTest();
	printf("\nDestroyTest2\n");
	DestroyTest2();
	printf("\nPushHeadTest\n");
	PushHeadTest();
	printf("\nPushHeadTest2\n");
	PushHeadTest2();
	printf("\nPushTailTest\n");
	PushTailTest();
	printf("\nPushTailTest2\n");
	PushTailTest2();
	printf("\nPushHeadTailTest\n");
	PushHeadTailTest();
	printf("\nListSizeTest\n");
	ListSizeTest();
	printf("\nPopTest\n");
	PopTest();
	printf("\nListItr_BeginTest\n");
	ListItr_BeginTest();
	printf("\nListItr_EndTest\n");
	ListItr_EndTest();
	printf("\nListItr_EqualsTest\n");
	ListItr_EqualsTest();
	printf("\nListItr_NextTest\n");
	ListItr_NextTest();
	printf("\nListItr_PrevTest\n");
	ListItr_PrevTest();
	printf("\nListItr_GetSetTest\n");
	ListItr_GetSetTest();
	printf("\nListItr_InsertBeforeTest\n");
	ListItr_InsertBeforeTest();
	printf("\nListItr_RemoveTest\n");
	ListItr_RemoveTest();
	printf("\nListItr_FindFirstTest\n");
	ListItr_FindFirstTest();
	printf("\nListItr_CountIfTest\n");
	ListItr_CountIfTest();
	printf("\nListItr_ForEachTest\n");
	ListItr_ForEachTest();
	
	return 1;
}
