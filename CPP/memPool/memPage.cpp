#include "memPage.h"
#include <string.h>

size_t memPage_t::defCap = 6;

size_t memPage_t::read(char* _data, size_t _length)
{
	if (_data == NULL)
	{
		return 0;
	}
	if ( _length > getSize() - getPos() )
	{
		_length = getSize() - getPos();
	}
	memcpy(_data, data+getPos(), _length);
	setPos( getPos() + _length);
	return _length;
}

size_t memPage_t::read(char* _data, size_t _length, size_t _pos)
{
	if ( _pos > getSize() || _data == NULL)
	{
		return 0;
	}
	setPos(_pos);
	return read(_data, _length);
}

size_t memPage_t::write(const char* _data, size_t _length)
{	
	if ( _data == NULL)
	{
		return 0;
	}
	if ( _length > getCapacity() - getPos() )
	{
		_length = getCapacity() - getPos();
	}
	memcpy(data+getPos(), _data, _length);
	if (getPos() + _length > getSize() )
	{
		setSize( getPos() + _length); 
	}
	setPos( getPos() + _length);
	return _length;
}

size_t memPage_t::write(const char* _data, size_t _length, size_t _pos)
{
	if ( _pos > getSize() ||  _data == NULL )
	{
		return 0;
	}
	setPos(_pos);
	return write(_data, _length);
}



