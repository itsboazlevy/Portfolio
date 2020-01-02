#include <stdio.h>
#include "BST.h"
#include "binaryTreeFunctions.h"



int main()
{
	Tree* myTree = TreeCreate();
	Tree* myTree2 = TreeCreate();
	TreeInsert(myTree, 10);
	TreeInsert(myTree, 20);
	TreeInsert(myTree, 5);
	TreeInsert(myTree, 8);
	TreeInsert(myTree, 13);
	TreeInsert(myTree, 30);
	TreeInsert(myTree, 3);
	TreePrint(myTree,IN_ORDER);
	printf("%d\n",IsFullTree(myTree));

	TreeInsert(myTree2, 3);
	TreeInsert(myTree2, 2);
	TreeInsert(myTree2, 7);
	TreeInsert(myTree2, 5);
	TreeInsert(myTree2, 8);
	
	

	TreePrint(myTree2,IN_ORDER);
	printf("%d\n",IsSimilarTrees(myTree,myTree2));
	
	printf("%d\n",FindTreeHight(myTree2));
	printf("%d\n",IsPerfectTree(myTree2));
	
	return 1;
}

