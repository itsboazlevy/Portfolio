#include <stdio.h>
#include "cString.h"

void CDTOR()
{
	string_t myStr;
}

void CDTOR2()
{
	const char* s1 = "String number 1";
	string_t myStr(s1);
}

void copCTOR()
{
	string_t myStr;
	const char* s1 = "String number 1";
	string_t myStr2 = myStr;
}

int main()
{
	CDTOR();
	CDTOR2();
	copCTOR();
	return 1;
}
