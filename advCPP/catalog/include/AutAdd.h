#ifndef AUTADD_H
#define AUTADD_H

#include "Author.h"

class AutAdd
{
public:
	virtual ~AutAdd() = 0;
	virtual void Add(const Author* _autPtr) = 0;
};

#endif //AUTADD_H
