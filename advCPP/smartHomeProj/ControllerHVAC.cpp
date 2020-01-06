#include <iostream>
#include "ControllerHVAC.h"
using namespace std;

ControllerHVAC::ControllerHVAC (std::string _id, std::string _type, std::string _logName, std::string _config, size_t _room, size_t _floor)
: Controller (_id, _type, _logName, _config, _room, _floor)
{

}

void ControllerHVAC::Run (const Event& _event) const
{
	cout << "Recieved By Controller with ID " << GetId() << " type "  <<  GetType() << " room " << GetRoom() << " floor " << GetFloor() << endl;
	if ( _event.GetType() == "TEMP" )
	{
		if ( _event.GetData() == GetSetVal() )
		{
			cout << "Temp Balanced. HVAC Stops!" << endl;
		}
		else
		{
			cout << "Temp Imbalanced. HVAC Works!" << endl;
		}
	}
	else
	{
		cout << "Fire! HVAC Stops!" << endl;
	}

}

