
FLAGS = -g -c -ansi -Wall -pedantic 

all: libd.so prog 

prog: p1.o p2.o
	gcc -o prog p1.o p2.o -ld -L.

p1.o : pdir/p1.c pdir/p.h
	gcc $(FLAGS) pdir/p1.c

p2.o : pdir/p2.c pdir/p.h
	gcc $(FLAGS) pdir/p2.c

libd.so : d1.o d2.o 
	gcc -shared -o libd.so d1.o d2.o 

d1.o : libdir/d1.c libdir/d.h
	gcc $(FLAGS) -fPIC libdir/d1.c

d2.o : libdir/d2.c libdir/d.h
	gcc $(FLAGS) -fPIC libdir/d2.c

clean: 
	rm -f *.o
	rm -f prog
	rm -f libd.so

