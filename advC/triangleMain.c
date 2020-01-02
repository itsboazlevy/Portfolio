#include "triangle.h"
int main ()
{
	int count;
	int (*triangleFuncPointer[])(char,int) = 
	{
		uprighttriangle,
		downrighttriangle,
		righttriangle,
		uptriangle,
		downtriangle,
		updowntriangle
	};
	int uprighttriangle(char symbol, int size);
	for (count = 0; count < 6; count++)
	{
		triangleFuncPointer[count]('*',5);
	}
	return 1 ;
}
