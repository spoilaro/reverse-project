CC=gcc

reverse: main.o tools.o
	$(CC) -std=c99 -Wall -o reverse main.o tools.o

clean:
	rm *.o reverse
