CC = gcc
CFLAGS = -std=gnu99 -pedantic -Wall -O3
DBGFLAGS = -std=gnu99 -pedantic -Wall -ggdb3 -DDEBUG
SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))
DBGOBJS=$(patsubst %.c,%.dbg.o,$(SRCS))
PROGRAM_NAME = test 
PROGRAM_DEBUG_NAME = test-debug
.PHONY: clean depend all
all: $(PROGRAM_NAME) $(PROGRAM_DEBUG_NAME)
$(PROGRAM_NAME): $(OBJS)
	gcc -o $@ -O3 $(OBJS)
$(PROGRAM_DEBUG_NAME): $(DBGOBJS)
	gcc -o $@ -ggdb3 $(DBGOBJS)
%.dbg.o: %.c
	gcc $(DBGFLAGS) -c -o $@ $<
clean:
	rm -f $(PROGRAM_NAME) $(PROGRAM_DEBUG_NAME) *.o *.c~ *.h~
depend:
	makedepend $(SRCS)
	makedepend -a -o .dbg.o  $(SRCS)
