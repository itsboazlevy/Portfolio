#include "analyser.h"
#include <iostream>
#include <set>
using namespace std;

string analyser::myPreDefined[] = {"char", "short", "int", "long", "float", "double", "void"};
string analyser::myKeyWords[] = {"if", "else", "for" , "while", "class", "private", "public","virtual", "main", "const", "protected"};
string analyser::myOperators[] = {"(", ")", "{", "}", "[", "]", "+", "-", "==", "->", "=", "*", "&", "<<", ">>", ">", "<", ";"};


analyser::analyser(): mainFlag(0), ifFlag(0), preDefFlag(0), parenCount(0), brackCount(0), braceCount(0), minusCount(0), plusCount(0), 	preDefined(&myPreDefined[0],&myPreDefined[6]), 	keyWords(&myKeyWords[0],&myKeyWords[10]), operators(&myOperators[0],&myOperators[17]) 
{
}

void analyser::mainCheck(size_t _lineNum, queue<string>& _tokens)
{
	if ( mainFlag == 0 && !_tokens.empty())
	{
		if ( _tokens.front() == "main" )
		{
			_tokens.pop();
		}
		else
		{
			cout << endl << "Expected main before input in line " << _lineNum << endl;
		}
		mainFlag = 1;		
	}	
}

bool analyser::ifElseCheck(size_t _lineNum, const string& _tok)
{
	bool flag = 0;
	if ( _tok == "if")
	{
		ifFlag = 1;
		flag = 1;
	}
	else if ( _tok == "else" && ifFlag == 1)
	{
		ifFlag = 0;
		flag = 1;
	} 
	else if ( _tok == "else" && ifFlag == 0)
	{
		cout << endl << "Expected if before else in line " << _lineNum << endl;
		flag = 1;
	}
	return flag;
}

bool analyser::bracCheck(size_t _lineNum, const string& _tok)
{
	bool flag = 1;
	if ( _tok == "(") 		{ parenCount++; }
	else if ( _tok == "[") 	{ brackCount++; }
	else if ( _tok == "{") 	{ braceCount++; }
	else if ( _tok == ")")
	{
		if (parenCount == 0) { cout << endl << "Expected ( before ) in line " << _lineNum << endl;}
		else { parenCount--; }	
	}
	else if ( _tok == "]")
	{
		if (brackCount == 0) { cout << endl << "Expected [ before ] in line " << _lineNum << endl;}
		else { brackCount--; }
	}
	else if ( _tok == "}")
	{
		if (braceCount == 0) { cout << endl << "Expected { before } in line " << _lineNum << endl;}
		else { braceCount--; }
	}
	else
	{
		flag = 0;
	}	
	return flag;
}

void analyser::finalBracCheck()
{
	if (parenCount) { cout << endl << parenCount << " ( not closed " << endl; }
	if (brackCount) { cout << endl << brackCount << " [ not closed " << endl; }
	if (braceCount) { cout << endl << braceCount << " { not closed " << endl; }
}

void analyser::finishTouch()
{
	finalBracCheck();
	mainFlag = 0;
	ifFlag = 0;
	preDefFlag = 0;
	parenCount = 0;
	brackCount = 0;
	braceCount = 0; 
	minusCount = 0;
	plusCount = 0;
	userDefined.clear();
}

void analyser::varInsert(size_t _lineNum, const string& _tok)
{
	if   (   _tok[0] == '_' || (_tok[0] >= 'a' && _tok[0] <= 'z') || (_tok[0] >= 'A' && _tok[0] <= 'Z')   )
	{
		userDefined.insert(_tok);	
	}
	else
	{
		cout << endl << "Variable name not valid in line " << _lineNum << endl;
	}
}

void analyser::varCheck(size_t _lineNum, const string& _tok)
{
	if ( preDefFlag == 1)
	{
		if ( userDefined.find(_tok) != userDefined.end())
		{
			cout << endl << "Redecleration of variable in line " << _lineNum << endl;
		}
		else
		{
			varInsert(_lineNum, _tok);
		}
	}
	else
	{
		if ( userDefined.find(_tok) == userDefined.end())
		{
			cout << endl << "Variable not declared in line " << _lineNum << endl;
		}
	}
}

bool analyser::plusMinusCheck(size_t _lineNum, const string& _tok)
{
	bool flag = 1;
	if(_tok == "+")
	{
		if (plusCount == 2)
		{
			cout << endl << "+++ operator not allowed in line " << _lineNum << endl;
			plusCount = 0;
		}
		else
		{
			plusCount++;
			minusCount = 0;
		}
	}
	else if(_tok == "-")
	{
		if (minusCount == 2)
		{
			cout << endl << "--- operator not allowed in line " << _lineNum << endl;
			minusCount = 0;
		}
		else
		{
			minusCount++;
			plusCount = 0;
		}
	}
	else
	{
		flag = 0;
	}
	return flag;
}

void analyser::analyze(size_t _lineNum, queue<string>& _tokens)
{
	string tok;	
	mainCheck(_lineNum, _tokens);
	while(!_tokens.empty())
	{
		tok = _tokens.front();
		_tokens.pop();

		if (preDefined.find(tok) != preDefined.end())
		{
			if (preDefFlag == 1)
			{ 
				cout << endl << "Multiple type declaration in line " << _lineNum << endl;
				preDefFlag = 0;
			}
			else
			{
				preDefFlag = 1;
			}
		}
		else if ( keyWords.find(tok) == keyWords.end() && operators.find(tok) == operators.end())
		{
			varCheck(_lineNum,tok);
			preDefFlag = 0;
		}
		else if ( (keyWords.find(tok) != keyWords.end()|| operators.find(tok) != operators.end()) && preDefFlag == 1)
		{
			cout << endl << "Valid variable name required after pre defined type in line " << _lineNum << endl;
			preDefFlag = 0;
		}
		else if (ifElseCheck(_lineNum,tok))				{preDefFlag = 0;}
		else if (keyWords.find(tok) != keyWords.end())	{preDefFlag = 0;}
		else if (bracCheck(_lineNum,tok))				{preDefFlag = 0;}
		else if (plusMinusCheck(_lineNum,tok))			{preDefFlag = 0;}
		else if (operators.find(tok) != operators.end()){preDefFlag = 0;}
	}
}
