#include <map>
#include <iostream>
#include "CharFreq.h"
#include "HuffTree.h"
using namespace std;

int main()
{
	CharFreq cf("someText.txt");
	std::map<char,size_t> map = cf.Result();
	std::map<char,size_t>::iterator it;
	for (it = map.begin(); it != map.end(); it++)
	{
		cout << it->first << "   " <<  it->second << endl;
	}
	HuffTree ht(cf.Result());
	
	return 1;
} 
