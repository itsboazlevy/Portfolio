#include <iostream>
#include "../include/AllBinNodes.h"
#include "../include/ValNode.h"
using namespace std;

int main()
{
	ValNode x(20);
	ValNode y(5);
	AddNode xy1(&x,&y); 
	SubNode xy2(&x,&y); 
	MulNode xy3(&x,&y); 
	DivNode xy4(&x,&y); 	
	cout <<  xy1.Value() << endl;
	cout <<  xy2.Value() << endl;
	cout <<  xy3.Value() << endl;
	cout <<  xy4.Value() << endl;
	return 1;
}
