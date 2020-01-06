#include "../include/ValNode.h"

ValNode::ValNode(double _val)
{
	m_val = _val; 
}
	
double ValNode::Value() 
{ 
	return m_val; 
}

