SRC=src
INC=inc
OBJDIR=obj

CC=gcc
CFLAGS=-I$(INC)
LD=gcc

# Generate object files (TODO)
_OBJS=main.o cpuid.o
OBJS=$(addprefix $(OBJDIR)/, $(_OBJS))

# Test executable

all: runcpuid

runcpuid: $(OBJS)
	$(CC) -o $@ $^

# Object build

$(OBJDIR)/main.o: main.c $(INC)/cpuid.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/cpuid.o: $(SRC)/cpuid.c $(INC)/cpuid.h
	$(CC) $(CFLAGS) -c -o $@ $<

# Directory setup

$(OBJS): $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)
