#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <fcntl.h> 
#include <sys/types.h>
#include <sys/stat.h> 
#include <unistd.h> 

int main(void)
{
	int fd;
	int count;	
	char* randomStrings[4] = {"abcdefg","hijklmnop","qrstuv","wxyz"};
	mkfifo("/home/student2-3/Desktop/myFIFO", 0666); 
	fd = open("/home/student2-3/Desktop/myFIFO", O_WRONLY); 	
    for (count = 0; count < 4; count++)
    {
    	write(fd, randomStrings[count], 30);	
    	printf("CHILD: just wrote %s\n",randomStrings[count]);
    	usleep(10000);	
    }
    close(fd);
    return 0;
}

#endif /*_XOPEN_SOURCE*/
