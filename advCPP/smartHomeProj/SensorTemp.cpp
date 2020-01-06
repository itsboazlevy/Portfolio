#include <time.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include "SensorTemp.h"
#include "Runnable.h"
#include "Thread.h"
using namespace std;

SensorTemp::SensorTemp (std::string _id, std::string _type, std::string _logName, std::string _config, size_t _room, size_t _floor,  MTQueue<Event*>& _events)
: Sensor (_id, _type, _logName, _config, _room, _floor, _events)
, m_thread(this)
{
}


void SensorTemp::Run()
{
	time_t sysTime;
	Event* newEventPtr;
	int data;
	for(;;)
	{
		if ( time (&sysTime) % GetPeriod() == 0)
		{
			data = rand() % (GetValMax() - GetValMin()) + GetValMin();
			newEventPtr = new Event(GetType(), data ,  GetRoom(), GetFloor());
			GetEvents().Enqueue(newEventPtr);
			cout << "Temp Sensor: temp is " << data << endl;
		}
		sleep(1);
	}			
}

SensorTemp::~SensorTemp()
{

}
