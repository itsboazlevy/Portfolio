#include "./include/WordCont.h"

const std::vector<const Book*>* WordCont::Find(std::string _word) const
{
	std::tr1::unordered_map< std::string, std::vector<const Book*> >::const_iterator it;
	it = m_words.find(_word);
	if ( it == m_words.end())
	{
		return 0;
	}
	return &(it->second);
}

void WordCont::Add(std::string _word, const Book* _bookPtr)
{	
	std::tr1::unordered_map< std::string, std::vector<const Book*> >::const_iterator it;
	it = m_words.find(_word);
	if ( it == m_words.end())
	{
		std::vector<const Book*> newVec;
		newVec.push_back(_bookPtr);
		m_words.insert(std::pair< std::string, std::vector<const Book*> >(_word,newVec));
	}
	else
	{
		std::vector<const Book*>::const_iterator it2;
  		it2 = find (it->second.begin(), it->second.end(), _bookPtr);
		if (it2 == it->second.end())
		{
			// WTF happend here ? with koren
			std::vector<const Book*> nonconstmf = it->second;
			nonconstmf.push_back(_bookPtr);
		}
	}
}

