#include "./include/CatAdd.h"

CatAdd::CatAdd(PubCont& _pubCont, WordCont& _wordCont, 	BookCont& _bookCont, AutCont& _autCont)
: m_pubCont(_pubCont)
, m_wordCont(_wordCont)
, m_bookCont(_bookCont)
, m_autCont (_autCont) 
{

}

void CatAdd::Add(std::vector<std::string> _book)
{
	std::string bookIspn = _book.front();
	if (m_bookCont.Find(ISBN(bookIspn)) == 0)
	{
		std::string bookTitle = _book.front();
		std::string bookAuthor = _book.front();
		std::string bookYear = _book.front();
		std::string bookPublisher = _book.front();
		Author* authorPtr = new Author(bookAuthor);
		if ( m_autCont.Find(*authorPtr) == 0 )
		{
			m_autCont.Add(authorPtr);
		}
		else
		{
			delete authorPtr;
		}
		Publisher* publisherPtr = new Publisher(bookPublisher);
		if ( m_pubCont.Find(*publisherPtr) == 0 )
		{
			m_pubCont.Add(publisherPtr);
		}
		else
		{
			delete publisherPtr;
		}
		Book* bookPtr = new Book(bookIspn, bookTitle, m_autCont.Find(Author(bookAuthor)), bookYear, 		
		m_pubCont.Find(Publisher(bookPublisher)));
		m_bookCont.Add(bookPtr);
		Tokenizer myTokenizer(" \t\n\v\f\r\0");
		AddWords(bookPtr, myTokenizer.Tokenize(bookTitle) );
	}
}

void CatAdd::AddWords(const Book* _bookPtr, vector<string> _words)
{
	std::string word;
	while( !_words.empty() )
	{
		word = _words.front();
		m_wordCont.Add(word, _bookPtr);
	}
}
