#ifndef PUBFIND_H
#define PUBFIND_H
#include <string>
#include "Publisher.h"
class PubFind
{
public:
	virtual ~PubFind() = 0;
	virtual const Publisher* Find(const Publisher& _publisher) const = 0;
};

#endif //PUBFIND_H
