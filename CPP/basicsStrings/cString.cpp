#include <string.h>
#include "cString.h"
#define minCap 8;

bool string_t::caseSens = true;
size_t string_t::capacity = minCap;

size_t string_t::makePower2 (size_t _num)
{
	while ( _num > capacity)
	{
		capacity*=2;
	}
	return capacity;
}

char* string_t::createFrom(const char* _str)
{
	char* tmp;
	if (_str == NULL)
	{
		tmp = new char[capacity];
		if (tmp == NULL)
		{	
			return NULL;
		}
		tmp[0] = '\0';
		return tmp;
	}
	tmp = new char[makePower2(strlen(_str)+1)];
	if (tmp == NULL)
	{
		return NULL;
	}
	strcpy(tmp,_str);
	return tmp;
}

string_t::string_t() 
{
	str = createFrom("");
}

string_t::string_t(const char* _str)
{
	str = createFrom(_str);
}

string_t::string_t(const string_t& _strRef)
{
	str = createFrom(_strRef.str);
}

string_t::~string_t()
{
	delete[] str;
}

string_t& string_t::operator = (const string_t& _strRef)
{
	if (this != &_strRef)
	{
		delete[] str;
		str = createFrom (_strRef.str);
	}
	return *this;
}

int string_t::length() const 
{ 
	return strlen(str);
}

const char* string_t::getString () const 
{
	return str;
}

void string_t::setString (const char* _str) 
{ 
	delete[] str;
	str = createFrom(_str); 
}

void string_t::print() const 
{
	cout << str;
}

int string_t::compare (const char* _str) const 
{
	int result;
	if (_str == NULL){ return 2;}
	if ( caseSens == false) { result = strcasecmp(str,_str);}
	else { result = strcmp(str,_str);}
	if (result = 0) { return result; }
	return result>0?2:1;
}

string_t& string_t::toLower ()
{
	int i = 0;
	while ( str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] -= ('A'-'a');
		}
		i++;
	}
	return *this;
}

string_t& string_t::toUpper ()
{
	int i = 0;
	while ( str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] += ('A'-'a');
		}
		i++;
	}
	return *this;
}

string_t& string_t::prepend (const char* _str)
{
	char* temp;
	if ( _str == NULL)
	{
		return *this; 
	}
	temp = new char[strlen(str)+strlen(_str)+1];
	if ( temp == NULL)
	{
		return *this;
	}
	strcpy(temp,_str);
	strcat(temp,str);
	delete[] str;
	str = createFrom(temp);
	return *this;
}

string_t& string_t::prepend (const string_t& _strRef)
{
	prepend(_strRef.str);
	return *this;	
}

string_t& string_t::operator +=  (const char* _str)
{
	char* temp;
	if ( _str == NULL)
	{
		return *this; 
	}
	temp = new char[strlen(str)+strlen(_str)+1];
	if ( temp == NULL)
	{
		return *this;
	}
	strcpy(temp,str);
	strcat(temp,_str);
	delete[] str;
	str = temp;
	return *this;
}

string_t& string_t::operator += (const string_t& _strRef)
{
	char* temp;
	temp = new char[strlen(str)+_strRef.length()+1];
	if ( temp == NULL)
	{
		return *this;
	}
	strcpy(temp,str);
	strcat(temp,_strRef.getString());
	delete[] str;
	str = temp;
	return *this;	
}

bool string_t::operator > (const string_t& _strRef) const
{
	return (compare(_strRef.getString()) == 2 );
}

bool string_t::operator < (const string_t& _strRef) const
{
	return (compare(_strRef.getString()) == 1 );
}

bool string_t::operator >= (const string_t& _strRef) const
{
	return (compare(_strRef.getString()) != 1 );
}

bool string_t::operator <= (const string_t& _strRef) const
{
	return (compare(_strRef.getString()) != 2 );
}

bool string_t::operator != (const string_t& _strRef) const
{
	return (compare(_strRef.getString()) != 0 );
}

bool string_t::operator == (const string_t& _strRef) const
{
	return (compare(_strRef.getString()) == 0 ); 
}

bool string_t::contains (const char* _str) const
{
	if (caseSens == false) { return (strcasestr((const char*)str, _str) != NULL);}
	else { return (strstr((const char*)str, _str) != NULL); }
}

char string_t::operator [] (size_t i) const
{
	return ( ( i > length() ) ? '\0' : str[i] );
}

char& string_t::operator [] (size_t i)
{
	return ( (i > length()) ? str[length()] : str[i] );
}

ostream& operator << (ostream& _os, const string_t& _strRef)
{
	_os << _strRef.getString() << '\n';
	return _os;
}

istream& operator << (istream& _is, string_t& _strRef)
{
	char scanStr[200];
	_is >> scanStr;
	_strRef.setString((const char*)scanStr);
	return _is;
}

bool string_t::getCaseSens()
{
	return caseSens;
}

bool string_t::setCaseSens(bool i)
{
	bool prevCase = caseSens;
	caseSens = i;
	return prevCase;
}

size_t string_t::getCapacity()
{
	return capacity;
}

size_t string_t::setCapacity(size_t i)
{
	size_t tmpCap = capacity;
	capacity = makePower2(i);
	return tmpCap;
}

int string_t::firstOccurence(char _ch) const
{
	int size = length();
	int i = 0;
	char tmp2[2] = {_ch,'\0'};
	char tmp1[2];
	tmp1[1] = '\0';
	while (i < size)
	{
		tmp1[0] = str[i];
		if (strcmp(tmp1,tmp2) == 0 || ((strcasecmp(tmp1,tmp2) == 0 && caseSens == false )) )
		{
			return i;
		}
		i++;
	}
	return -1;
}

int string_t::lastOccurence(char _ch) const
{
	int i = length()-1;
	char tmp2[2] = {_ch,'\0'};
	char tmp1[2];
	tmp1[1] = '\0';
	while (i > 0)
	{
		tmp1[0] = str[i];
		if (strcmp(tmp1,tmp2) == 0 || ( (strcasecmp(tmp1,tmp2) == 0 && caseSens == false ) ) )
		{
			return i;
		}
		i--;
	}
	return -1;
}

string_t string_t::operator()(unsigned int _start, unsigned int _len) const
{
	int i = 0;
	char subStr[_len+1];
	while ( i < _len)
	{
		subStr[i] = str[_start+i];
		i++;
	}
	string_t tmp(subStr);
	return tmp;
}


