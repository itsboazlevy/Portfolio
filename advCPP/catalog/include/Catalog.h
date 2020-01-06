#ifndef CATALOG_H
#define CATALOG_H

#include <tr1/unordered_map>
#include <fstream>
#include <queue>
#include "Tokenizer.h"
#include "CatAdd.h"
#include "CatFind.h"

class Catalog
{
public:
	Catalog(const string& _fileName);
private:
	ifstream m_file;
	vector<string> m_book;
	PubCont m_pubCont;
	WordCont m_wordCont;
	BookCont m_bookCont;
	AutCont m_autCont;
	CatAdd m_catAdd;
	CatFind m_catFind;
};

#endif //CATALOG_H
