CC := gcc
CFLAGS := -Wall -Werror -std=c99 -O3
LIBS := -lm -lpthread

SRCDIR := src
OBJDIR := obj
BINDIR := bin
INDIR := include
TESTDIR := test

TARGET := $(BINDIR)/sin_test
OBJS := $(OBJDIR)/sin_test.o $(OBJDIR)/parallel_midpoint.o

all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p $(BINDIR)
	$(CC) $(OBJS) -o $@ $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INDIR)/%.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INDIR) -c $< -o $@ 

$(OBJDIR)/%.o: $(TESTDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INDIR) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)
