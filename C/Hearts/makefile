# makefile

TARGET= Hearts.out
CC= gcc
CFLAGS= -ansi -Wall -g -pedantic
OBJS= main.o game.o player.o round.o deck.o ai.o ui.o DV.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) 
	
main.o: main.c game.h player.h round.h ui.h gameErr.h
	$(CC)  $(CFLAGS) -c main.c
	
game.o: game.c game.h player.h round.h ui.h gameErr.h
	$(CC)  $(CFLAGS) -c game.c
	
player.o: player.c player.h ai.h DV.h ui.h gameErr.h
	$(CC)  $(CFLAGS) -c player.c
	
round.o: round.c round.h deck.h player.h ui.h gameErr.h
	$(CC)  $(CFLAGS) -c round.c
	
deck.o: deck.c deck.h gameErr.h
	$(CC)  $(CFLAGS) -c deck.c

ai.o: ai.c ai.h DV.h gameErr.h
	$(CC)  $(CFLAGS) -c ai.c

ui.o: ui.c ui.h DV.h
	$(CC)  $(CFLAGS) -c ui.c

DV.o: DV.c DV.h  
	$(CC)  $(CFLAGS) -c DV.c

clean:
	rm -f $(TARGET) $(OBJS)
