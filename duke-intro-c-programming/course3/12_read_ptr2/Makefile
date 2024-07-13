CC = gcc
CFLAGS = -std=gnu99 -pedantic -Wall -O3
SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))

PROGRAM_NAME = test

$(PROGRAM_NAME): $(OBJS)
	$(CC) -o $@ -O3 $(OBJS)

.PHONY: clean depend
clean:
	rm -f $(PROGRAM_NAME) *.o *~
depend:
	makedepend $(SRCS)

