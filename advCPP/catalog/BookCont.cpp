#include "./include/BookCont.h"

const Book* BookCont::Find(const ISBN& _isbn) const
{
	std::tr1::unordered_map<ISBN, const Book*, HashISBN>::const_iterator it;
	it = m_books.find(_isbn);
	if ( it == m_books.end())
	{
		return 0;
	}
	return it->second;
}

void BookCont::Add(const Book* _bookPtr)
{
	m_books.insert(std::pair<ISBN,const Book*>(_bookPtr->GetISBN(), _bookPtr));
}

