CC = gcc
AR = ar

#name program object files

MAIN_OBJECT = main.o
LIB_OBJECTS = my_mat.o
#static library for mat

LIB_S = lib_mat.a

DEPS = "my_mat.h"
CFLAGS = -Wall -g

# Declare them as non-files
.PHONY: all clean

#all make
all: prog

#program
prog: MAIN_OBJECT LIB_OBJECTS
	$(CC) $(CFLAGS) $^ o $@

LIB_S: LIB_OBJECTS
	$(AR) rcs $@ $<

%.o: %.c $(DEPS)
	$(CC) -c $^ $(CFLAGS) -fPIC 

clean:
	rm -f *.o *.a *.so prog *.gch