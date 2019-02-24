CC = gcc
CFLAGS = -Wall -std=c99

all: test

quick.o: quick.c points_segments.h 
	$(CC) $(CFLAGS) -c quick.c

naive.o: naive.c points_segments.h
	$(CC) $(CFLAGS) -c naive.c
	
test.o: test.c points_segments.h
	$(CC) $(CFLAGS) -c test.c  
	
test: quick.o naive.o test.o
	$(CC) $(CFLAGS) -o test quick.o naive.o test.o

clean:
	rm *.o test
