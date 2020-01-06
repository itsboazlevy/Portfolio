// this is not close to being done :(

#include <iostream>
#include <string.h>

class String
{
	public:
	String (const char * _data, bool _flag);
	~String ();
	private:
	const char* data;
}

String::String (const char * _data, bool _flag)
{    
	if (_flag) 
	{
		throw void;
	}
	data = new char[100];
	strcpy(data,_data);
}

String::~String()
{
	cout << "DTOR is deleting data now" << endl;
	delete[] data;
}
