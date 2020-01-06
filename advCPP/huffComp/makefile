TARGET= test
CFLAGS = -ansi -g -pedantic -Wall -Werror
CXXFLAGS = $(CFLAGS) -std=c++03
#CPPFLAGS= -I../include -DNDEBUG
OBJS= main.o CharFreq.o Node.o HuffTree.o

$(TARGET): $(OBJS) *.h
	g++ $(CXXFLAGS) *.cpp -o $(TARGET)
clean:
	rm -f *.gch  $(TARGET) $(OBJS)
