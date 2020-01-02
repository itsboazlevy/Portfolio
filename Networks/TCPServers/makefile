FLAGS = -ansi -pedantic -Wall -g
all: nbTCPserver sTCPserver clients

clients : TCPclients.c
	gcc -o clients $(FLAGS) TCPclients.c

sTCPserver : list.o list_itr.o list_functions.o selectTCPserver.o
	gcc -o sTCPserver $(FLAGS) list.o list_itr.o list_functions.o selectTCPserver.o 

nbTCPserver : list.o list_itr.o list_functions.o noBlockTCPserver.o
	gcc -o nbTCPserver $(FLAGS) list.o list_itr.o list_functions.o noBlockTCPserver.o 

noBlockTCPserver.o : noBlockTCPserver.c 
	gcc -c $(FLAGS) noBlockTCPserver.c

selectTCPserver.o : selectTCPserver.c 
	gcc -c $(FLAGS) selectTCPserver.c
	
list.o : list.c list.h
	gcc -c $(FLAGS) list.c

list_itr.o : list_itr.c list_itr.h
	gcc -c $(FLAGS) list_itr.c

list_functions.o : list_functions.c list_functions.h
	gcc -c $(FLAGS) list_functions.c

clean:
	rm -f *.o nbTCPserver sTCPserver clients