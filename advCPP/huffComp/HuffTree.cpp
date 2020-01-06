#include <iostream>
#include "HuffTree.h"

using namespace std;


HuffTree::HuffTree(map<char,size_t>& _map)
{
	map<char,size_t>::iterator it;
	for (it = _map.begin(); it != _map.end(); it++)
	{
		Node* newNode = new Node(it->first, it->second ,0,0);
		M_pQueue.push( newNode );
	}
	cout << endl << endl << endl << endl;
	while (M_pQueue.size() != 0)
	{
		cout << M_pQueue.top()->Char() << "   " << M_pQueue.top()->Value() << endl;
		M_pQueue.pop();
	}
	
}


HuffTree::~HuffTree()
{
	
}

