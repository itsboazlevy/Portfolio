#ifndef CONTROLLERHVAC_H
#define CONTROLLERHVAC_H

#include "Controller.h"
#include "Event.h"

using namespace std;

class ControllerHVAC : public Controller
{
public:
	ControllerHVAC (std::string _id, std::string _type, std::string _logName, std::string _config, size_t _room, size_t _floor);
	virtual void Run (const Event& _event) const;
};

#endif //CONTROLLERHVAC_H
