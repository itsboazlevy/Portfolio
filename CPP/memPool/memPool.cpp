#include "memPool.h"

size_t memPool_t::read(char* _data, size_t _length)
{
	/* get relevant page i and sum of previous pages capcities */
	size_t i = 0;
	size_t sumCaps = 0;
	while ( getPos() > data[i]->getCapacity() + sumCaps )
	{
		sumCaps += data[i]->getCapacity();
		i++;
	}
	
	/* reading */
	size_t partLen = 0;
	while( partLen != _length && i < data.size())
	{
		/* reads maximum from page to data*/
		partLen += data[i]->read(_data + partLen, _length - partLen, getPos() - sumCaps );
		/* from second page reads from start */
		sumCaps = getPos();
		i++;
	}
	
	/* updates position */
	setPos(getPos()+ partLen);
	return partLen;
}

size_t memPool_t::read(char* _data, size_t _length, size_t _pos)
{
	if ( _pos > getSize() )
	{
		return 0;
	}
	setPos(_pos);
	return read(_data, _length);
}

size_t memPool_t::write(const char* _data, size_t _length)
{
	/* get relevant page i and sum of previous pages capcities */
	size_t i = 0;
	size_t sumCaps = 0;
	while ( getPos() > data[i]->getCapacity() + sumCaps )
	{
		sumCaps += data[i]->getCapacity();
		i++;
	}
	
	/* writing */
	size_t partLen = 0;
	while( partLen != _length )
	{
		/* writes maximum of data into page*/
		partLen += data[i]->write(_data + partLen, _length - partLen, getPos() - sumCaps );
		/* from second page writes from start */
		sumCaps = getPos();
		/* checks if there is a next page, creates and inserts if not */
		if ( i+1 == data.size() )
		{
			memPage_t* pagePtr = new memPage_t;
			data.insert(data.end(), pagePtr);
		}
		i++;
	}
	
	/* updates size and position */
	if (getPos() + partLen > getSize() )
	{
		setSize( getPos() + partLen); 
	}
	setPos( getPos() + partLen);
	
	return partLen;
}

size_t memPool_t::write(const char* _data, size_t _length, size_t _pos)
{
	if ( _pos > getSize() )
	{
		return 0;
	}
	setPos(_pos);
	return write(_data, _length);
}



