#include "./include/Catalog.h"

Catalog::Catalog(const string& _fileName)
: m_catAdd  (m_pubCont, m_wordCont, m_bookCont, m_autCont)
, m_catFind ( m_wordCont, m_bookCont)
{
	int lineNum = 1;
	char buffer[100];
	
	m_file.open(_fileName.data(),ifstream::in);
	
	Tokenizer myTokenizer("|");
	
	while ( !m_file.eof() )
	{ 	
		m_file.getline(buffer,100);
		m_book = myTokenizer.Tokenize(buffer);
		m_catAdd.Add(m_book);
		lineNum++;
	}
	m_file.close();
}

