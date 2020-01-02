#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#define BUFF_SIZE 30
#define STRING_AMOUNT 4
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int count;
    int pfds[2];
    char buf[BUFF_SIZE];
    char* randomStrings[STRING_AMOUNT] = {"abcdefg","hijklmnop","qrstuv","wxyz"};
    pipe(pfds);
    if (!fork()) 
    {
        printf("CHILD: is about to write to the pipe\n");
        for (count = 0; count < STRING_AMOUNT; count++)
        {
        	write(pfds[1], randomStrings[count], BUFF_SIZE);	
        	printf("CHILD: just wrote something\n");
        	usleep(200);	
        }
    } 
    else 
    {
    	usleep(100);	
		for (count = 0; count < STRING_AMOUNT; count++)
        {
        	printf("PARENT: is about to read from pipe\n");
       		read(pfds[0], buf, BUFF_SIZE);
        	printf("PARENT: just read \"%s\"\n", buf);
        	usleep(200);	
        }
    }
    return 0;
}

#endif /*_XOPEN_SOURCE*/
