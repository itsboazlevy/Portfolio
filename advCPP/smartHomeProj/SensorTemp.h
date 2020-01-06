#ifndef SENSORTEMP_H
#define SENSORTEMP_H

#include <string>
#include "Sensor.h"
#include "Runnable.h"
#include "Thread.h"

class SensorTemp : public Sensor , public Runnable
{
public:
	SensorTemp (std::string _id, std::string _type, std::string _logName, std::string _config, size_t _room, size_t _floor,  MTQueue<Event*>& _events);
	virtual void Run();
	virtual ~SensorTemp();
private:
	Thread m_thread;
};

#endif //SENSORTEMP_H
