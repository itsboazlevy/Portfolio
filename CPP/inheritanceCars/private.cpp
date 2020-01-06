#include "car.h"

private_t::private_t():car_t()
{
	setName('P');
	setGear(0);
}

private_t::private_t(const char* _capacity, bool _gear, size_t _speed):car_t(_capacity)
{
	setName('P');
	setGear(_gear);
	speed = _speed;
}

