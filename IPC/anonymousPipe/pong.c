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
    char buf[30];
    fd = open("/home/student2-3/Desktop/myFIFO", O_RDONLY); 
   	for (count = 0; count < 4; count++)
        {
       		read(fd, buf, 30);
        	printf("PARENT: just read \"%s\"\n", buf);
        	usleep(10000);	
        }
	close(fd);
    return 0;
}

#endif /*_XOPEN_SOURCE*/
