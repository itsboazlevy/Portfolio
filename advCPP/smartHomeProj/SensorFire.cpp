#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include "SensorFire.h"
#include "Runnable.h"
#include "Thread.h"

using namespace std;

SensorFire::SensorFire (string _id, string _type, string _logName, string _config, size_t _room, size_t _floor,  MTQueue<Event*>& _events)
: Sensor (_id, _type, _logName, _config, _room, _floor, _events)
, m_thread(this)
{
}

void SensorFire::Run()
{
	Event* newEventPtr;
	int data;
	for(;;)
	{
		data = rand() % (GetValMax() - GetValMin()) + GetValMin();
		if ( data == GetValMax()-1 )
		{
			newEventPtr = new Event(GetType(), data ,  GetRoom(), GetFloor());
			GetEvents().Enqueue(newEventPtr);
			cout << "Fire Sensor: FIRE!!" << endl;
		}
		sleep(1);
	}	
}

SensorFire::~SensorFire()
{

}

SensorFire* Creator(string _id, string _type, string _logName, string _config, size_t _room, size_t _floor,  MTQueue<Event*>& _events)
{
	return new SensorFire(_id, _type, _logName, _config, _room, _floor, _events);
}
