#ifndef BOOKCONT_H
#define BOOKCONT_H

#include <string>
#include <tr1/unordered_map>
#include "Book.h"
#include "BookFind.h"
#include "BookAdd.h"

class BookCont : public BookAdd, public BookFind
{
public:
	virtual const Book* Find(const ISBN& _isbn) const;
	virtual void Add(const Book* _bookPtr);
private:
	std::tr1::unordered_map<ISBN, const Book*, HashISBN> m_books;
};

#endif //BOOKCONT_H
