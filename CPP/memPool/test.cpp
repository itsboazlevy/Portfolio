#include "memPool.h"
#include "memPage.h"
#include <iostream>

int main ()
{
	char command;
	int flag = 1;
	size_t num;
	memManager_t* memPtr;
	
	while(flag)
	{
		cout << "Choose your memory managment:" << endl << "Page - 1" << endl << "Pool - 2" << endl;
		cin >> command;
		switch (command) 
		{
		case '1': 	memPtr = new memPage_t;
					flag = 0;
					break;
		case '2': 	memPtr = new memPool_t;
					flag = 0;
					break;
		default : 	cout << endl << "No such command, try again!" << endl;	
		}		
	}
	flag = 1;
	
	while(flag)
	{
		cout << endl << "Commands: E(mpty) S(ize) P(osition) W(rite) R(ead) M(ove) Q(uit)" << endl;
		cin >> command;
		switch (command) 
		{
			case 'E': 	cout << endl << memPtr->isEmpty() << endl;
						break;
			case 'S': 	cout << endl << memPtr->getSize() << endl;
						break;
			case 'P': 	cout << endl << memPtr->getPos() << endl;
						break;
			case 'Q':	cout << endl << "GoodBye!" << endl;
						flag = 0;
						break;
			case 'W':	cout << endl << "Enter Number to Write" << endl;
						cin >> num; 
						memPtr->write((const char*) &num, sizeof(int));
						break;
			case 'M':	cout << endl << "Enter Position to Move to" << endl;
						cin >> num; 
						while (1)
						{
							try 
							{
								memPtr->setPos(num);
								break;
							}
							catch(...) 
							{
								cout << endl << "Try Again! max position is " << memPtr->getSize() << endl;
								cout << endl << "Enter Position to Move to" << endl;
								cin >> num; 
							}
						}
						break;
			case 'R':	memPtr->read((char*)num, 4);
						cout << endl << num << endl; 
						break;
			default : 	cout << endl << "No such command, try again!" << endl;
						break;
		}
	}
	return 1;
}
