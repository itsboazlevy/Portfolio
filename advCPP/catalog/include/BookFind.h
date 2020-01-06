#ifndef BOOKFIND_H
#define BOOKFIND_H

#include <string>
#include "Book.h"

class BookFind
{
public:
	virtual ~BookFind() = 0;
	virtual const Book* Find(const ISBN& _isbn) const = 0;
};

#endif //BOOKFIND_H
