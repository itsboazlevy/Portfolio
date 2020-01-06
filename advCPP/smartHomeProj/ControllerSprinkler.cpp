#include <iostream>
#include "ControllerSprinkler.h"
using namespace std;

ControllerSprinkler::ControllerSprinkler (std::string _id, std::string _type, std::string _logName, std::string _config, size_t _room, size_t _floor)
: Controller (_id, _type, _logName, _config, _room, _floor)
{

}

void ControllerSprinkler::Run (const Event& _event) const
{
	cout << "Recieved By Controller with ID " << GetId() << " type "  <<  GetType() << " room " << GetRoom() << " floor " << GetFloor() << endl;
	cout << "Sprinkler Activated!" << endl;
}
