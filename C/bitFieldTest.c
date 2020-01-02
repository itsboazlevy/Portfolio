#include <stdlib.h>
#include <stdio.h>
#define MSB 128

union BitFieldUnion
{
	struct BF
	{
		unsigned int first:4;
		unsigned int second:4;
	}BitFieldStruct;
	unsigned char myChar;
};

int PrintStringInBin(char string[])
{
	int count = 0;
	int count2 = 0;
	while (string[count] != '\0')
	{
		for(count2 = 0; count2<sizeof(char)*8; count2++)
		{
			if ( (string[count] & MSB) != 0)
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

int main()
{
	union BitFieldUnion myUnion;
	char string[] = "abcdefg";
	myUnion.BitFieldStruct.first = 6;
	myUnion.BitFieldStruct.second = 4;
	printf("%d\n",myUnion.myChar);
	printf("%s\n",string);
	printf("%c\n",string[2]);
	PrintStringInBin(string);
	return 1;
}
