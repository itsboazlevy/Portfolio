hashMap : hashMap.o hashMapTest.o list_itr.o list.o
	gcc -o hashMap -g -ansi -Wall -pedantic hashMap.c hashMapTest.c list_itr.c list.c -lm

hashMap.o : hashMap.c
	gcc -c -g -ansi -Wall -pedantic hashMap.c -lm

hashMapTest.o : hashMapTest.c
	gcc -c -g -ansi -Wall -pedantic hashMapTest.c

list_itr.o : list_itr.c
	gcc -c -g -ansi -Wall -pedantic list_itr.c

list.o : list.c
	gcc -c -g -ansi -Wall -pedantic list.c
