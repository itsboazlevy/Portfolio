TARGET= test
CPPC= g++
CFLAGS = -ansi -g -pedantic -Wall -Werror
CXXFLAGS = $(CFLAGS) -std=c++03

#CPPFLAGS= -I../include -DNDEBUG
OBJS= main.o Node.o ValNode.o BinOpNode.o AllBinNodes.o

$(TARGET): $(OBJS)
	g++ $(CXXFLAGS) *.cpp -o $(TARGET)
	
clean:
	rm -f *.gch  $(TARGET) $(OBJS)
