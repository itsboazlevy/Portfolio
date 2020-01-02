#include <sys/socket.h>
#include <sys/types.h> 
#include <stdio.h>  
#include <arpa/inet.h> 
#include <string.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include "list_itr.h"

void MakeSocUnblocked(int soc)
{
    int flags = fcntl(soc, F_GETFL);
    if (flags == -1)
    {
        printf("fcntl get failed\n");
    }
    flags = fcntl(soc, F_SETFL, flags | O_NONBLOCK); 
    if (flags == -1)
    {
        printf("fcntl set failed\n");
    }
}

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

int AcceptCon(int soc,struct sockaddr_in sStruc)
{
    socklen_t sStrucLen = sizeof(sStruc);
    int newSoc = accept(soc, (struct sockaddr*)&sStruc, &sStrucLen);
    if (newSoc > 2)
    {
        printf("client %d connected\n", newSoc);
        MakeSocUnblocked(newSoc);
    }
    return newSoc;
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

void RunServer(int sSoc, struct sockaddr_in sStruc,  List* myList)
{
    ListItr iterator;
    ListItr iteratorEnd;
    int cSoc;
    int* socPtr;

    for(;;)
    {
        cSoc = AcceptCon(sSoc,sStruc);
        if (cSoc > 2)
        {
            socPtr = malloc(sizeof(int));
            *socPtr = cSoc;
            List_PushTail(myList,(void*)socPtr);
        }
        iteratorEnd =  ListItr_End(myList);        
        for (iterator = ListItr_Begin(myList); iterator != iteratorEnd; iterator = ListItr_Next(iterator))
        {
            socPtr = ListItr_Get(iterator);
            if (Recieve(socPtr) == 0)
            {
                ListItr_Remove(iterator);
                close(*socPtr);
                free(socPtr);
            }
        }
    }
}

int main()
{   
    struct sockaddr_in sStruc;
    int sSoc;
    List* myList = List_Create();
    sSoc = MakeSoc();
    ReuseSoc(sSoc);
    MakeSocUnblocked(sSoc);
    sStruc = BindSocPort(sSoc,1234);
    listen(sSoc,10);    
    RunServer(sSoc,sStruc,myList);
    close(sSoc);
    return 1;
}