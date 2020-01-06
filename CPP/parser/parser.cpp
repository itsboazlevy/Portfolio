#include "parser.h"

bool parser::parse(const string& _fileName)
{
	lineNum = 1;
	char buffer[1000];
	
	file.open(_fileName.data(),ifstream::in);
	
	while ( !file.eof() )
	{ 	
		file.getline(buffer,1000);
		queue<string>& tokens = myTokenizer.tokenize(buffer);
		myAnalyser.analyze(lineNum,tokens);
		lineNum++;
	}
	myAnalyser.finishTouch();
	
	file.close();
}
