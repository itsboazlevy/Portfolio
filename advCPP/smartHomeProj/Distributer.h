#ifndef DISTRIBUTER_H
#define DISTRIBUTER_H

#include <set>
#include <string>
#include "Runnable.h"
#include "Server.h"
#include "Controller.h"

class Distributer : public Runnable
{
public:
	Distributer (Server& _server);
	virtual ~Distributer();
	virtual void Run();
private:
	void AddToDelivery (std::string _key1, size_t _key2);
	Server& m_server;
	std::set<const Controller*> m_delivery;
};

#endif //DISTRIBUTER_H
