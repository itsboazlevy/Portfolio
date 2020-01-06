#include "./include/PubCont.h"

const Publisher* PubCont::Find(const Publisher& _publisher) const
{
	std::tr1::unordered_map<Publisher, const Publisher*, HashPublisher>::const_iterator it;
	it = m_publishers.find(_publisher);
	if ( it == m_publishers.end())
	{
		return 0;
	}
	return it->second;
}

void PubCont::Add(const Publisher* _pubPtr)
{
	 m_publishers.insert(std::pair<Publisher,const Publisher*>(*_pubPtr,_pubPtr));
}

