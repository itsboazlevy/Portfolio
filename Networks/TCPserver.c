#include <sys/socket.h>
#include <sys/types.h> 
#include <arpa/inet.h> // for htons
#include <string.h> // memset
#include <stdio.h>  
#include <unistd.h> //close

int main()
{
    // ipv4 tcp socket
    int sSoc = socket(AF_INET,SOCK_STREAM,0);

    // will allow to free the port after used, tcp will hold him for a while if not
    int optval = 1;
    setsockopt(sSoc, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // binding the socket
    struct sockaddr_in sIn;
    memset(&sIn,0,sizeof(sIn));
    sIn.sin_family = AF_INET;
    sIn.sin_addr.s_addr = INADDR_ANY;
    sIn.sin_port = htons(1234);
    bind(sSoc, (struct sockaddr*)&sIn, sizeof(sIn));

    // wait for handshake, limit connections to given number
    listen(sSoc,100);

    // new socket for each accept
    int sInLen = sizeof(sIn);
    int sSocSec = accept(sSoc, (struct sockaddr*)&sIn, &sInLen);
    
    // recieve, 0 says connection is closed
    int buffer;
    int answer = recv(sSocSec, &buffer, sizeof(buffer) ,0);
    printf("%d\n",buffer);
    if (answer == 0)
    {
        // close descriptors
        close(sSocSec);
        close(sSoc);
    }
    
    return 1;
}