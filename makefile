CC = gcc
AR = ar

# Objects variables
GRAPH_MAIN_OBJECT = my_graph.o
LIB_OBJECTS = my_mat.o
KNAPSACK_MAIN_OBJECT = my_Knapsack.o


DEPS = my_mat.h

# Librarys variables
LIB_S = lib_mat.a

# FLAGS
CFLAGS = -Wall -g

# Declare non-files
.PHONY: all clean

all: my_graph my_Knapsack

# Programs
my_graph: $(GRAPH_MAIN_OBJECT) $(LIB_S)
	$(CC) $(CFLAGS) $^ -o $@

my_Knapsack: $(KNAPSACK_MAIN_OBJECT)
	$(CC) $(CFLAGS) $^ -o $@

# All object files:
*.o: *.c $(DEPS)
	$(CC) $(CFLAGS) -c $^

# Libraries:
$(LIB_S): $(LIB_OBJECTS)
	$(AR) rcs $@ $^

clean:
	rm -f *.o *.a my_graph my_Knapsack *.gch
