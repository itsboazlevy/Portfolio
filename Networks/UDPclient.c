#include <sys/socket.h>
#include <sys/types.h> 
#include <arpa/inet.h> // for htons
#include <string.h> // memset

int main()
{
    // ipv4 udp socket
    int cSoc = socket(AF_INET,SOCK_DGRAM,0);

    // send buffer 
    struct sockaddr_in sIn;
    memset(&sIn,0,sizeof(sIn));
    sIn.sin_family = AF_INET;
    sIn.sin_addr.s_addr = inet_addr("127.0.0.1");
    sIn.sin_port = htons(1234);
    int buffer = 5;
    sendto( cSoc,(void*)&buffer,sizeof(buffer),0, (struct sockaddr*) &sIn, sizeof(sIn) );
    return 1;
}
