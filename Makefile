CC = gcc
FLAGS = -Wall -g
OBJECTS = main.o my_mat.o

all: connections

connections: $(OBJECTS)
    $(CC) $(FLAGS) $(OBJECTS) -o connections

main.o: main.c my_mat.h
    $(CC) $(FLAGS) -c main.c my_mat.h

my_mat.o: my_mat.c my_mat.h
    $(CC) $(FLAGS) -c my_mat.c my_mat.h

.PHONY: all clean

clean:
    rm -f *.o connections

