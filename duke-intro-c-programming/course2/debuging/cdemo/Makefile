CC = gcc
CFLAGS = -std=gnu99 -pedantic -Wall -O3
DBGFLAGS = -std=gnu99 -pedantic -Wall -ggdb3 -DDEBUG

# The default MAKEFILE_NAME is Makefile. DO NOT USE Makefile.bak
MAKEFILE_NAME = Makefile 
PROGRAM_NAME = helloworld
PROGRAM_DEBUG_NAME = helloworld-debug
SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))
DBGOBJS=$(patsubst %.c,%.dbg.o,$(SRCS))
.PHONY: clean depend all
all: $(PROGRAM_NAME) $(PROGRAM_DEBUG_NAME)
$(PROGRAM_NAME): $(OBJS)
	$(CC) -o $@ -O3 $(OBJS)
$(PROGRAM_DEBUG_NAME): $(DBGOBJS)
	$(CC) -o $@ -ggdb3 $(DBGOBJS)
%.dbg.o: %.c
	$(CC) $(DBGFLAGS) -c -o $@ $<
clean:
	rm -f $(PROGRAM_NAME) $(PROGRAM_DEBUG_NAME) *.o *.c~ *.h~
depend:
	makedepend -f $(MAKEFILE_NAME) $(SRCS)
	makedepend -f $(MAKEFILE_NAME) -a -o .dbg.o  $(SRCS)

# DO NOT DELETE

helloworld.o: talk.h
talk.o: talk.h

helloworld.dbg.o: talk.h
talk.dbg.o: talk.h
