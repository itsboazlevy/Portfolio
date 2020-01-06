#include <iostream>
#include <stdlib.h>  
#include "Controller.h"
#include "Tokenizer.h"

using namespace std;

Controller::Controller (string _id, string _type, string _logName, string _config, size_t _room, size_t _floor)
: Agent(_id, _type, _logName, _config, _room, _floor)
{
	Tokenizer tok("|");
	vector<string> vec = tok.Tokenize(_config);
	m_setVal = atoi(vec[0].data());
	m_range = atoi(vec[1].data());
}

int Controller::GetSetVal() const
{
	return m_setVal;
}

int Controller::GetRange() const
{
	return m_range;
}
	
