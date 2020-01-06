#include "Server.h"
#include <string>
#include <iostream>

int main()
{
	Server mySrv("config.txt");
	std::string s;
	do
	{
		std::cin >> s ;
	}
	while(s!="Q"); 

	return 3;
}
