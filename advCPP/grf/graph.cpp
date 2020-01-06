#include <cstddef>
#include <vector>
#include <algorithm>
#include <iostream>
#include "../include/graph.h"
#include "../include/edge.h"
using namespace std;


bool Graph::IsConnected(const IdHolder& _a,const IdHolder& _b) const
{
	int i;
	bool flag = 0;
	for (i = 0; i < edges.size(); i++)
	{
		if ( ( edges[i].getIdA() == _a.getId() && edges[i].getIdB() == _b.getId() ) 
		|| ( edges[i].getIdA() == _b.getId() && edges[i].getIdB() == _a.getId() ) )
		{
			flag = 1;
			break;
		}
	}
}


void Graph::Add(const IdHolder& _a,const IdHolder& _b)
{
	// checks if ids exist, if not inserts them, not ordered
	if (  find( ids.begin(), ids.end(), _a.getId()) == ids.end() )
	{
		ids.push_back (_a.getId());
	}
	if (  find( ids.begin(), ids.end(), _b.getId()) == ids.end() )
	{
		ids.push_back (_b.getId());
	}
	
	// if not connected connect it 
	if (!IsConnected(_a,_b))
	{
		Edge newEdge(_b.getId(),_a.getId());
		edges.push_back (newEdge);
	}
	return;
}

void Graph::BFS(const IdHolder& _start) // this function needs to go by BFS , starting at start and doing an action func on elements
{
	int i;		
	for (i = 0; i < ids.size(); i++)
	{
		cout << ids[i] << endl;
	} 
}

