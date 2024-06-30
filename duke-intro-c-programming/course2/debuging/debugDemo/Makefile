CC = gcc
CFLAGS = -std=gnu99 -pedantic -Wall -O3
DBGFLAGS = -std=gnu99 -pedantic -Wall -ggdb3 -DDEBUG
SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))
DBGOBJS=$(patsubst %.c,%.dbg.o,$(SRCS))

# The default MAKEFILE_NAME is Makefile. DO NOT USE Makefile.bak
MAKEFILE_NAME = Makefile 
PROGRAM_NAME = test
PROGRAM_DEBUG_NAME = test-debug

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
