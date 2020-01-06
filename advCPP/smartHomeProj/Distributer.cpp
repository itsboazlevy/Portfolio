#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include "Distributer.h"
#include "Sensor.h"

using namespace std;

Distributer::Distributer (Server& _server)
: m_server(_server)
{
	
}

void Distributer::AddToDelivery (string _key1, size_t _key2)
{

	const std::tr1::unordered_map<std::string, std::tr1::unordered_map<size_t, set<const Controller*> > >& subscriptions = m_server.GetSubscriptions();
	std::tr1::unordered_map<std::string, std::tr1::unordered_map<size_t, std::set<const Controller*> > >::const_iterator it;
	std::tr1::unordered_map<size_t, std::set<const Controller*> >::const_iterator it2;

	it = subscriptions.find(_key1);
	if (it != subscriptions.end())
	{
		it2 = it->second.find(_key2);
		if ( it2 != it->second.end() )
		{
			m_delivery.insert(it2->second.begin(),it2->second.end());
		}
	}

}

void Distributer::Run()
{
	for(;;)
	{
		Event* eventPtr = m_server.GetEvents().Dequeue();
		AddToDelivery ("GLOBAL",10001);
		AddToDelivery (eventPtr->GetType(),10001);
		AddToDelivery (eventPtr->GetType(),eventPtr->GetFloor()*100);
		AddToDelivery (eventPtr->GetType(),eventPtr->GetFloor()*100+eventPtr->GetRoom());
		
		for (set<const Controller*>::iterator it = m_delivery.begin(); it!=m_delivery.end(); ++it)
		{
			(*it)->Run(*eventPtr);			
		}
		m_delivery.clear();
		delete eventPtr;
	}
}

Distributer::~Distributer()
{
	
}

