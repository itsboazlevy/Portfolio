#ifndef ALLBINNODES_H
#define ALLBINNODES_H
#include "BinOpNode.h"

class AddNode : public BinOpNode
{
public:
	AddNode(Node* _left, Node* _right);
	//~AddNode() = default;
	virtual double Value() throw();
	//Node* Left() { return m_left; }
	//Node* Right() { return m_right; }
private:
	//Node* m_left;
	//Node* m_right;
};

class SubNode : public BinOpNode
{
public:
	SubNode(Node* _left, Node* _right);
	//~AddNode() = default;
	virtual double Value() throw();
	//Node* Left() { return m_left; }
	//Node* Right() { return m_right; }
private:
	//Node* m_left;
	//Node* m_right;
};

class MulNode : public BinOpNode
{
public:
	MulNode(Node* _left, Node* _right);
	//~AddNode() = default;
	virtual double Value() throw();
	//Node* Left() { return m_left; }
	//Node* Right() { return m_right; }
private:
	//Node* m_left;
	//Node* m_right;
};

class DivNode : public BinOpNode
{
public:
	DivNode(Node* _left, Node* _right);
	//~AddNode() = default;
	virtual double Value() throw (std::bad_exception);
	//Node* Left() { return m_left; }
	//Node* Right() { return m_right; }
private:
	//Node* m_left;
	//Node* m_right;
};

#endif //ALLBINNODES_H
