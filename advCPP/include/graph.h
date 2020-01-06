#ifndef GRAPH_H
#define GRAPH_H
#include "edge.h"
#include "idHolder.h"
#include <vector>
#include <cstddef>
class Graph
{
public:
	//Graph();
	//~Graph() = default; 
	//Graph& operator = (const Graph&) = default;
	//Graph(const Graph&) = default;
	
	void Add(const IdHolder& _a,const IdHolder& _b);
	bool IsConnected(const IdHolder& _a,const IdHolder& _b) const; 
	void BFS(const IdHolder& _start); //need to add print action and fun ptr
private:
	std::vector<size_t> ids;		
	std::vector<Edge> edges;
};

#endif //GRAPH_H
