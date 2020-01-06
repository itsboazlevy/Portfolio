#include <iostream>
#include "CharFreq.h"

using namespace std;

CharFreq::CharFreq(const string& _fileName)
{
	ifstream file;
	file.open(_fileName.data(),ifstream::in);
	char i;
	while ( file.get(i) ) 
	{
			++m_map[i]; //subsc operator will insert new with value 0 if i doesnt exist
	}
	file.close();
}

std::map<char, size_t>& CharFreq::Result() 
{
	return m_map;
}	
	

