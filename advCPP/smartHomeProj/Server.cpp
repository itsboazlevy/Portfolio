#include <iostream>
#include <stdexcept> 
#include <stdlib.h> 
#include <set>
#include <fstream>
#include <dlfcn.h>
#include "Server.h"
#include "Tokenizer.h"
#include "Event.h"
#include "Thread.h"
#include "Distributer.h"
#include "SensorTemp.h"
#include "SensorFire.h"
#include "ControllerHVAC.h"
#include "ControllerSprinkler.h"

using namespace std;

Server::Server(const std::string& _fileName)
{
	ifstream file;
	char buffer[100];
	file.open(_fileName.data(),ifstream::in);
	Tokenizer myTokenizer("*");
	vector<string> agentDetails;
	
	file.getline(buffer,100);
	while ( !file.eof() )
	{ 	
		agentDetails = myTokenizer.Tokenize(buffer);			
		AddAgent(agentDetails[0],agentDetails[1],agentDetails[2],agentDetails[3],atoi(agentDetails[4].data()),atoi(agentDetails[5].data()));
		file.getline(buffer,100);
	}
	file.close();
	Initialise(1);
}

void Server::Subscribe(const Controller* _controllerPtr, const char* _type)
{
		int range = _controllerPtr->GetRange();
		//subscription to global
		if (range == -2)
		{
			tr1::unordered_map<size_t, set<const Controller*> >& mapRef = m_subscriptions["GLOBAL"];
			set<const Controller*>& setRef =  mapRef[10001];
			setRef.insert(_controllerPtr);
		}
		//subscription to single type
		else if (range == -1)
		{
			tr1::unordered_map<size_t, set<const Controller*> >& mapRef = m_subscriptions[_type];
			set<const Controller*>& setRef =  mapRef[10001];
			setRef.insert(_controllerPtr);
		}
		//subscription to single type+room
		else if (range == 0)
		{
			tr1::unordered_map<size_t, set<const Controller*> >& mapRef = m_subscriptions[_type];
			set<const Controller*>& setRef =  mapRef[_controllerPtr->GetFloor()*100+_controllerPtr->GetRoom()];
			setRef.insert(_controllerPtr);
		}
		//subscription to type+floors
		else if (range > 0)
		{
			tr1::unordered_map<size_t, set<const Controller*> >& mapRef = m_subscriptions[_type];
			set<const Controller*>& setRef =  mapRef[_controllerPtr->GetFloor()*100]; 
			int i;
			for (i = 0; i < range; i++)
			{
				setRef =  mapRef[(_controllerPtr->GetFloor()+i)*100];
				setRef.insert(_controllerPtr);
				setRef =  mapRef[(_controllerPtr->GetFloor()-i)*100];
				setRef.insert(_controllerPtr);
			}
		}
}

void Server::AddAgent(string _id, string _type, string _logName, string _config, size_t _room, size_t _floor)
{

	if ( _type == "STEMP" )
	{
		SensorTemp* agentPtr = new SensorTemp(_id, &(_type[1]), _logName, _config, _room, _floor, m_events);
		m_agents.push_back(agentPtr);
	}
	else if ( _type == "SFIRE" )
	{
		void* ptr = dlopen("./SensorFire.so",RTLD_LAZY);
		SensorFire* (*getSensor) (string _id, string _type, string _logName, string _config, size_t _room, size_t _floor,  MTQueue<Event*>& _events);
		*(void**)(&getSensor) = dlsym(ptr, "Creator");
		SensorFire* agentPtr = getSensor(_id, &(_type[1]), _logName, _config, _room, _floor, m_events);
		
		m_agents.push_back(agentPtr);
	}
	else if ( _type == "CSPRINKLER" )
	{
		ControllerSprinkler* agentPtr = new ControllerSprinkler(_id, &(_type[1]), _logName, _config, _room, _floor);
		Subscribe(agentPtr,"FIRE");
		m_agents.push_back(agentPtr);
	}
	else if ( _type == "CHVAC" )
	{
		ControllerHVAC* agentPtr = new ControllerHVAC(_id, &(_type[1]), _logName, _config, _room, _floor);
		Subscribe(agentPtr,"FIRE");
		Subscribe(agentPtr,"TEMP");
		m_agents.push_back(agentPtr);
	}
}

void Server::Initialise(size_t _disThreads)
{
	Distributer* newDisPtr = new Distributer(*this);
	Thread* newDisThreadPtr = new Thread(newDisPtr);
	if (newDisThreadPtr == 0)
	{
		throw runtime_error("Distributer Thread Creation Failure");
	}
	m_threads.push_back(newDisThreadPtr);

}


Server::~Server()
{
	// free all pointers within containers, threads of sensors are currently their own responsibility, not joining 
}

const std::vector<Agent*>& Server::GetAgents() const
{
	return m_agents;
}

const std::tr1::unordered_map<std::string, std::tr1::unordered_map<size_t, set<const Controller*> > >& Server::GetSubscriptions() const
{
	return m_subscriptions;
}

MTQueue<Event*>& Server::GetEvents()
{
	return m_events;
}

void Server::AddEvent(Event* _eventPtr)
{
	m_events.Enqueue(_eventPtr);
}


