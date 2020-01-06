#ifndef PUBADD_H
#define PUBADD_H

#include <string>
#include "Publisher.h"

class PubAdd
{
public:
	virtual ~PubAdd() = 0;
	virtual void Add(const Publisher* _pubPtr) = 0;
};

#endif //PUBADD_H
