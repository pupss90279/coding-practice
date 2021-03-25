# compiler gcc for c
CC = g++
CFLAGS = -Wall -g

removeDups: removeDups.o node.o
	$(CC) $(CFLAGS) -o removeDups.exe removeDups.o node.o

removeDups.o: removeDups.cpp node.h
	$(CC) $(CFLAGS) -c removeDups.cpp

node.o: node.cpp node.h
	$(CC) $(CFLAGS) -c node.cpp

all: removeDups.o node.o

clean: 
	$(RM) count *.o *~