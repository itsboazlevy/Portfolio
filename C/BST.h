/*
BST ADT - Binary Search Tree Abstract Data Type
author: BL
date: 19.2.19
*/

#ifndef __BST_H__
#define __BST_H__

typedef struct Node Node;
typedef struct Tree Tree;

typedef enum
{
	FAIL,
	SUCCESS,
	ALLOC_ERR,
	NULL_ERR = 1000
}ADTErr;

typedef enum
{
	PRE_ORDER,
	IN_ORDER,
	POST_ORDER
}TreeTraverse;

/*
Description: Creates BST
Input: None
Output: Pointer to BST 
Errors: NULL if allocation failed
*/
Tree* TreeCreate();

/*
Description: Destroys BST and all of its nodes
Input: Pointer to BST
Output: None
Errors: None
*/
void TreeDestroy(Tree* _tree);

/*
Description: Inserts new node with given data to BST
Input: Pointer to BST, data to insert
Output: 
Errors: None
*/
ADTErr TreeInsert(Tree* _tree, int _data);

/*
Description: Checks if there is a node with given data
Input: Pointer to BST, data to search
Output: SUCCESS if exists, FAIL if doesnt
Errors: NULL_ERR if BST pointer is null
*/
int TreeIsDataFound(Tree* _tree,int _data);

/*
Description: Prints BST 
Input: Pointer to BST, Print Mode PRE_ORDER, IN_ORDER, POST_ORDER
Output: Prints BST or a message if BST doesnt exist
Errors: None
*/
void TreePrint(Tree* _tree, TreeTraverse _traverseMode);


int IsFullTree(Tree* _tree);
int IsSimilarTrees(Tree* _tree1, Tree* _tree2) ;
int FindTreeHight(Tree* _tree);
int IsPerfectTree(Tree* _tree);

#endif /* __BST_H__ */
