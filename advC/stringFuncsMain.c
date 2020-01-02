#include <stdio.h>
#include "stringFuncs.h"
int main()
{
	char str[] = "ab";
	char str2[] = "cde";
	char str3[] = "fghijk";
	char str4[] = "lmnop";
	char str5[] = "qrst";
	char str6[] = "uwxyz";
	char str7[20] = "abcdefg";
	char str8[] = "hij";
	char str9[] = "klmnop";
	char str10[] = "mn";

	printf("%d\n",StrLen(str));
	printf("%d\n",StrLenRec(str));
	printf("%d\n",StrCompare(str,str2));
	printf("%d\n",StrCompareRec(str,str2));
	printf("%s\n",StrCopy(str,str2));
	printf("%s\n",StrCopyRec(str,str3));
	printf("%s\n",StrNCopy(str4,str5,2));
	printf("%s\n",StrNCopyRec(str4,str6,2));
	printf("%s\n",StrConcat(str7,str8));
	printf("%s\n",StrSubString(str9,str10));
	return 1;
}
