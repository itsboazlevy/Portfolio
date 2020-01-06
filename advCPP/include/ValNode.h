#ifndef VALNODE_H
#define VALNODE_H
#include "Node.h"

class ValNode : public Node
{
public:
	ValNode(double _val = 0);
	//~Value() = default;
	virtual double Value();
private:
	double m_val;
};

#endif //VALNODE_H
