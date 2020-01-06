#include "./include/CatFind.h"

CatFind::CatFind(const WordCont& _wordCont, const BookCont& _bookCont)
: m_wordCont(_wordCont)
, m_bookCont(_bookCont)
{

}

const Book* CatFind::FindByISBN(const ISBN& _isbn) const
{
	return m_bookCont.Find(_isbn);
}

const std::vector<const Book*> CatFind::FindByWords(std::string _words) const
{
	Tokenizer myTokenizer(" \t\n\v\f\r\0");
	vector<string> words = 	myTokenizer.Tokenize(_words);
	int wordsNum = words.size();
	std::vector<const Book*> initResultVec;
	int i;
	int j;
	// this creates the initial result vector by the first pos word
	for (i=0; i<wordsNum;++i)
	{
		if ( words[i][0] != '-' )
		{
			initResultVec = *(m_wordCont.Find(words[i]));
			words.erase(words.begin() + i);
			break;
		}
	}
	// this go over the initial vector and checks the rest of the given pos or neg words

	wordsNum--;
	int bookNum = initResultVec.size();
	std::vector<const Book*> finalResultVec;
	
	bool flag;
	
	for(i=0; i < bookNum; ++i)
	{
		const std::string& testedTitle = initResultVec[i]->GetTitle();
		flag = 0;
		for (j=0; j< wordsNum; ++j)
		{
			if(words[j][0] != '-')
			{
				if ( testedTitle.find(words[j]) == std::string::npos)
				{
					flag = 1;
					break;
				}
			}
			else
			{
				if ( testedTitle.find(&(words[j][1])) != std::string::npos)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				finalResultVec.push_back(initResultVec[i]);
			}
		}
	}
	return finalResultVec;
}

