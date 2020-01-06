#ifndef __ANALYSER_H__
#define __ANALYSER_H__
#include <queue>
#include <set>
#include <string>
using namespace std;

class analyser
{
	public:
		analyser();
		~analyser() {}
		void analyze(size_t _lineNum, queue<string>& _tokens);
		void finishTouch();
	private:
		analyser(const analyser& _analyser);
		const analyser& operator = (const analyser& _analyser);
		
		void mainCheck(size_t _lineNum, queue<string>& _tokens);
		bool ifElseCheck(size_t _lineNum, const string& _tok);
		bool bracCheck(size_t _lineNum, const string& _tok);
		void varCheck(size_t _lineNum, const string& _tok);
		void varInsert(size_t _lineNum, const string& _tok);
		bool plusMinusCheck(size_t _lineNum, const string& _tok);
		void finalBracCheck();
		
		static string myPreDefined[7];
		static string myKeyWords[11];
		static string myOperators[18];
				
		set<string> preDefined;
		set<string> keyWords;
		set<string> operators;
		set<string> userDefined;
		
		bool mainFlag;
		bool ifFlag;
		bool preDefFlag;
		size_t parenCount;
		size_t brackCount;
		size_t braceCount;
		size_t minusCount;
		size_t plusCount;
};

#endif //__ANALYSER_H__
