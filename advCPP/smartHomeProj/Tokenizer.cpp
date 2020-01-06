#include "Tokenizer.h"

Tokenizer::Tokenizer(string _whiteSpaces)
: m_whiteSpaces(_whiteSpaces)
{

}

vector<string> Tokenizer::Tokenize(const string& _buffer)
{
	size_t i;
	string pushMe;
	m_tokens.clear();
	for (i=0;i<_buffer.length();i++)
	{
		if ( m_whiteSpaces.find(_buffer[i]) != string::npos)
		{
			/* makes sure we push last token */
			if (!pushMe.empty() )
			{
				m_tokens.push_back(pushMe);
				pushMe.clear();
			}
		} 
		else
		{
			pushMe += (_buffer[i]);
		}
	}
	m_tokens.push_back(pushMe);
	return m_tokens;
}
