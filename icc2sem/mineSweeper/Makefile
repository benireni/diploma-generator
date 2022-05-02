PROG=main
FLAGS=-Wall -Wextra -g -O3

all: compile clean

compile: main.o ./include/board_consumer.o ./include/ms_board.o
	@gcc -c *.c $(FLAGS)
	@gcc *.o $(FLAGS) -o $(PROG)

main.o: main.c ./include/board_consumer.h ./include/ms_board.h
	@gcc -c main.c

./include/board_consumer.o: ./source/board_consumer.c ./include/board_consumer.h
	@gcc -c ./source/board_consumer.c

./include/ms_board.o: ./source/ms_board.c ./include/board_consumer.h
	@gcc -c ./source/ms_board.c

clean:
	@rm -rf core *.o *.gch

run:
	@./$(PROG)

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(PROG)