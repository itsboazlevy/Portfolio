#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include "ISBN.h"
#include "Year.h"
#include "Author.h"
#include "Publisher.h"

class Book
{
public:
	Book(std::string _isbn, std::string _title, const Author* _authorPtr, std::string _year, const Publisher* _publisherPtr);
	const std::string& GetTitle() const;
	const ISBN& GetISBN() const;
	void Print() const;
private:
	const ISBN m_isbn;
	const std::string m_title;
	const Year m_year;
	const Author* m_authorPtr;
	const Publisher* m_publisherPtr;

};

#endif //BOOK_H
