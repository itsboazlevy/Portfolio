#include <stdio.h>

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

int reverseString(char *str)
{
	char temp;
	int size = myStrLen(str);
	for (int i = 0; i < size/2; i++)
	{
		temp = *(str+i);
		*(str+i) = *(str + size-1-i);
		*(str + size-1-i) = temp;
	}
	return 1;
}

int squeeze(char *str1, const char *str2)
{
	int str1Size = myStrLen(str1);
	int str2Size = myStrLen(str2);
	int i,j,k;
	for (i = 0; i < str2Size; i++)
	{
		for (j = 0; j < str1Size; j++)
		{
			if (*(str2+i) == *(str1+j))
			{
				for (k = j; k < str1Size; k++)
				{
					*(str1+k) = *(str1+k+1);
				}
				*(str1+k) = '\0';
				str1Size --;
			}
		}
	}
	return 1;
}

float atoi(char *str)
{
    int strLen = myStrLen(str);    
    int i, sign = 1; 
    float tempInt = 0, pointFix = 0;
    for(i = 0; i < strLen ; i++)
        {
            if (*(str+i) <= '9' && *(str+i) >= '0')
            {
                tempInt *= 10;
                tempInt += (*(str+i) - '0') ;
            }
            else if (*(str+i) == ' ' || *(str+i) == '+')
            {
                if ( tempInt != 0)
                {
                    break;
                }
            }
            else if (*(str+i) == '-')
            {
                if ( tempInt != 0)
                {
                   break;
                }
                sign = -1;
            }
            else if (*(str+i) == '.' && pointFix == 0)
            {
                if (tempInt != 0)
                {
                    pointFix = i;  
                }
            } 
            else
            {
                break;
            }
        }
    while (pointFix < i-1 && pointFix != 0)
    {
        tempInt /= 10.0;
        pointFix++;
    }
    tempInt *= sign;
    return tempInt;
}

int itoa (int num, char *str)
{	
	int reversedNumber = 0,i = 0; 
	if (str == NULL)
	{
		return 0;
	}
	if (num < 0)
	{
		*str = '-';
		str++;
		num *= -1;
	}
	while(num != 0)
	{
		reversedNumber = (reversedNumber*10) + (num%10);
		num /= 10;
	}
	while (reversedNumber != 0)
	{
		*(str+i) = reversedNumber%10 + '0';
		reversedNumber /= 10;
		i++;
	}
	*(str+i) = '\0';
	return 1;	
}




