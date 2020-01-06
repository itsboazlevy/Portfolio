#include "Agent.h"
using namespace std;

Agent::Agent (string _id, string _type, string _logName, string _config, size_t _room, size_t _floor)
: m_id(_id)
, m_type(_type)
, m_logName(_logName)
, m_config(_config)
, m_room(_room)
, m_floor(_floor)
{

}

Agent::~Agent()
{

}

const std::string& Agent::GetId() const
{
	return m_id;
}

const std::string& Agent::GetType() const
{
	return m_type;
}

const std::string& Agent::GetLogName() const
{
	return m_logName;
}

const std::string& Agent::GetConfig() const
{
	return m_config;
}

size_t Agent::GetRoom() const
{
	return m_room;
}

size_t Agent::GetFloor() const
{
	return m_floor;
}	
	
