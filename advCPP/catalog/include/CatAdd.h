#ifndef CATADD_H
#define CATADD_H

#include "PubCont.h"
#include "WordCont.h"
#include "BookCont.h"
#include "AutCont.h"
#include "Tokenizer.h"

class CatAdd
{
public:
	CatAdd(PubCont& _pubCont, WordCont& _wordCont, 	BookCont& _bookCont, AutCont& _autCont);
	void Add(vector<string> _book);
private:
	PubCont& m_pubCont;
	WordCont& m_wordCont;
	BookCont& m_bookCont;
	AutCont& m_autCont;
	void AddWords(const Book* _bookPtr, vector<string> _words);
};

#endif //CATADD_H
