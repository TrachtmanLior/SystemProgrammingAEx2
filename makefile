CC = gcc
AR = ar


# Objects variables
MAIN_OBJECT = my_graph.o
LIB_OBJECTS = my_mat.o

DEPS = my_mat.h

# Librarys variables
LIB_S = lib_mat.a

# FLAGS
CFLAGS = -Wall -g

# Declare non-files
.PHONY: all clean

all: prog

# program
prog: $(MAIN_OBJECT) $(LIB_S)
	$(CC) -o $@ $< $(CFLAGS) ./$(LIB_S) -L.

# All object files:
*.o: *.c $(DEPS)
	$(CC) $(CFLAGS) -c $^

# Libraries:
$(LIB_S): $(LIB_OBJECTS)
	$(AR) rcs $@ $^

clean:
	rm -f *.o *.a prog *.gch
