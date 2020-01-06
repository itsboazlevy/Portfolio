#include "container.h"
#include "vector.h"
#include "list.h"
#include <iostream>
using namespace std;
int main ()
{
	char command;
	int flag = 1;
	size_t num;
	size_t index;
	container_t<int>* conPtr;
	
	while(flag)
	{
		cout << "Choose your container:" << endl << "list - 1" << endl << "vector - 2" << endl;
		cin >> command;
		switch (command) 
		{
		case '1': 	conPtr = new list_t;
					flag = 0;
					break;
		case '2': 	conPtr = new vector_t;
					flag = 0;
					break;
		default : 	cout << endl << "No such command, try again!" << endl;	
		}		
	}
	flag = 1;
	
	while(flag)
	{
	cout << endl <<"Commands: A(ppend) P(repend) C(ontains) c(ount) F(ind) I(ndex) i(sEmpty)" << endl <<
				"	N(sert) R(emove) D(elete) r(emoveAll) d(eleteAll) Q(uit" << endl;
		cin >> command;
		switch (command) 
		{
			case 'A': 	cout << endl << "Enter Number to Append" << endl;
						cin >> num; 
						cout << endl << "Enter index to Append" << endl;
						cin >> index; 
						cout << conPtr->append(&num, index) << endl;
						break;
			case 'P':	cout << endl << "Enter Number to Preppend" << endl;
						cin >> num; 
						cout << endl << "Enter index to Preppend" << endl;
						cin >> index; 
						cout << conPtr->prepend(&num, index) << endl;
						break;
			case 'C':	cout << endl << "Enter Number to Contains" << endl;
						cin >> num; 
						cout << conPtr->contains(&num) << endl;
						break;
			case 'c':	cout << conPtr->count() << endl;
						break;
			case 'F':	cout << endl << "Enter Number to Find" << endl;
						cin >> num; 
						cout << conPtr->find(&num) << endl;
						break;
			case 'I':	cout << endl << "Enter Number to Index" << endl;
						cin >> num; 
						cout << conPtr->index(&num) << endl;
						break;
			case 'i':	cout << conPtr->isEmpty() << endl;
						break;
			case 'N':	cout << endl << "Enter Number to INsert" << endl;
						cin >> num; 
						cout << conPtr->insert(&num) << endl;
						break;
			case 'R':	cout << endl << "Enter Number to Remove" << endl;
						cin >> num; 
						cout << conPtr->remove(num) << endl;
						break;
			case 'D':	cout << endl << "Enter Number to Delete" << endl;
						cin >> num; 
						cout << conPtr->removeAndDelete(num) << endl;
						break;
			case 'r':	cout << conPtr->removeAll() << endl;
			case 'd':	cout << conPtr->removeAndDeleteAll() << endl;
			case 'Q':	cout << endl << "GoodBye!" << endl;
						flag = 0;
						break;
			default : 	cout << endl << "No such command, try again!" << endl;
						break;
		}
	}
	return 1;
}
