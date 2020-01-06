#include <ctime>
#include "Event.h"

using namespace std;

Event::Event(string _type, int _data, size_t _room, size_t _floor)
: m_type(_type)
, m_data(_data)
, m_room(_room)
, m_floor(_floor)
{
	time_t sysTime;
	time (&sysTime);
	m_time = asctime(localtime (&sysTime));
}

const std::string& Event::GetTime() const
{
	return m_time;
}

const std::string& Event::GetType() const
{
	return m_type;
}

size_t Event::GetRoom() const
{
	return m_room;
}

size_t Event::GetFloor() const
{
	return m_floor;
}

int Event::GetData() const
{
	return m_data;
}
