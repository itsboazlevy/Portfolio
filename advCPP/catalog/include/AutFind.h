#ifndef AUTFIND_H
#define AUTFIND_H

#include <string>
#include "Author.h"

class AutFind
{
public:
	virtual ~AutFind() = 0;
	virtual const Author* Find(const Author& _author) const = 0;
};

#endif //AUTFIND_H
