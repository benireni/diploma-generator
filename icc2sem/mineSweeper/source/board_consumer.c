#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../include/ms_board.h"
#include "../include/board_consumer.h"

MSBoard *consumeBoard(FILE *stream) {
	MSBoard *board = malloc(sizeof(MSBoard));
	board->length = 0, board->height = 0;

	int allocatedLines = INITIAL_SIZE;
	board->grid = malloc(allocatedLines * sizeof(char *)); // allocates with initial len
	do {
		// if at any point there is no available alocated memory left, double it
		if (board->height == allocatedLines) {
			allocatedLines *= 2;
			board->grid = realloc(board->grid, allocatedLines * sizeof(char *));
		}

		board->grid[board->height++] = consumeLine(stream);
	} while (board->grid[board->height - 1] != NULL);
	board->length = strlen(board->grid[0]);

	board->height--;
	board->grid = realloc(board->grid, board->height *  sizeof(char *)); // dismiss unused alocated mem

	return board;
}

char *consumeLine(FILE *stream) {

	int allocatedBytes = INITIAL_SIZE, currentLength = 0;
	char *line = malloc(allocatedBytes*sizeof(char)); // allocates with initial len

	bool hasFinished = false;
	do {
		// if at any point there is no available alocated memory left, double it
		if (currentLength == allocatedBytes) {
			allocatedBytes *= 2;
			line = realloc(line, allocatedBytes*sizeof(char));
		}

		char c = fgetc(stream);
		hasFinished = (c == '\n' || c == EOF);

		line[currentLength++] = hasFinished ? '\0' : c;
	} while (!hasFinished);

	if (line[0] == '\0') {
		free(line);
		return NULL;
	}
	line = realloc(line, sizeof(char) * currentLength); // dismiss unused alocated mem and trim \n or EOF

	return line;
}