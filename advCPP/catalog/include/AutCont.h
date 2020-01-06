#ifndef AUTCONT_H
#define AUTCONT_H

#include <string>
#include <tr1/unordered_map>
#include "Author.h"
#include "AutFind.h"
#include "AutAdd.h"

class AutCont : public AutFind, public AutAdd
{
public:
	virtual const Author* Find(const Author& _author) const;
	virtual void Add(const Author* _autPtr);
private:
	std::tr1::unordered_map<Author, const Author*, HashAuthor> m_authors;
};

#endif //AUTCONT_H
