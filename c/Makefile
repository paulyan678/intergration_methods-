
CC := gcc
CFLAGS := 

all: main
helpers.o: helpers.c helpers.h
	$(CC) $(CFLAGS) -c helpers.c -o helpers.o

main.o: main.c helpers.h main.h
	$(CC) $(CFLAGS) -c main.c -o main.o

main: main.o helpers.o
	$(CC) $(CFLAGS) main.o helpers.o -o main -lm

clean:
	rm -f main main.o helpers.o




