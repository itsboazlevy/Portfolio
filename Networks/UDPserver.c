#include <sys/socket.h>
#include <sys/types.h> 
#include <arpa/inet.h> // for htons
#include <string.h> // memset
#include <stdio.h> 

int main()
{
    // ipv4 udp socket
    int sSoc = socket(AF_INET,SOCK_DGRAM,0);

    // binding the socket
    struct sockaddr_in sIn;
    memset(&sIn,0,sizeof(sIn));
    sIn.sin_family = AF_INET;
    sIn.sin_addr.s_addr = INADDR_ANY;
    sIn.sin_port = htons(1234);
    bind(sSoc, (struct sockaddr*)&sIn, sizeof(sIn));

    // recieve buffer 
    int buffer;
    int sInLen = sizeof(sIn);
    recvfrom(sSoc, (void*)&buffer, sizeof(buffer), 0, (struct sockaddr*) &sIn, &sInLen );
    printf("%d\n",buffer);
    sendto( sSoc,(void*)&buffer,sizeof(buffer),0, (struct sockaddr*) &sIn, sizeof(sIn) );
    
    return 1;
}