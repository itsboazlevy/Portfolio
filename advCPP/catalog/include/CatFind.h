#ifndef CATFIND_H
#define CATFIND_H

#include <string>
#include "WordCont.h"
#include "BookCont.h"
#include "Tokenizer.h"
class CatFind
{
public:
	CatFind(const WordCont& _wordCont, const BookCont& _bookCont);
	const Book* FindByISBN(const ISBN& _isbn) const;
	const std::vector<const Book*> FindByWords(std::string _words) const;
private:
	const WordCont& m_wordCont;
	const BookCont& m_bookCont;
};

#endif //CATFIND_H


