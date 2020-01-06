#ifndef PUBCONT_H
#define PUBCONT_H

#include <string>
#include <tr1/unordered_map>
#include "Publisher.h"
#include "PubFind.h"
#include "PubAdd.h"

class PubCont : public PubFind, public PubAdd
{
public:
	virtual const Publisher* Find(const Publisher& _publisher) const;
	virtual void Add(const Publisher* _pubPtr);
private:
	std::tr1::unordered_map<Publisher, const Publisher*, HashPublisher> m_publishers;
};

#endif //PUBCONT_H
