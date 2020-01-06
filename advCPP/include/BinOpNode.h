#ifndef BINOPNODE_H
#define BINOPNODE_H
#include <exception>
#include "Node.h"

class BinOpNode : public Node
{
public:
	BinOpNode(Node* _left, Node* _right) throw (std::bad_exception);
	virtual double Value() throw (std::bad_exception) = 0;
	Node* Left();
	Node* Right();
private:
	Node* m_left;
	Node* m_right;
};

#endif // BINOPNODE_H
