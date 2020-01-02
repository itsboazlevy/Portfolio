#include <sys/socket.h>
#include <sys/types.h> 
#include <arpa/inet.h> // for htons
#include <string.h> // memset
#include <unistd.h>

int main()
{
    // ipv4 tcp socket
    int cSoc = socket(AF_INET,SOCK_STREAM,0);
    // ask to connect to server 
    struct sockaddr_in sIn;
    memset(&sIn,0,sizeof(sIn));
    sIn.sin_family = AF_INET;
    sIn.sin_addr.s_addr = inet_addr("127.0.0.1");
    sIn.sin_port = htons(1234);   
    connect(cSoc,(struct sockaddr*) &sIn, sizeof(sIn) );

    // send buffer 
    int buffer = 78;
    send(cSoc, &buffer, sizeof(buffer) ,0);

    // close descriptor
    close(cSoc);
    return 1;
}