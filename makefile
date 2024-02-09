CC = gcc
AR = ar

#name program object files

MAIN_OBJECT = my_graph.o
LIB_OBJECTS = my_mat.o

#static library for mat
LIB_S = lib_mat.a

DEPS = my_mat.h
CFLAGS = -Wall -g

# Declare them as non-files
.PHONY: all clean

#all make
all: prog

#program
prog: $(MAIN_OBJECT) $(LIB_S)
	$(CC) $(CFLAGS) $^ -o $@

$(LIB_S): $(LIB_OBJECTS)
	$(AR) rcs $@ $^
	
$(MAIN_OBJECT): my_graph.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

$(LIB_OBJECTS): my_mat.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *.a prog *.gch
