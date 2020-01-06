#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__
#include <string>
using namespace std;

template <class T>
class TException_t
{
	public:
		TException_t(size_t _lineNum,const string& _srcName,const T& _obj, const string& _description = "Default message");
		TException_t(const TException_t& _ex);
		~TException_t() {};
		const string& getSrcName() const {return srcName.data();}
		const string& getDescription() const {return description.data();}
		size_t getLineNum() const {return lineNum;}
		const T& getObj() const {return obj;}
	private:
		TException_t& operator = (const TException_t& _ex); 
		string description;
		string srcName;
		size_t lineNum;
		T obj;
};

#endif //__EXCEPTION_H__

template <class T>
TException_t<T>::TException_t(size_t _lineNum,const string& _srcName,const T& _obj, const string& _description)
{
	lineNum = _lineNum;
	srcName = _srcName;
	description = _description;
	obj = _obj; 
}

template <class T>
TException_t<T>::TException_t(const TException_t& _ex)
{
	lineNum = _ex.lineNum;
	srcName = _ex.srcName;
	description = _ex.description;
	obj = _ex.obj; 
}
