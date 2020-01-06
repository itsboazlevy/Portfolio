#include "./include/Author.h"

Author::Author(const std::string& _author)
: m_author(_author)
{

}

const std::string& Author::GetAuthor() const
{
	return m_author;
}

