#include <iostream>
#include "Cat.h"
using namespace std;

Cat::Cat()
{
	cout << "this is ctor" << endl;
}

Cat::~Cat()
{
	cout << "this is dtor" << endl;
}

void Cat::eat()
{
	cout << "this is eat" << endl;
}

void Cat::play()
{
	cout << "this is play" << endl;
}

Cat* creator()
{
	cout << "this is creator envelope" << endl;
	return new Cat;
}

