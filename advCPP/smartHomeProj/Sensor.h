#ifndef SENSOR_H
#define SENSOR_H

#include <vector>
#include "Agent.h"
#include "Event.h"
#include "MTQueue.h"

class Sensor : public Agent
{
public:
	Sensor (std::string _id, std::string _type, std::string _logName, std::string _config, size_t _room, size_t _floor,  MTQueue<Event*>& _events);
	int GetValMin() const;
	int GetValMax() const;
	int GetPeriod() const;
	MTQueue<Event*>& GetEvents() const;
	virtual void Run() = 0;
private:
	int m_valMin;
	int m_valMax;
	int m_period;
	MTQueue<Event*>& m_events;
};

#endif //SENSOR_H
