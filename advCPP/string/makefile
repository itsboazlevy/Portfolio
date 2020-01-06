TARGET= str.out
CPPC= g++ 
CPPFLAGS= -ansi -g -pedantic
OBJS= main.o

$(TARGET): $(OBJS)
	$(CPPC) -o $(TARGET) $(OBJS) 
	
main.o: main.cpp string.hpp buffer.hpp
	$(CPPC)  $(CPPFLAGS) -c main.cpp 
	
clean:
	rm -f *.gch *.out *.o
