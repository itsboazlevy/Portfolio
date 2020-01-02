#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "binaryTreeFunctions.h"
#define MAGIC_NUM 123456789

struct Node
{
	int m_data;
	Node* m_left;
	Node* m_right;
	Node* m_father;
}; 

struct Tree
{
	Node* m_root;
	int m_magicNum;
};

static void NodesDestroy(Node* _root)
{
	if (_root == NULL)
	{
		return;
	}
	NodesDestroy(_root->m_left);
	NodesDestroy(_root->m_right);
	free(_root);
}

static void NodeInsert(Node* _root,Node* _myNode)
{
	if (_root->m_data == _myNode->m_data)
	{
		return;
	}
	if (_root->m_data > _myNode->m_data)
	{
		if (_root->m_left == NULL)
		{
			_root->m_left = _myNode;
		}
		else
		{
			NodeInsert(_root->m_left ,_myNode);
		}
	}
	if (_root->m_data < _myNode->m_data)
	{
		if (_root->m_right == NULL)
		{
			_root->m_right = _myNode;
		}
		else
		{
			NodeInsert(_root->m_right ,_myNode);
		}
	}
	return;
}

static void NodeIsDataFound(Node* _root,int _data,int* status)
{
	if (_root == NULL )	
		{
			return;
		}
	if (_root->m_data == _data )	
		{
			*status = 1;
			return;
		}
	NodeIsDataFound(_root->m_left,_data,status);
	NodeIsDataFound(_root->m_right,_data,status);
	return;
}

static void PreOrderPrint(Node* _root)
{
	if (_root == NULL)	
	{
		return;
	}
	printf("%d ",_root->m_data);
	PreOrderPrint(_root->m_left);
	PreOrderPrint(_root->m_right);
	return;
}

static void InOrderPrint(Node* _root)
{
	if (_root == NULL )	
	{
		return;
	}

	InOrderPrint(_root->m_left);
	printf("%d ",_root->m_data);
	InOrderPrint(_root->m_right);
	return;
}

static void PostOrderPrint(Node* _root)
{
	if (_root == NULL )	
	{
		return;
	}
	PostOrderPrint(_root->m_left);
	PostOrderPrint(_root->m_right);
	printf("%d ",_root->m_data);
	return;
}

Tree* TreeCreate()
{
	Tree* myTree;
	myTree = (Tree*)malloc(sizeof(Tree));
	if (myTree == NULL)
	{
		return NULL;
	}
	myTree->m_root = NULL;
	myTree->m_magicNum = MAGIC_NUM;
	return myTree;
}

void TreeDestroy(Tree* _tree)
{
	if (_tree == NULL || _tree->m_magicNum != MAGIC_NUM)	
	{
		return;
	}
	NodesDestroy(_tree->m_root);
	_tree->m_magicNum = 0;
	free(_tree);
	return;
}

ADTErr TreeInsert(Tree* _tree, int _data)
{
	Node* myNode;
	if (_tree == NULL || _tree->m_magicNum != MAGIC_NUM)
	{
		return NULL_ERR;
	}
	myNode = (Node*)calloc(1,sizeof(Node));
	if (myNode == NULL)
	{
		return ALLOC_ERR;
	}
	myNode->m_data = _data;
	if (_tree->m_root == NULL)
	{
		_tree->m_root = myNode;
		return SUCCESS;
	}
	NodeInsert(_tree->m_root,myNode);
	return SUCCESS;
}

int TreeIsDataFound(Tree* _tree,int _data)
{
	int status = 0;
	if (_tree == NULL || _tree->m_magicNum != MAGIC_NUM)	
	{
		return NULL_ERR;
	}
	NodeIsDataFound(_tree->m_root,_data,&status);
	return status;
}

void TreePrint(Tree* _tree, TreeTraverse _traverseMode)
{
	if (_tree == NULL || _tree->m_magicNum != MAGIC_NUM)
	{
		printf("BST doesnt exist");
		return;
	}
	switch (_traverseMode)
	{
		case PRE_ORDER: PreOrderPrint(_tree->m_root);
						break;
		case IN_ORDER: InOrderPrint(_tree->m_root);
						break;
		case POST_ORDER: PostOrderPrint(_tree->m_root);
						break;
	}
}

static int IsFullTreeCheck (Node* _root)
{
	if (_root == NULL)
	{
		return SUCCESS;
	}
	if ((_root->m_right != NULL && _root->m_left == NULL) || (_root->m_right == NULL && _root->m_left != NULL))
	{
		return FAIL;
	}
	return IsFullTreeCheck(_root->m_left) * IsFullTreeCheck(_root->m_right); 	
}

int IsFullTree(Tree* _tree) 
{
	if(_tree == NULL)
	{
		return FAIL;
	}
	return IsFullTreeCheck ( _tree->m_root);
}

static int IsSimilarTreesCheck(Node* _root1, Node* _root2) 
{
	if (_root1 == _root2)
	{
		return SUCCESS;
	}
	if	(	_root1->m_data != _root2->m_data ||
		(	_root1->m_right != NULL && _root2->m_right == NULL) ||
		(	_root2->m_right != NULL && _root1->m_right == NULL) || 
		(	_root1->m_left != NULL && _root2->m_left == NULL)  || 
		(	_root2->m_left != NULL && _root1->m_left == NULL) )
	{
		return FAIL;
	}
	return IsSimilarTreesCheck(_root1->m_left,_root2->m_left)*	IsSimilarTreesCheck(_root1->m_right,_root2->m_right); 
}

int IsSimilarTrees(Tree* _tree1, Tree* _tree2) 
{
	if(_tree1 == NULL || _tree2 == NULL)
	{
		return FAIL;
	}
	return IsSimilarTreesCheck(_tree1->m_root, _tree2->m_root);
}

static int FindTreeHightCheck(Node* _root)
{
	if (_root == NULL)
	{
		return -1;
	}
	if (_root->m_right == NULL && _root->m_left == NULL)
	{
		return 0;
	}
	if (FindTreeHightCheck(_root->m_left) > FindTreeHightCheck(_root->m_right)) 
	{
		return (FindTreeHightCheck(_root->m_left) + 1);
	}
	else
	{
		return (FindTreeHightCheck(_root->m_right) + 1);
	}
}

int FindTreeHight(Tree* _tree)
{
	if(_tree == NULL)
	{
		return NULL_ERR;
	}
	return FindTreeHightCheck(_tree->m_root);
}

static int IsPerfectTreeCheck(Node* _root)
{
	if (_root == NULL)
	{
		return SUCCESS;
	}
	if (_root->m_left == NULL && _root->m_right == NULL)
	{
		return SUCCESS;
	}
	if (FindTreeHightCheck(_root->m_left) != FindTreeHightCheck(_root->m_right))
	{
		return FAIL;
	}
	else
	{
		return IsPerfectTreeCheck(_root->m_left) * IsPerfectTreeCheck(_root->m_right); 	
	}
}

int IsPerfectTree(Tree* _tree)
{
	if(_tree == NULL)
	{
		return NULL_ERR;
	}
	return IsPerfectTreeCheck(_tree->m_root);
}


















