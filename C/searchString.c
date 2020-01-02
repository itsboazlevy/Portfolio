
// isStringPalindrom returns 1 if string is palindrom, 0 if not, -1 if nullError.
/* firstLocation finds the first location of string within string and return location
   or didnt find return -1 */

 
#include <stdio.h>
#define nullError -1   

int checkNull(const char *str)
{
	if (*str == '\0')
	{
	return nullError;
	}
	return 1;
}

int myStrLen(const char *str)
{
    int i = 0;
    while ( *str != '\0')
    {
        str++;
        i++;
    }
    return i;
}   

int isStringPalindrom ( const char *str)
{
	if (checkNull(str) == 0)
	{
		return nullError;
	}
	int size = myStrLen(str);
	int i = 0;
	while (size > i*2)
	{
		if (*(str+i) != *(str+size-1-i))
		{
			return 0;
		}
		i++;
	}
	return 1;
}

int myStrCmp(const char *str, const char *str2, int str2Size)
{
	while (str2Size-1 > 0)
	{
		if (*str != *str2)
		{
			break;
		}
		str++;
		str2++;
		str2Size--;
	}
    return (*(str) - *(str2));
} 
int firstLocation(const char *str, const char *str2)
{
	int str2Size = myStrLen(str2);
	int str1Size = myStrLen(str);
	int count = 0;
	while (str2Size <= str1Size-count )
	{	
		if (myStrCmp(str,str2,str2Size) == 0)
		{
			return count;
		}			
		count++;
		str++;
	}
	return -1;	
}

int main()
{
	const char string[50] = "abcdefggerthfboazsdasd";
	const char string2[50] = "boazk";
	printf("%d\n",isStringPalindrom (string));
	printf("%d\n",firstLocation(string, string2));
	return 1;
}

