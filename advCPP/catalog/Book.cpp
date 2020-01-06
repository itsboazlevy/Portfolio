#include "./include/Book.h"

Book::Book(std::string _isbn, std::string _title, const Author* _authorPtr, std::string _year, const Publisher* _publisherPtr)
: m_isbn(_isbn)
, m_title(_title)
, m_year(_year)
, m_authorPtr(_authorPtr)
, m_publisherPtr(_publisherPtr)
{

}

const std::string& Book::GetTitle() const
{
	return m_title;
}

const ISBN& Book::GetISBN() const
{
	return m_isbn;
}

void Book::Print() const
{
	std::cout << m_isbn.GetISBN() << "|" << m_title << "|" << m_authorPtr->GetAuthor() << 
	"|" << m_year.GetYear() << "|" << m_publisherPtr->GetPublisher() << std::endl;	
}
	
