#ifndef HUFFTREE_H
#define HUFFTREE_H

#include <queue>
#include <map>
#include "Node.h"

class HuffTree
{
public:
	HuffTree(std::map<char,size_t>& _map);
	~HuffTree();
private:
	HuffTree(const HuffTree&);
	HuffTree& operator = (const HuffTree&);
	std::priority_queue<Node*> M_pQueue; 
};

#endif //HUFFTREE_H
