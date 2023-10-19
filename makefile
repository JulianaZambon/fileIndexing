CFLAGS = -Wall -Wextra -g
CC = gcc

all: main aplicacoes

main: main.o
	$(CC) $(CFLAGS) -o main main.o

main.o: main.c

aplicacoes: aplicacoes.o
	$(CC) $(CFLAGS) -o aplicacoes aplicacoes.o

aplicacoes.o: aplicacoes.c

clean:
	rm -f *.o main aplicacoes