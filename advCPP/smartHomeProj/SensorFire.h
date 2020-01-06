#ifndef SENSORFIRE_H
#define SENSORFIRE_H

#include "Sensor.h"
#include "Runnable.h"
#include "Thread.h"

class SensorFire : public Sensor, public Runnable
{
public:
	SensorFire (std::string _id, std::string _type, std::string _logName, std::string _config, size_t _room, size_t _floor,  MTQueue<Event*>& _events);
	virtual void Run();
	virtual ~SensorFire();
private:
	Thread m_thread;
};


extern "C" SensorFire* Creator(std::string _id, std::string _type, std::string _logName, std::string _config, size_t _room, size_t _floor,  MTQueue<Event*>& _events);

#endif //SENSORFIRE_H
