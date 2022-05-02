PROG=main
FLAGS=-Wall -Wextra -Werror -pedantic -g -O3

all: compile clean

compile: main.o matrix.o
	@gcc -c *.c $(FLAGS)
	@gcc *.o $(FLAGS) -o $(PROG)

main.o: main.c ./includes/matrix.h
	@gcc -c main.c

matrix.o: ./source/matrix.c ./includes/matrix.h
	@gcc -c ./source/matrix.c

clean:
	@rm -rf core *.o *.gch

run:
	@./$(PROG)

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(PROG)