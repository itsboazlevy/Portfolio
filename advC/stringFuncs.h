#ifndef __STRINGFUNCS_H__
#define __STRINGFUNCS_H__

#include <stdio.h>
/*
Description: checks string length
Input:	string pointer 
Output:	length of string
Error:	0 for null pointer
*/
int StrLen(const char* _str);
int StrLenRec(const char* _str);

/*
Description: checks if strings are the same
Input:	2 strings pointers 
Output:	1 if identical 0 if not
Error: 0 if null pointers
*/
int StrCompare (const char* _s1, const char* _s2);
int StrCompareRec (const char* _s1, const char* _s2);

/*
Description: copy string from source to destenation
Input:	source string and destenation string 
Output:	pointer to start of destination
Error: null if null pointer 
*/
char* StrCopy (char* _destination, const char* _source);
char* StrCopyRec (char* _destination, const char* _source);

/*
Description: copy string from source to destenation
Input:	source string and destenation string 
Output:	pointer to start of destination
Error: null if null pointer 
*/
char* StrNCopy (char* _destination, const char* source, size_t _num);
char* StrNCopyRec (char* _destination, const char* source, size_t _num);

/*
Description: adds source string to destenation string - might smear memory
Input:	source string and destenation string 
Output:	pointer to start of destination
Error: null if null pointer 
*/
char* StrConcat (char* _destination, const char* source);

/*
Description: finds first appearence of string within string - returns warning for const?
Input:	string and searched string
Output:	pointer to found string start or to null if not found
Error: null if null pointer
*/
char* StrSubString (const char* _str, const char* _search);

#endif /* __STRINGFUNCS_H__ */
