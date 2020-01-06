#ifndef BOOKADD_H
#define BOOKADD_H

#include <string>
#include "Book.h"

class BookAdd
{
public:
	virtual ~BookAdd() = 0;
	virtual void Add(const Book* _bookPtr) = 0;
};

#endif //BOOKADD_H
