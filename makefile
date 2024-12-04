CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJS = main.o fifo.o

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o main
