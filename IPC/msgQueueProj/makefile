all : Ping Pong

Ping : MsgQueue.o ping.o MyMalloc.o cyclicQueue.o
	gcc -g -ansi -Wall -pedantic -o Ping MsgQueue.o ping.o MyMalloc.o cyclicQueue.o
	
MsgQueue.o : MsgQueue.c MsgQueue.h
	gcc -c -g -ansi -Wall -pedantic MsgQueue.c
	
ping.o : ping.c
	gcc -c -g -ansi -Wall -pedantic ping.c
	
MyMalloc.o : MyMalloc.c MyMalloc.h
	gcc -c -g -ansi -Wall -pedantic MyMalloc.c

cyclicQueue.o : cyclicQueue.c cyclicQueue.h
	gcc -c -g -ansi -Wall -pedantic cyclicQueue.c

Pong : MsgQueue.o pong.o MyMalloc.o cyclicQueue.o
	gcc -g -ansi -Wall -pedantic -o Pong MsgQueue.o pong.o MyMalloc.o cyclicQueue.o
	
pong.o : pong.c
	gcc -c -g -ansi -Wall -pedantic pong.c

clear :
	rm *.o
	rm MQ
	rm MQping.txt
	rm MQpong.txt
