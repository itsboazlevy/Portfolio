#include <stdio.h>
#include <string.h>

int FindWordOcc(char _word[],char _fileName[])
{
	char tempWord[20];
	int count;
	FILE* ptr = fopen (_fileName, "r+");
	
	if (ptr == NULL)
	{
		printf("error in fopen");
	}
	count=0;
	while(!feof(ptr))
	{
		fscanf(ptr,"%s",tempWord);
		if (strcmp(tempWord,_word) == 1)
		{
			count++;
		}
	}
return count;
}

int main()
{
/*
general tests
*/
	FILE* ptr;
	FILE* ptr2;
	char temp;
	int n;
	int count;
	char tempS[100];
	ptr = fopen("newFile.c", "w+");
	if (ptr == NULL)
	{
		printf("error in fopen");
	}
	fputc('a',ptr);
	fputc('b',ptr);
	fputc('c',ptr);
	fputs("defghij",ptr);
	fprintf(ptr,"klmnop");
	fprintf(ptr,"\nqrstuv wx\n    y      z\n123");
	fclose(ptr);
	ptr = fopen("newFile.c", "r+");
	if (ptr == NULL)
	{
		printf("error in fopen");
	}
	printf("%c",fgetc(ptr));
	fscanf(ptr,"%c",&temp);
	printf("%c", temp);
	fscanf(ptr,"%c",&temp);
	printf("%c", temp);
	fscanf(ptr,"%s",tempS);
	printf("%s", tempS);
	printf("%d", feof(ptr));
	fscanf(ptr,"%s",tempS);
	printf("%s", tempS);
	printf("%d", feof(ptr));
	printf("%s",fgets(tempS,5,ptr));
	printf("%s",fgets(tempS,20,ptr));
	fclose(ptr);
	printf("--------------\n");
/*
this prints the n last lines of a file, tests more functions
*/
	ptr2 = fopen("newFile2.c", "r+");
	if (ptr == NULL)
	{
		printf("error in fopen");
	}
	count=0;
	fseek(ptr2,count,2);
	n=5;
	while (count!=n)
	{
		if (fgetc(ptr) == '\n')
		{
			count++;
		}
		fseek(ptr2,-2,1);
	}
	fseek(ptr2,2,1);
	for (n=5; n > 0; n--)
	{
		printf("%s",fgets(tempS,100,ptr2));
	}
	fclose(ptr2);
	printf("--------------\n");
	printf("%d",FindWordOcc("money","newFile2.c"));
	printf("--------------\n");
	
	return 1;
}

