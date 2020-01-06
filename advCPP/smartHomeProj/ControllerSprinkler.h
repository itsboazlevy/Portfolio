#ifndef CONTROLLERSPRINKLER_H
#define CONTROLLERSPRINKLER_H

#include "Controller.h"
#include "Event.h"

class ControllerSprinkler : public Controller
{
public:
	ControllerSprinkler (std::string _id, std::string _type, std::string _logName, std::string _config, size_t _room, size_t _floor);
	virtual void Run (const Event& _event) const;
};

#endif //CONTROLLERSPRINKLER_H
