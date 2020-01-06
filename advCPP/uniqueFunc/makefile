TARGET= test
CFLAGS = -ansi -g -pedantic -Wall -Werror
CXXFLAGS = $(CFLAGS) -std=c++03
#CPPFLAGS= -I../include -DNDEBUG

$(TARGET): test.cpp

run: $(TARGET)
	@./$(TARGET)

clean:
	@rm -f *.gch *.o  $(TARGET)

.PHONY: clean run

