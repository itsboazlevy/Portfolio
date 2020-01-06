#ifndef IDHOLDER_H
#define IDHOLDER_H
#include <cstddef>
class IdHolder
{
public:
	//ABC
	virtual ~IdHolder() = 0;
	virtual size_t getId() const = 0;
};

#endif // IDHOLDER_H



