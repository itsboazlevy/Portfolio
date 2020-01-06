#include "Node.h"

Node::Node(char _char, size_t _value ,const Node* _left,const Node* _right)
: m_char(_char)
, m_value(_value)
, m_left(_left)
, m_right(_right)
{}

char Node::Char() const
{ 
	return m_char; 
}

size_t Node::Value() const
{ 
	return m_value; 
}

const Node* Node::Left() const
{ 
	return m_left; 
}

const Node* Node::Right() const
{
	return m_right; 
}


bool Node::operator < (const Node _node) const
{
	return _node.Value() > Value();
}
	


