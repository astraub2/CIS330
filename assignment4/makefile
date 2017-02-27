
CC = g++
CFLAGS = -std=c++11 -g

all: reversi

reversi: reversi.o main.o
	$(CC) $(CFLAGS) -o reversi reversi.o main.o

reversi.o: reversi.cpp reversi.h
	$(CC) $(CFLAGS) -c reversi.cpp reversi.h

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) reversi *.o *~