/*
Binary Tree Functions
author: BL
date: 20.2.19
*/

#ifndef __BINARYTREEFUNCTIONS_H__
#define __BINARYTREEFUNCTIONS_H__

/*
Description: Checs if tree is full (0 or 2 children per node)
Input: tree pointer
Output: SUCCESS or FAIL
Errors: FAIL if null pointer
*/
int IsFullTree(Tree* _tree);

/*
Description: checks if 2 trees are identical
Input: 2 tree pointers
Output: SUCCESS or FAIL
Errors: FAIL if null pointers
*/
int IsSimilarTrees(Tree* _tree1, Tree* _tree2);

/*
Description: finds hight of tree
Input: tree pointer
Output: hight: empty tree is -1 in hight. 
Errors: NULL_ERR if null pointer
*/
int FindTreeHight(Tree* _tree);

/*
Description: checks if tree is perfect (all leaves in same hight)
Input: tree pointer
Output: SUCCESS or FAIL
Errors: FAIL if null pointers
*/
int IsPerfectTree(Tree* _tree);

#endif /* __BINARYTREEFUNCTIONS_H__ */
