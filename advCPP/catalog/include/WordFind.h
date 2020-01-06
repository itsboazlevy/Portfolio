#ifndef WORDFIND_H
#define WORDFIND_H

#include <string>
#include <vector>
#include "Book.h"

class WordFind
{
public:
	virtual ~WordFind() = 0;
	virtual const std::vector<const Book*>* Find(std::string _word) const = 0;
};

#endif //WORDFIND_H
