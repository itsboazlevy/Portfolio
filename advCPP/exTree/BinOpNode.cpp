#include "../include/BinOpNode.h"

BinOpNode::BinOpNode(Node* _left, Node* _right) throw (std::bad_exception)
{ 
	if( _left == 0 || _right == 0)
	{
		throw std::bad_exception();
	} 
	m_left = _left; 
	m_right = _right;
} 
	
Node* BinOpNode::Left() 
{ 
	return m_left; 
}

Node* BinOpNode::Right()
{
	return m_right; 
}


