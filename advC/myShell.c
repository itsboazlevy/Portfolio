#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


int main()
{
	int i;
	pid_t fPid;
	char* nPtr;
	char* chPtr;
    char *newargv[100];
    char *newenviron[] = { NULL };
	char str[100];
	while(1)
	{
		fPid = fork();
		if (fPid != 0)
		{
			wait(NULL);
		}
		else
		{	
			printf("Boaz:");
			fgets(str,100,stdin);
			nPtr = strchr(str,'\n');
			if (nPtr != NULL)
			{
				*nPtr = '\0';
			}
			
			chPtr = strtok(str," ");
			for( i = 0; chPtr != NULL; i++)
			{
				newargv[i] = chPtr;	
				chPtr = strtok(NULL," ");
			}	
			newargv[i] = NULL;
			if (execve(str,newargv,newenviron) < 0)
			{
				perror("MYEXECRAN");
			}
			break;
		}
	}
	return 1;
}


