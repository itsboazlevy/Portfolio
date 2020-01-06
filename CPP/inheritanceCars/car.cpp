#include "car.h"
#include <string.h>
size_t car_t::id = 0;

char* car_t::createFrom(const char* _str)
{
	char* tmp;
	if (_str == NULL)
	{
		tmp = new char[1];
		tmp[0] = '\0';
	}
	else
	{
		tmp = new char[(strlen(_str)+1)];
		strcpy(tmp,_str);
	}
	return tmp;
}

car_t::car_t() 
{
	capacity = createFrom("");
	objID = id;
	id++; 
}

car_t::car_t(const char* _capacity)
{
	capacity = createFrom(_capacity);
	objID = id;
	id++; 	
}

car_t::car_t(const car_t& _carRef)
{
	capacity = createFrom(_carRef.capacity);
	objID = _carRef.objID; 
}

car_t::~car_t()
{
	delete[] capacity;
}

bool car_t::operator < (const car_t& _carRef) const
{
	return ( strcmp(capacity,_carRef.capacity) < 0 );
}

void car_t::setGear (bool _gear)
{
	gear = _gear;
}

void car_t::setName (char _name)
{
	name = _name;
}

bool car_t::getGear () const
{
	return gear;
}


