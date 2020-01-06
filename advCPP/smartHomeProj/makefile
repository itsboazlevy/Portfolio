TARGET= test
CFLAGS = g++ -ansi -g -pedantic -Wall -Werror
CXXFLAGS = $(CFLAGS) -std=c++03
CPPFLAGS= -I ./include/ -DNDEBUG

all: $(TARGET) SensorFire.so

SensorFire.so : SensorFire.o
	g++ -shared -o SensorFire.so SensorFire.o
	
SensorFire.o : SensorFire.cpp SensorFire.h
	$(CXXFLAGS) -c -fPIC SensorFire.cpp
 
$(TARGET): Agent.cpp Agent.h Condition.cpp Condition.h Controller.cpp Controller.h Distributer.cpp Distributer.h Event.cpp Event.h MTQueue.hpp MTQueue.h Mutex.cpp Mutex.h Runnable.cpp Runnable.h Sensor.cpp Sensor.h Server.cpp Server.h Thread.cpp Thread.h Tokenizer.cpp Tokenizer.h Main.cpp config.txt ControllerHVAC.cpp ControllerHVAC.h ControllerSprinkler.cpp ControllerSprinkler.h
	$(CXXFLAGS) -o $(TARGET) *.cpp -lpthread -ldl

run: $(TARGET)
	@./$(TARGET)

clean:
	@rm -f *.so *.gch *.o  $(TARGET)

.PHONY: clean run all

SensorFire.o : SensorFire.cpp SensorFire.h
	$(CXXFLAGS) -c -fPIC SensorFire.cpp
