TARGET= test
CFLAGS = g++ -ansi -g -pedantic -Wall -Werror
CXXFLAGS = $(CFLAGS) -std=c++03
CPPFLAGS= -I ./include/ -DNDEBUG

all : $(TARGET) libcat.so

$(TARGET) : main.cpp
	$(CXXFLAGS) -o test main.cpp -ldl

libcat.so : Cat.o
	g++ -shared -o libcat.so Cat.o

Cat.o : Cat.cpp Cat.h
	$(CXXFLAGS) -c -fPIC Cat.cpp

clean: 
	rm -f *.o
	rm -f *.so
	rm -f *.out
	rm $(TARGET)
	
