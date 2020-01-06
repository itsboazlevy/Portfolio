#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include "Agent.h"
#include "Event.h"
#include "Thread.h"
#include "MTQueue.h"
#include "Controller.h"
#include "Sensor.h"

class Server
{

public:
	Server(const std::string& _fileName);
	void AddAgent(std::string _id, std::string _type, std::string _logName, std::string _config, size_t _room, size_t _floor);
	void Initialise(size_t _disThreads);
	const std::vector<Agent*>& GetAgents() const;
	const std::tr1::unordered_map<std::string, std::tr1::unordered_map<size_t, std::set<const Controller*> > >& GetSubscriptions() const;
	MTQueue<Event*>& GetEvents() ;
	void AddEvent(Event* _eventPtr);
	~Server();
private:
	void Subscribe(const Controller* _controllerPtr, const char* _type);
	std::vector<Agent*> m_agents;
	std::vector<Thread*> m_threads;
	std::tr1::unordered_map<std::string, std::tr1::unordered_map<size_t, std::set<const Controller*> > > m_subscriptions;
	MTQueue<Event*> m_events;
};


#endif //SERVER_H


