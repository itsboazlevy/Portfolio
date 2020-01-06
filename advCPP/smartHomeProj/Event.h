#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <stddef.h>

class Event 
{
public:
	Event(std::string _type, int _data, size_t _room, size_t _floor);
	const std::string& GetTime() const;
	const std::string& GetType() const;
	size_t GetRoom() const;
	size_t GetFloor() const;
	int GetData() const;
private:
	std::string m_time;
	std::string m_type;
	int m_data;
	size_t m_room;
	size_t m_floor;	
};

#endif //EVENT_H
