CC = gcc
CFLAGS = -std=gnu99 -pedantic -Wall -O3
SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))

# The default MAKEFILE_NAME is Makefile. DO NOT USE Makefile.bak
MAKEFILE_NAME = Makefile 
PROGRAM_NAME = test

$(PROGRAM_NAME): $(OBJS)
	$(CC) -o $@ -O3 $(OBJS)

.PHONY: clean depend
clean:
	rm -f $(PROGRAM_NAME) *.o *~
depend:
	makedepend -f $(MAKEFILE_NAME) $(SRCS)

