#include <dlfcn.h>
#include <iostream>
#include "Cat.h"

using namespace std;
int main()
{
	void* ptr = dlopen("./libcat.so",RTLD_LAZY);
	Cat* (*getCat) ();
	*(void**)(&getCat) = dlsym(ptr, "creator");
	Cat* myCat = getCat(); 
	myCat->eat();
	myCat->play();
	delete myCat;
	
}
