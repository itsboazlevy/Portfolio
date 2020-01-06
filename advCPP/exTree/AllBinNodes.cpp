#include "../include/AllBinNodes.h"

AddNode::AddNode(Node* _left, Node* _right)
: BinOpNode(_left, _right)
{}

double AddNode::Value() throw()
{
	return (Left()->Value()+Right()->Value()); 
}

SubNode::SubNode(Node* _left, Node* _right)
: BinOpNode(_left, _right)
{}

double SubNode::Value() throw()
{
	return (Left()->Value()-Right()->Value()); 
}

MulNode::MulNode(Node* _left, Node* _right)
: BinOpNode(_left, _right)
{}

double MulNode::Value() throw()
{
	return (Left()->Value()*Right()->Value()); 
}

DivNode::DivNode(Node* _left, Node* _right)
: BinOpNode(_left, _right)
{}

double DivNode::Value() throw (std::bad_exception)
{
	if ( Right()->Value() == 0)
	{
		throw std::bad_exception();	
	}
	return (Left()->Value()/Right()->Value()); 
}

