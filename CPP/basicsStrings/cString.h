/*	Description: C++ Class practice with string type and functions	
	Author: Boaz L
	Created: 7.9.19
	Last Update: 10.9.19
*/
#ifndef __CSTRING_H__
#define __CSTRING_H__
#include <iostream>
using namespace std;
class string_t
{
	public:
		string_t();											/* default CTOR */
		string_t(const char* _str);							/* CTOR */
		string_t(const string_t& _strRef);					/* copy CTOR*/
		~string_t();										/* DTOR	*/
		string_t& operator = (const string_t& _str);		/* assignment operator */
		inline int length() const;							
		int compare (const char* _str) const;		
		inline void print () const;
		void setString (const char* _str);
		inline const char* getString () const;
		string_t& toLower ();
		string_t& toUpper ();
		string_t& prepend (const char* _str);
		string_t& prepend (const string_t& _strRef);
		string_t& operator += (const string_t& _strRef);
		string_t& operator +=  (const char* _str);
		bool operator > (const string_t& _strRef) const;
		bool operator < (const string_t& _strRef) const;
		bool operator >= (const string_t& _strRef) const;
		bool operator <= (const string_t& _strRef) const;
		bool operator != (const string_t& _strRef) const;
		bool operator == (const string_t& _strRef) const;
		bool contains (const char* _str) const;
		char operator [] (size_t i) const;					/* if out of bounds returns null char */
		char& operator [] (size_t i) ;						/* if out of bounds returns null char */
		inline static bool getCaseSens();
		static bool setCaseSens(bool i);
		inline static size_t getCapacity();
		static size_t setCapacity(size_t i);				/* all actual capacities will be powers of 2 */
		int firstOccurence(char _ch) const;
		int lastOccurence(char _ch) const;
		string_t operator()(unsigned int _start, unsigned int _len) const;
	private:
		char* str;
		static char* createFrom(const char* _str);	
		static bool caseSens;	
		static size_t capacity;	
		static size_t makePower2 (size_t _num);
};


ostream& operator << (ostream& _os, const string_t& _strRef) ;	/* this is called global overloading, its outside of classes */
istream& operator >> (ostream& _is, string_t& _strRef) ; 		/* limited to 200 scanned elements */
		

#endif /* __CSTRING_H__ */
