#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int RemoveSpaces(char _fileName[])
{
	FILE* fptr;
	char temp[20];
	fptr = fopen(_fileName, "r");
	if (fptr == NULL)
	{
		return 0;
	}
	fscanf(fptr,"%s",temp);
	while(!feof(fptr))
	{
	printf("%s",temp);
	fscanf(fptr,"%s",temp);
	}
	return 1;
}

int CountChars(char _fileName[])
{
	FILE* fptr;
	int temp;
	int array[26] = {0};
	fptr = fopen(_fileName, "r");
	if (fptr == NULL)
	{
		return 0;
	}

	while(!feof(fptr))
	{
		temp = fgetc(fptr);
		if (temp >= 'A' && temp <= 'Z')
		{
			array[temp - 'A']++;
		}
		if (temp >= 'a' && temp <= 'z')
		{
			array[temp - 'a']++;
		}	
	}
	for(temp = 0; temp < 26; temp++)
	{
		printf("%c  %d\n",'A'+temp,array[temp]);
	}
	return 1;
}

typedef struct word word;
	struct word
	{
		char word[30];
		int count;
	};

int CountWords(char _fileName[])
{
	FILE* fptr;
	char temp[30];
	word array[300];
	int index;
	int flag = 0;
	int currentWordCount = 0;
	fptr = fopen(_fileName, "r");
	if (fptr == NULL)
	{
		return 0;
	}
	while(!feof(fptr))
	{
		flag = 0;
		fscanf(fptr,"%s",temp);
		
		for (index = 0; index <= currentWordCount-1; index++)
		{
			if (!strcmp(temp,array[index].word))
			{
				array[index].count ++;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			strcpy(array[currentWordCount].word,temp);
			array[currentWordCount].count ++;
			currentWordCount++;			
		}
	}
	for (index = 0; index <= currentWordCount; index++)
	{
			printf("%20s     %5d\n",array[index].word,array[index].count);
	}
	return 1;
}

int main()
{	
	RemoveSpaces("justApoam.text");
	printf("\n");
	CountChars("justApoam.text");
	printf("\n");
	CountWords("justApoam.text");
	return 1;
}


