#ifndef WORDADD_H
#define WORDADD_H

#include <string>
#include "Book.h"

class WordAdd
{
public:
	virtual ~WordAdd() = 0;
	virtual void Add(std::string _word, const Book* _bookPtr) = 0;
};

#endif //WORDADD_H
