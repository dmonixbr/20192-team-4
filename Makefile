CC := g++
CX := gcc
SRCDIR := src
TSTDIR := tests
OBJDIR := build
BINDIR := bin

MAIN := program/main.cpp
TESTER := program/tester.cpp

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o)) build/sqlite3.o
TSTSOURCES := $(shell find $(TSTDIR) -type f -name *.$(SRCEXT))

DBASE := -c sqlite/sqlite3.c -ldl -o build/sqlite.o 
DSHELL := -c sqlite/shell.c -ldl -o build/shell.c 

CFLAGS := -g -Wall -O3 -std=c++11 -pthread -Wl,--no-as-needed -ldl -lsqlite3 
INC := -I include/ -I third_party/ -I sqlite/

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

database:
	$(CX) $(DBASE)
	$(CX) $(DSHELL)

main: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(MAIN) $^ -o $(BINDIR)/main

tests: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(TESTER) $(TSTSOURCES) $^ -o $(BINDIR)/tester
	$(BINDIR)/tester

valgrind: main
	valgrind --leak-check=full --track-origins=yes $(BINDIR)/main

all: main

run: database main
	$(BINDIR)/main

clean:
	$(RM) -r $(OBJDIR)/* $(BINDIR)/*

.PHONY: clean coverage