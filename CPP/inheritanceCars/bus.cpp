#include "car.h"

bus_t::bus_t():car_t()
{
	setName('B');
	setGear(0);
}

bus_t::bus_t(const char* _capacity, bool _gear, size_t _seatNum, size_t _lineNum):car_t(_capacity)
{
	setName('B');
	setGear(_gear);
	seatNum = _seatNum;
	lineNum = _lineNum;
}

bus_t::bus_t(const bus_t& _busRef):car_t((car_t&) _busRef)
{
	setName('B');
	setGear(_busRef.getGear);
	seatNum = _busRef.getSeatNum;
	lineNum = _busRef.getLineNum;
}

size_t bus_t::getSeatNum () const
{
	return seatNum;	
}
size_t bus_t::getLineNum () const
{
	return lineNum;	
}
