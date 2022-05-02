PROG=main
FLAGS=-Wall -Wextra -Werror -pedantic -g -O3

all: compile clean

compile: main.o
	@gcc -c *.c $(FLAGS)
	@gcc *.o $(FLAGS) -o $(PROG)

main.o: main.c
	@gcc -c main.c

clean:
	@rm -rf core *.o *.gch

run:
	@./$(PROG)

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(PROG)