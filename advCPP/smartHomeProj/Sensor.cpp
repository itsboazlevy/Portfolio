#include <stdlib.h>  
#include <iostream>
#include "Sensor.h"
#include "Tokenizer.h"

using namespace std;

Sensor::Sensor (string _id, string _type, string _logName, string _config, size_t _room, size_t _floor, MTQueue<Event*>& _events)
: Agent(_id, _type, _logName, _config, _room, _floor)
, m_events(_events)
{
	Tokenizer tok("|");
	vector<string> vec = tok.Tokenize(_config);
	m_valMin = atoi(vec[0].data());
	m_valMax = atoi(vec[1].data());
	m_period = atoi(vec[2].data());
}

int Sensor::GetValMin() const
{
	return m_valMin;
}

int Sensor::GetValMax() const
{
	return m_valMax;
}

int Sensor::GetPeriod() const
{
	return m_period;
}

MTQueue<Event*>& Sensor::GetEvents() const
{
	return m_events;
}
