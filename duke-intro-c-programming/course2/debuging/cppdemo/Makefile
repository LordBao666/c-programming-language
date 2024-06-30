CXX = g++
CXXFLAGS = -std=gnu++17 -pedantic -Wall -O3
DBGFLAGS = -std=gnu++17 -pedantic -Wall -ggdb3 -DDEBUG
SRCS=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp,%.o,$(SRCS))
DBGOBJS=$(patsubst %.cpp,%.dbg.o,$(SRCS))

# The default MAKEFILE_NAME is Makefile. DO NOT USE Makefile.bak
MAKEFILE_NAME = Makefile 
PROGRAM_NAME = helloworld 
PROGRAM_DEBUG_NAME = helloworld-debug
.PHONY: clean depend all
all: $(PROGRAM_NAME) $(PROGRAM_DEBUG_NAME)
$(PROGRAM_NAME): $(OBJS)
	$(CXX) -o $@ -O3 $(OBJS)
$(PROGRAM_DEBUG_NAME): $(DBGOBJS)
	$(CXX) -o $@ -ggdb3 $(DBGOBJS)
%.dbg.o: %.cpp
	$(CXX) $(DBGFLAGS) -c -o $@ $<
clean:
	rm -f $(PROGRAM_NAME) $(PROGRAM_DEBUG_NAME) *.o *.cpp~ *.h~
depend:
	makedepend -f $(MAKEFILE_NAME) $(SRCS)
	makedepend -f $(MAKEFILE_NAME) -a -o .dbg.o  $(SRCS)

# DO NOT DELETE

helloworld.o: talk.h
talk.o: talk.h

helloworld.dbg.o: talk.h
talk.dbg.o: talk.h
