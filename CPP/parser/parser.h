#ifndef __PARSER_H__
#define __PARSER_H__

#include <string>
#include <fstream>
#include "tokenizer.h"
#include "analyser.h"

using namespace std;

class parser
{
	public:
	
		parser() {}
		virtual ~parser() {}
		bool parse(const string& _fileName);
	
	private:
	
		parser(const parser& _parser);
		const parser& operator = (const parser& _parser);
		
		size_t lineNum;
		ifstream file;
		tokenizer myTokenizer;
		analyser myAnalyser;
		
};

#endif // __PARSER_H__
