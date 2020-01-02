#include <stdio.h>
#include <stdlib.h>

struct student
	{
		char name[30];
		int age;
		int education;
	};
	
void swap(struct student *x,struct student *y)
{
	struct student temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int myStrLen(const char *str)
{
    int i = 0;
    int value = 1;
    while ( value != '\0')
    {
        value = *(str+i);
        i++;
    }
    i--;
    return i;
}   

int myStrCmp(const char *str, const char *str2)
{
    int tempValue,i;
    for(i=0; i < myStrLen(str); i++)
    {
        tempValue = *(str+i) - *(str2+i);
        if(tempValue != 0)
        {
            break;
        }
    }
    return tempValue;
}


int sortStructByAge(struct student a, struct student b, struct student c, struct student d, struct student e)
{
	int listSize;
	int i,j;
	struct student temp;
	struct student list[5] = {a,b,c,d,e};
	listSize = sizeof(list)/sizeof(struct student);

	for (i = 0; i < listSize-1 ; i++)
	{
		for (j = 0; j < listSize-i-1; j++)
		{
			if ((*(list+j)).age > (*(list+1+j)).age)
			{
				swap((list+j),(list+j+1));
			}
		}
	}
	for (i = 0; i < listSize; i++)
	{
		printf("%s %d \n",(*(list+i)).name, (*(list+i)).age);   	
	}
}

int sortStructByName(struct student a, struct student b, struct student c, struct student d, struct student e)
{
	int listSize;
	int i,j;
	struct student temp;
	struct student list[5] = {a,b,c,d,e};
	listSize = sizeof(list)/sizeof(struct student);

	for (i = 0; i < listSize-1 ; i++)
	{
		for (j = 0; j < listSize-i-1; j++)
		{
			if (myStrCmp((*(list+j)).name, (*(list+1+j)).name) > 0)
			{
				swap((list+j),(list+j+1));
			}
		}
	}
	for (i = 0; i < listSize; i++)
	{
		printf("%s %d \n",(*(list+i)).name, (*(list+i)).age);   	
	}
}


int main()
{	
	struct student a = {"Anastasia",259,12};
	struct student b = {"Pavel",34,12};
	struct student c = {"Adir",22,12};
	struct student d = {"Boaz",11,31};
	struct student e = {"Izik",1,100};
	sortStructByAge(a,b,c,d,e);
	sortStructByName(a,b,c,d,e);
	return 1;
}

