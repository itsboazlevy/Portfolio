#ifndef NODE_H
#define NODE_H

class Node
{
public:
	Node();
	virtual ~Node();
	virtual double Value() = 0;
private:
	Node(const Node& _node);
	Node& operator =(const Node& _node);
};

#endif // NODE_H
