.PHONY: all clean

CC = g++
CFLAGS = -Wall -Wextra -Wshadow -O3
LDFLAGS = -lcurl

OBJS = main.o

all: main

clean:
	rm *.o ; true

main.elf: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<
