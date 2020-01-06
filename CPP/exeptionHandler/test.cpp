#include <iostream>
#include <string>
#include "exception.h"
using namespace std;

void foo()
{
	int bb;
	throw TException_t<int>(__LINE__, __FILE__, 5);
}

int main()
{
	try 
	{
		foo();	
	}
	catch (TException_t<int>)
	{
		cout << TException_t<int>.getSrcName() << endl;
		cout << TException_t<int>.getLineNum() << endl;
		cout << TException_t<int>.getDescription() << endl;
		cout << TException_t<int>.getObj() << endl;
	}
	return 1;
}
