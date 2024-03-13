CC := gcc
CFLAGS := -Wall -Werror -std=c99 -O3
LIBS := -lm -lpthread

OBJDIR = obj
BINDIR = bin
SRCDIR = src
INDIR = include
TESTDIR = test

TARGET = $(BINDIR)/sin_test

OBJECTS = $(OBJDIR)/sin_test.o $(OBJDIR)/parallel_mci.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# compile all the .c files into .o files
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INDIR)/%.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INDIR) -c -o $@ $<

$(OBJDIR)/%.o: $(TESTDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INDIR) -c -o $@ $<

clean:
	rm -rf $(OBJDIR) $(BINDIR) 