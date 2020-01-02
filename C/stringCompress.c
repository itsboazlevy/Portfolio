#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int PrintStringInBin(char string[])
{
	int count = 0;
	int count2 = 0;
	while (string[count] != '\0')
	{
		for(count2 = 0; count2<sizeof(char)*8; count2++)
		{
			if ( (string[count] & 128) != 0)
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
			string[count] = string[count]<<1;
		} 
		count++;
		printf(" ");
	}
	return 1;
}

int CompressStringByFactor2(char string[])
{
	int count = 0;
	char origString[100];
	int printIndex = 0;
	strcpy(origString,string);
	/*prints 2 versions of the original string*/
	printf("\nstring: %s\n",string);
	PrintStringInBin(string);
	strcpy(string,origString);
	/*compresses string*/
	while (string[count] != '\0' && string[count+1] != '\0')
	{
		string[count/2] = (string[count] - 'a'+1) + ((string[count+1] - 'a'+1)*16);
		count += 2;
	}
	if (string[count] != '\0' && string[count+1] == '\0')
	{
		string[count/2] = string[count] - 'a'+1;
	}
	else
	{
		string[count/2] = '\0';
	}
	count = 0;
	/*prints 2 versions of the compressed string*/
	
	printf("\nCompressed string: ");
	while ((string[count] & 15) != 0 && (string[count] & 240) !=0)
	{
		printf("%c%c", (string[count] & 15) + 'a'-1, (string[count] & 240)/16 + 'a'-1); 
		count += 1;
	}
	if ((string[count] & 15) != 0 && (string[count] & 240) ==0)
	{
		printf("%c", (string[count] & 15) + 'a'-1);
		count += 1;
	}
	count = 0;
	printf("\n");
	while ((string[count] & 15) != 0 && (string[count] & 240) !=0)
	{
		for(printIndex = 0; printIndex<sizeof(char)*8; printIndex++)
		{
			if ( (string[count] & 128) != 0)
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
			string[count] = string[count]<<1;
		} 
		count++;
		printf(" ");
	}
	if ((string[count] & 15) != 0 && (string[count] & 240) ==0)
	{
		for(printIndex = 0; printIndex<sizeof(char)*8; printIndex++)
		{
			if ( (string[count] & 128) != 0)
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
			string[count] = string[count]<<1;
		} 
	}
	printf("\n");
	return 1;
}

typedef struct BF BF;
struct BF
{
	unsigned int m_cChar :4;
}; 

int CompressStringByFactor2BF(char string[])
{
	int count;
	int sizeOfString = 0;
	BF* myBF;
	char origString[100];
	/*prints 2 versions of the original string*/
	printf("\nstring: %s\n",string);
	PrintStringInBin(string);
	strcpy(string,origString);
	printf("\n");
	/*compress string*/
	while (string[sizeOfString] != '\0')
	{
		sizeOfString++;
	}
	myBF = (BF*)string;

	for ( count = 0; count < sizeOfString; count+=2)
	{
		(myBF+count)->m_cChar = string[count] - 'a'+1;
		(myBF+1+count)->m_cChar =(string[1+count] - 'a'+1);
	}
	
	/*prints the compressed string*/
	printf("compressed string:\n");
	for ( count = 0; count < sizeOfString; count++)
	{
		printf("%c",(myBF+count)->m_cChar +'a'-1);
	}	
	printf("\n");
	return 1;
}

int main (int argc,char* argv[])
{
	int i;
	char string[] = "abcdefg";
	char string2[] = "abcdefg";
	for (i = 0; i < argc; i++)
	{
	printf("%s  ",*(argv+i));
	}
	CompressStringByFactor2(string);	
	CompressStringByFactor2BF(string2);
	return 1;
}
