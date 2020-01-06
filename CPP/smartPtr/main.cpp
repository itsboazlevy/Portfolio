#include "smartPtr.h"

int main()
{
	try
	{
		String("abcdefg",0) str;
	} 
	catch (...)
	{
		cout << "Execption Executed" << endl;	
	}
}
