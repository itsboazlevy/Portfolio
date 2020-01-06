#include "../include/edge.h"
#include <cstddef>


Edge::Edge(size_t _a, size_t _b)
: idA(_a)
, idB(_b)
{}
	
size_t Edge::getIdA() const
{
	return idA;
}

size_t Edge::getIdB() const
{
	return idB;
}

