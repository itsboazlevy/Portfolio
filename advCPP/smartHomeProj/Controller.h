#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Agent.h"
#include "Event.h"

class Controller : public Agent
{
public:
	Controller (std::string _id, std::string _type, std::string _logName, std::string _config, size_t _room, size_t _floor);
	int GetSetVal() const;
	int GetRange() const;
	virtual void Run (const Event& _event) const = 0;
private:
	int m_setVal;
	int m_range;
};

#endif //CONTROLLER_H
