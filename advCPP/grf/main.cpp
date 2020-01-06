#include "../include/vertex.h"
#include "../include/graph.h"

int main()
{
	Graph myG;
	Vertex a,b,c,d,e,f,g,h,i;
	myG.Add(a,b);
	myG.Add(c,d);
	myG.Add(e,f);
	myG.Add(g,h);
	myG.BFS(a);
	return 1;
}

