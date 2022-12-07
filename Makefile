.PHONEY: all clean
AR = ar
CC = gcc
FLAGS = -Wall -g
OBJECTS = main.o my_mat.o

all: connections

connections: main.o mat.a
	$(CC) $(FLAGS) -o connections main.o mat.a

mat.a: my_mat.o
	$(AR) -rcs mat.a my_mat.o

main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

clean: 
	rm -f *.o connections

leakTest: clean connections
	valgrind --leak-check=full  --track-origins=yes --show-leak-kinds=all --error-exitcode=1 ./connections
