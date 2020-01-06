#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__
#include <queue>
#include <string>
using namespace std;

class tokenizer
{
	public:
		tokenizer() { whiteSpaces =  " \t\n\v\f\r"; preDefined = "()[]{};<>=+-*&";}
		~tokenizer() {}
		queue<string>& tokenize(const string& _buffer);
		
	private:
		tokenizer(const tokenizer& _tokenizer);
		const tokenizer& operator = (const tokenizer& _tokenizer);
		queue<string> tokens;
		string whiteSpaces;
		string preDefined;
};

#endif //__TOKENIZER_H__
