.PHONEY: all clean

CC = gcc
FLAGS = -Wall -g
OBJECTS = main.o my_mat.o

all: connections

connections: $(OBJECTS)
	$(CC) $(FLAGS) -o connections $(OBJECTS)

main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

clean:
	rm -f *.o connections