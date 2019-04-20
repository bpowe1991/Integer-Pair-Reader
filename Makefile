CC=gcc
CFLAGS= -g

all: proj3 childProj3

proj3: proj3.o
	$(CC) $(CFLAGS) -o $@ proj3.o

proj3.o: proj3.c
	$(CC) $(CFLAGS) -c proj3.c

childProj3: childProj3.o
	$(CC) $(CFLAGS) -o $@ childProj3.o

childProj3.o: childProj3.c
	$(CC) $(CFLAGS) -c childProj3.c

clean:
	rm *.o proj3 childProj3 intPipe
