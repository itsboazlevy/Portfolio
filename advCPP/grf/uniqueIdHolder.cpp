#include <cstddef>
#include "../include/uniqueIdHolder.h"

size_t UniqueIdHolder::idGenerate = 0;

UniqueIdHolder::UniqueIdHolder()
: id(++idGenerate)
{}


size_t UniqueIdHolder::getId() const
{
	return id;
}

