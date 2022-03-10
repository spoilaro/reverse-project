CC=gcc

main: main.o tools.o
	$(CC) -std=c99 -Wall -o main main.o tools.o