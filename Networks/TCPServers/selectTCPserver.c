#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h> 
#include <stdio.h>  
#include <arpa/inet.h> 
#include <string.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include "list_itr.h"

int MakeSoc()
{
    int soc = socket(AF_INET,SOCK_STREAM,0);
    if (soc == -1)
    {
        printf("sock making error\n");
    }
    else
    {
        printf("sock %d made\n",soc);
    }
    return soc;
}

void ReuseSoc(int soc)
{
    int result;
    int optval = 1;
    result = setsockopt(soc, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
    if (result == -1)
    {
        printf("free sock error\n");
    }
    else
    {
        printf("sock recycled\n");
    }  
}

struct sockaddr_in BindSocPort(int soc, int port)
{
    int answer;
    struct sockaddr_in sStruc;
    memset(&sStruc,0,sizeof(sStruc));
    sStruc.sin_family = AF_INET;
    sStruc.sin_addr.s_addr = INADDR_ANY;
    sStruc.sin_port = htons(port);
    answer = bind(soc, (struct sockaddr*)&sStruc, sizeof(sStruc));
    if (answer == -1)
    {
       printf("bind error\n");
    }
    else
    {
       printf("port %d binded to socket %d\n",port,soc);
    }
    return sStruc;
}

int Recieve(int* soc)
{
    int buffer;
    int result;
    result = recv(*soc, &buffer, sizeof(buffer) ,0);
    if (result == -1)
    {

    }
    else if (result == 0)
    {
        printf("Recieved close from socket %d\n",*soc);
    }
    else
    {
        printf("Recieved msg from socket %d\n", *soc);
    }
    return result;
}

void RunServer(int masterSoc, struct sockaddr_in sStruc,  List* myList)
{
    ListItr iterator;
    ListItr iteratorEnd;
    fd_set descriptors;
    fd_set desc;
    int newSoc;
    int* socPtr;
    unsigned int sStrucLen = sizeof(sStruc);
    FD_ZERO(&descriptors);
    FD_SET(masterSoc,&descriptors);
    
    for(;;)
    {
        desc = descriptors;
        select(1024, &desc, NULL, NULL, NULL); /* waiting, not non blocking now */
        if(FD_ISSET(masterSoc, &desc))
        {
            newSoc = accept(masterSoc, (struct sockaddr*)&sStruc, &sStrucLen);
            if (newSoc > 2)
            {
                printf("client %d connected\n", newSoc);
                socPtr = malloc(sizeof(int));
                *socPtr = newSoc;
                List_PushTail(myList,(void*)socPtr);
                FD_SET(*socPtr,&descriptors);
            }
            iteratorEnd =  ListItr_End(myList);        
            for (iterator = ListItr_Begin(myList); iterator != iteratorEnd; iterator = ListItr_Next(iterator))
            {
                socPtr = ListItr_Get(iterator);
                if (FD_ISSET(*socPtr, &desc))
                {
                    if (Recieve(socPtr) == 0)
                    {
                        ListItr_Remove(iterator);
                        FD_CLR(*socPtr,&descriptors);
                        close(*socPtr);
                        free(socPtr);
                    }
                }
                
            }
        }
    }
}

int main()
{
    struct sockaddr_in sStruc;
    int masterSoc;
    List* myList = List_Create();
    masterSoc = MakeSoc();
    ReuseSoc(masterSoc);
    sStruc = BindSocPort(masterSoc,1234);
    listen(masterSoc,1024);  
    RunServer(masterSoc, sStruc, myList);
    close(masterSoc);
    return 1;
}