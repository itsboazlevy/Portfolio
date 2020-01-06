#ifndef EDGE_H
#define EDGE_H
#include <cstddef>
#include "vertex.h"

class Edge
{
public:
	Edge(size_t _a, size_t _b);
	//~Edge();
	//Edge& operator = (const Edge&) = default;
	//Edge(const Edge&) = default;
	size_t getIdA() const;
	size_t getIdB() const;
private:
	size_t idA;
	size_t idB;
};

#endif //EDGE_E
