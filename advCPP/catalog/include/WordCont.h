#ifndef WORDCONT_H
#define WORDCONT_H

#include <string>
#include <algorithm>
#include <vector>
#include <tr1/unordered_map>
#include "Book.h"
#include "WordFind.h"
#include "WordAdd.h"

class WordCont : public WordFind, public WordAdd
{
public:
	virtual const std::vector<const Book*>* Find(std::string _word) const;
	virtual void Add(std::string _word, const Book* _bookPtr);
private:
	std::tr1::unordered_map< std::string, std::vector<const Book*> >  m_words;
};

#endif //WORDCONT_H
