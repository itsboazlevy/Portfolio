#ifndef UNIQUEIDHOLDER_H
#define UNIQUEIDHOLDER_H
#include "idHolder.h"
#include <cstddef>

class UniqueIdHolder: public IdHolder
{
public:
	UniqueIdHolder();
	//~UniqueIdHolder() = default;
	virtual size_t getId() const;
protected:
	static size_t idGenerate;
	size_t id;
private:
	UniqueIdHolder(const UniqueIdHolder&);
	UniqueIdHolder& operator= (const UniqueIdHolder&);
};

#endif // UNIQUEIDHOLDER_H



