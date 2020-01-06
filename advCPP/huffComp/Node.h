#ifndef NODE_H
#define NODE_H
#include <cstddef>

class Node
{
public:
	Node(char _char, size_t _value ,const Node* _left,const Node* _right);
	// ~Node() = default;
	char Char() const;
	size_t Value() const;
	const Node* Left() const;
	const Node* Right() const;
	bool operator < (const Node _node) const;
private:
	Node(const Node& _node);
	Node& operator =(const Node& _node);
	char m_char;
	size_t m_value;
	const Node* m_left;
	const Node* m_right;
};

#endif // NODE_H
