PROG=main
FLAGS=-Wall -Wextra -Werror -pedantic -g -O3

all: compile clean

compile: main.o ./includes/waveHandler.o ./includes/audioSines.o ./includes/audioCompressor.o ./includes/streamReader.o
	@gcc -c *.c $(FLAGS)
	@gcc *.o $(FLAGS) -o $(PROG) -lm

main.o: main.c ./includes/waveHandler.h ./includes/audioSines.h ./includes/audioCompressor.h ./includes/streamReader.h
	@gcc -c main.c -lm

./includes/waveHandler.o: ./source/waveHandler.c ./includes/waveHandler.h
	@gcc -c ./source/waveHandler.c -lm

./includes/audioSines.o: ./source/audioSines.c ./includes/audioSines.h ./includes/waveHandler.h
	@gcc -c ./source/audioSines.c -lm

./includes/audioCompressor.o: ./source/audioCompressor.c ./includes/audioCompressor.h ./includes/audioSines.h ./includes/waveHandler.h
	@gcc -c ./source/audioCompressor.c -lm

./includes/streamReader.o: ./source/streamReader.c ./includes/streamReader.h ./includes/audioSines.h ./includes/waveHandler.h
	@gcc -c ./source/streamReader.c -lm

clean:
	@rm -rf core *.o *.gch

run:
	@./$(PROG)

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(PROG)