#include "tokenizer.h"

queue<string>& tokenizer::tokenize(const string& _buffer)
{
	int i;
	string pushMe;
	size_t findResult;
	for (i=0;i<_buffer.length();i++)
	{
		if ( whiteSpaces.find(_buffer[i]) != string::npos)
		{
			/* makes sure we push last token */
			if (!pushMe.empty() )
			{
				tokens.push(pushMe);
				pushMe.clear();
			}
			continue;
		} 
		else if ( ( findResult = preDefined.find(_buffer[i]) ) != string::npos)
		{
			/* makes sure we push last token */
			if (!pushMe.empty() )
			{
				tokens.push(pushMe);
				pushMe.clear();
			}
			
			pushMe = preDefined[findResult];
			tokens.push(pushMe);
			pushMe.clear();
		}
		else
		{
			pushMe += (_buffer[i]);
		}
		
	}
	return tokens;
}

