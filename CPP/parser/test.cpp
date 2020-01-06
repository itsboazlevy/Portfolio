#include "parser.h"

int main(int argc, char** argv)
{
	int i;
	parser p;
	for(i=1; i<argc; i++)
	{
		p.parse(argv[i]);
	}
	
	return 1;
}
