#include "./include/AutCont.h"

const Author* AutCont::Find(const Author& _author) const
{
	std::tr1::unordered_map<Author, const Author*, HashAuthor>::const_iterator it;
	it = m_authors.find(_author);
	if ( it == m_authors.end())
	{
		return 0;
	}
	return it->second;
}

void AutCont::Add(const Author* _autPtr)
{
	 m_authors.insert(std::pair<Author,const Author*>(*_autPtr,_autPtr));
}
