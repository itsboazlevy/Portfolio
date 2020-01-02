#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Person Person; 
struct Person
{
	int m_id;
	char m_name[128];
	int m_age;
	Person* m_next;
};


int main()
{	
	
	int array[10] = {1,2,3,4,5,6,7,8,9,10};
	int result[10];
	int count = 0;
	FILE* fptr = NULL;
	Person* a;
	Person* resultPerson = (Person*)malloc(sizeof(Person));
	if (resultPerson == NULL)
	{
		return 0;
	}
	
	a = (Person*)malloc(sizeof(Person)); 
 	a->m_id = 14;
	a->m_age = 40;
	strcpy(a->m_name,"arturo");
 	a->m_next = NULL;
 	
 	fptr =fopen("fWriteRead.bin", "w+");
 	if (fptr == NULL)
 	{
 		return 0;
 	}
 	fwrite(array,sizeof(int),10,fptr);
 	fseek(fptr,0,SEEK_SET); 
 	fread(result,sizeof(int),10,fptr);
	fclose(fptr);
 	
 	while(count<10)
 	{
 		printf("%d ",result[count]);
 		count++;
 	}
 	printf("\n-------\n");
 	fptr =fopen("fWriteRead.bin", "w+");
 	if (fptr == NULL)
 	{
 		return 0;
 	}
 	fwrite(a,sizeof(Person),1,fptr);
 	fseek(fptr,0,SEEK_SET); 
 	fread(resultPerson,sizeof(Person),1,fptr);
 	printf("%d ",resultPerson->m_id);
 	printf("%d ",resultPerson->m_age);
 	printf("%s ",resultPerson->m_name);
 	printf("%p ",(void*)resultPerson->m_next);
	fclose(fptr);
 	printf("\n-------\n");
 	return 1;
}	
