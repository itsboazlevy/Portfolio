//this allows to connect clients to msngr server, server will need to send recieved msg to all clients 
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <stdio.h> 
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h> 

int init()
{
	int sock = socket(AF_INET, SOCK_STREAM,0);
	if (sock < 0)
	{
		perror("socket faild");
	}
	return sock;
}

void connectWith(int _sock, int _serverPort, char* _address)
{
	struct sockaddr_in sin;
	memset(&sin,0,sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr(_address);
	sin.sin_port = htons(_serverPort);
	if(connect(_sock,(struct sockaddr*) &sin, sizeof(sin)) < 0)
	{
			perror("connect faild");
	}
}
	
void sendTo(int _sock, char* _data, int _size)
{
	socklen_t data_len = (socklen_t) _size;
	int sent_bytes = send(_sock, _data, data_len,0);
	if( sent_bytes < 0)
	{
		perror("send faild");
	}
}

int reciveFrom(int _sock)
{
	char buffer[150];
	int buffer_len = sizeof(buffer);
	
	int read_bytes = recv(_sock, buffer, buffer_len,0);
	if(read_bytes == 0)
	{
		close(_sock);
		printf("socket no %d close",_sock);
	}
	else if(read_bytes < 0)
	{
		perror("recv faild");
	}
	else
	{
		printf("%s",buffer);
 
	}
	
	return read_bytes;
}	
	



int main()
{
	int sock = init();
	char data [20] = "hello from client";
	int iteration = 3;
	int returnValue = 1;
	int activity = 0;
	int flag = 1;
	fd_set readfdsMain;
	fd_set readfdsTemp;
	connectWith(sock,4000,"192.168.0.32");
	
	FD_ZERO(&readfdsMain);
	FD_SET(sock, &readfdsMain);
	FD_SET(0, &readfdsMain);
	
	while(flag)
	{
		readfdsTemp = readfdsMain;
		
		activity = select(sock+1, &readfdsTemp, NULL, NULL, NULL);
		
		if((activity <= 0) && (errno!=EINTR))
		{
			printf("select error\n");
		}
		else
		{		
			if((FD_ISSET(sock, &readfdsTemp)))
			{
				reciveFrom(sock);
			}
			if((FD_ISSET(0, &readfdsTemp)))
			{
				char buffer[150];
				int buffer_len = sizeof(buffer);
				int read_bytes = read(0, buffer, buffer_len);
				if(read_bytes < 0)
				{
					perror("recv faild");
					flag = 0;
				}
				else
				{
					sendTo(sock, buffer, sizeof(buffer));
				}
			}
		}
	}
	return 0;
}

