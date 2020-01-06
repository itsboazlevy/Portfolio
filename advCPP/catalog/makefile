TARGET= test
CFLAGS = g++ -ansi -g -pedantic -Wall -Werror
CXXFLAGS = $(CFLAGS) -std=c++03
CPPFLAGS= -I ./include/ -DNDEBUG

$(TARGET): *.cpp
	$(CXXFLAGS) $(CPPFLAGS) -o test *.cpp

run: $(TARGET)
	@./$(TARGET)

clean:
	@rm -f *.gch *.o  $(TARGET)

.PHONY: clean run

