CFLAGS = -Wall -Wextra -g
CC = gcc

all: insere procura

insere: insere.o
	$(CC) $(CFLAGS) -o insere insere.o

procura: procura.o
	$(CC) $(CFLAGS) -o procura procura.o

clean:
	rm -f insere procura *.o