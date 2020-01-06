#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <queue>
#include <string>

using namespace std;

class Tokenizer
{
	public:
		Tokenizer(string _whiteSpaces);
		vector<string> Tokenize(const string& _buffer);
	private:
		vector<string> m_tokens;
		string m_whiteSpaces;
};

#endif //TOKENIZER_H
