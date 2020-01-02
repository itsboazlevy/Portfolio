#include <sys/socket.h>
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <string.h> 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct client
{
    int isConnected;
    int socket;
};

struct sockaddr_in GetsStruc()
{
    struct sockaddr_in sStruc;
    memset(&sStruc,0,sizeof(sStruc));
    sStruc.sin_family = AF_INET;
    sStruc.sin_addr.s_addr = inet_addr("127.0.0.1");
    sStruc.sin_port = htons(1234);   
    return sStruc;
}

void ConnectClient(struct client* c, struct sockaddr_in sStruc)
{
    c->socket = socket(AF_INET,SOCK_STREAM,0);
    connect(c->socket,(struct sockaddr*) &sStruc, sizeof(sStruc) );
    c->isConnected = 1;
}


void Initialise(struct client* clients, int n, struct sockaddr_in sStruc)
{
    int i;
    for(i=0; i<n; i++) 
    {
        if (rand()%10 > 5)
        {
            printf("client %d connected\n", i);
            ConnectClient(&clients[i], sStruc);
        }
        else
        {
            clients[i].isConnected = 0;
        }
    }
}

void Run(struct client* clients, int n, struct sockaddr_in sStruc)
{
    int i;
    int verdict;
    for(;;)
    {
        for(i=0; i<n; i++)
        {
            verdict = rand()%10;
            if (clients[i].isConnected == 1)
            {
                if ( verdict > 5)
                {
                    printf("client %d sent msg\n", i);
                    send(clients[i].socket, &verdict, sizeof(verdict) ,0);
                }
                else if ( verdict < 1)
                {
                    printf("client %d disconnected\n", i);
                    close(clients[i].socket);
                    clients[i].isConnected = 0;
                }
            }
            else
            {
                if (verdict > 6)
                {
                    printf("client %d connected\n", i);
                    ConnectClient(&clients[i], sStruc);
                }
            }     
        }
    }
}

int main()
{
    struct client clients[1000];
    struct sockaddr_in sStruc = GetsStruc();
    Initialise(clients, 1000, sStruc);
    Run(clients, 1000, sStruc);
    return 1;
}