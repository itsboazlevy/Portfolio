#include "virtIO.h"
#include "asciiIO.h"
#include "binIO.h"
#include <iostream>

int main()
{	
	char command;
	int flag = 1;
	size_t num;
	virtIO_t* ioPtr;
	
	while(flag)
	{
		cout << "Choose your IO type:" << endl << "ASCII - 1" << endl << "Binary - 2" << endl;
		cin >> command;
		switch (command) 
		{
		case '1': 	ioPtr = new asciiIO_t;
					flag = 0;
					break;
		case '2': 	ioPtr = new binIO_t;
					flag = 0;
					break;
		default : 	cout << endl << "No such command, try again!" << endl;	
		}		
	}
	flag = 1;
	
	while(flag)
	{
		cout << endl << "Commands: O(pen File) C(lose File) W(rite) R(ead) P(osition Set) p(osition Get) M(ode Set) m(ode get) s(tatus Get) Q(uit)" << endl;
		cin >> command;
		switch (command) 
		{
			case 'O':   ioPtr->openFile();
						break;
			case 'C': 	cout << endl << ioPtr->closeFile() << endl;
						break;
			case 'W':	cout << endl << "Enter your Input" << endl;
						cin >> num; 
						try 
						{
							(*ioPtr << num);
							cout << endl << "Success ! " << endl;
						}
						catch(...) 
						{
							cout << endl << "Something Went Wrong! :( " << endl;
						}
						break;
			case 'R':	try 
						{
							*ioPtr >> num;
							cout << endl << num << endl;
						}
						catch(...) 
						{
							cout << endl << "Something Went Wrong! :( " << endl;
						}
						break;			
			case 'P': 	cout << endl << "Enter Position to Move to" << endl;
						cin >> num; 
						cout << endl << ioPtr->setPosition(num) << endl;
						break;			
			case 'p': 	cout << endl << ioPtr->getPosition() << endl;
						break;	
			case 'M': 	cout << endl << "Enter Mode 0-Read 1-Write 2-Read+Write" << endl;
						cin >> num; 
						ioPtr->setMode((virtIO_t::modes)num);
						cout << endl << "Success ! " << endl;
						break;			
			case 'm': 	cout << endl << size_t(ioPtr->getMode()) << endl;
						break;			
			case 's': 	cout << endl << ioPtr->getStatus() << endl;
						break;			
			case 'Q':	cout << endl << "GoodBye!" << endl;
						flag = 0;
						break;
			default : 	cout << endl << "No such command, try again!" << endl;
						break;
		}
	}
	return 1;
}
