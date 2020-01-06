#include <iostream>
#include "../include/string.h"
#include "../include/buffer.h"
using namespace std;

void CDTOR()
{
	cout << endl;
	String<char> myStr;
	if (myStr.Data() == 0) 							{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
	String<char> myStr2("abcd");
	if (strcmp(myStr2.Data(),"abcd") == 0) 			{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
	String<char> myStr3(myStr2);
	if (strcmp(myStr3.Data(),"abcd") == 0) 			{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
}

void AssignOp()
{
	cout << endl;
	String<char> myStr("abcd");
	String<char> myStr2("efgh");
	if (strcmp(myStr2.Data(),myStr.Data()) != 0) 	{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
	myStr2 = myStr;
	if (strcmp(myStr2.Data(),myStr.Data()) == 0) 	{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
}

void Size()
{
	cout << endl;
	String<char> myStr("abcd");
	if (myStr.Size() == 4) 							{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
	String<char> myStr2;
	if (myStr2.Size() == 0) 						{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
	String<char> myStr3("abcdefghijklmnop");
	if (myStr3.Size() == 16) 						{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
}

void SubscOp()
{
	cout << endl;
	String<char> myStr("abcdefg");
	myStr[5] = 'w';
	if (strcmp(myStr.Data(),"abcdewg") == 0) 		{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
	char x;
	x = myStr[5];
	if (x == 'w') 									{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
	x = myStr[3];
	if (x == 'd') 									{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
}

void At()
{
	cout << endl;
	String<char> myStr("abcdefg");
	try { myStr.At(7) = 'w';}
	catch (int) { cout << "PASS" << endl;}
	try {  myStr.At(5) = 'w';}
	catch (int) { cout << "FAIL" << endl;}
}

void BoolConvert()
{
	cout << endl;
	String<char> myStr("abc");
	String<char> myStr2;
	if( myStr ) 									{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
	if( !myStr2 ) 									{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
	if( !!myStr ) 									{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }

}

void BoolOps()
{
	cout << endl;
	String<char> myStr("ab");
	String<char> myStr2("abc");	
	String<char> myStr3("abc");	
	if (myStr < myStr2) 							{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
	if (myStr2 > myStr) 							{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
	if (myStr3 == myStr2) 							{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
	if (myStr3 != myStr) 							{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
	if (myStr3 >= myStr) 							{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
	if (myStr <= myStr3) 							{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
}

void Contain()
{
	cout << endl;
	String<char> myStr("abcdefg");
	if ( Contain(myStr,'a') ) 						{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
	if ( Contain(myStr,'d' ) )						{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
	if ( !Contain(myStr,'h') ) 						{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
}

void ToLowUp()
{
	cout << endl;
	String<char> myStr("abcdefg");
	ToUpper(myStr);
	if (strcmp(myStr.Data(),"ABCDEFG") == 0) 		{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
	ToLower(myStr);
	if (strcmp(myStr.Data(),"abcdefg") == 0) 		{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; }
}

/*
void AddOps()
{
	cout << endl;
	String<char> myStr("abcd");
	String<char> myStr2("efgh");
	String<char> myStr3;
	myStr3 = myStr + myStr2;
	if (strcmp(myStr.Data(),"abcd") == 0) 			{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; } 
	if (strcmp(myStr2.Data(),"efgh") == 0) 			{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; } 
	if (strcmp(myStr3.Data(),"abcdefgh") == 0) 		{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; } 
	myStr += myStr2;
	if (strcmp(myStr.Data(),"abcdefgh") == 0) 		{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; } 
	myStr2 += myStr;
	if (strcmp(myStr2.Data(),"efghabcdefgh") == 0) 	{ cout << "PASS" << endl; } else { cout << "FAIL" << endl; } 
}
*/
void Print()
{
	cout << endl;
	String<char> myStr("PASS");
	Print(myStr);
}


int main()
{
	
	CDTOR();
	
	AssignOp();
	
	Size();
	
	SubscOp();
	
	At();
	
	BoolConvert();
	
	BoolOps();
	
	Contain();
	
	ToLowUp();
	
	//AddOps();
	
	Print();
	
	cout << endl;
	return 1;
}
