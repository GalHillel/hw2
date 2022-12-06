FLAGS = -Wall -g

main: main.o my_mat.o
	gcc $(FLAGS) -o main main.o my_mat.o

main.o: main.c my_mat.h
	gcc $(FLAGS)  -c main.c

my_mat.o: my_mat.c my_mat.h
	gcc $(FLAGS) -c my_mat.c

.PHONY: clean

clean: rm -f *.o *.a main

