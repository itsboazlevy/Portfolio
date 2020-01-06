#include "./include/ISBN.h"

ISBN::ISBN(const std::string& _isbn)
: m_isbn(_isbn)
{

}

const std::string& ISBN::GetISBN() const
{
	return m_isbn;
}


