/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Revisão Alocação Dinâmica, Recursão e Arquivos
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define bool short int
#define false 0
#define true 1

#define INITIAL_SIZE 8

typedef struct { int x, y; } Coordinates;

typedef struct {
    char **elements;
    int lines, cols;
    int people, paths, steps;
    Coordinates cursor;
} Maze;

char *readLine(FILE *stream);

void populateMaze(FILE *stream, Maze *maze);
bool solveMaze(Maze *maze);

bool isCursorInEdge(Maze *maze);

void printMaze(Maze *maze);
void plotMazeData(Maze *maze);

void deleteMaze(Maze *maze);

int main() {
    char *mazeFileName = readLine(stdin);
    FILE *mazeFile = fopen(mazeFileName, "r");
    if (mazeFile == NULL) {
        fprintf(stderr, "Não foi possível abrir o arquivo: %s\n", mazeFileName);
        free(mazeFileName);
        exit(EXIT_FAILURE);
    }

    Maze *maze = malloc(sizeof(Maze));
    maze->paths = 0, maze->people = 0, maze->steps = 0;
    fscanf(mazeFile, "%d %d", &maze->lines, &maze->cols);
    fscanf(mazeFile, "%d %d", &maze->cursor.x, &maze->cursor.y);
    fgetc(mazeFile);

    populateMaze(mazeFile, maze);

    free(mazeFileName);
    fclose(mazeFile);

    solveMaze(maze);
    plotMazeData(maze);

    deleteMaze(maze);

    return 0;
}

bool solveMaze(Maze *maze) {
    maze->elements[maze->cursor.y][maze->cursor.x] = '*';
    maze->steps++;

    if (isCursorInEdge(maze)) return true;

    if (maze->elements[maze->cursor.y][maze->cursor.x - 1] == '.') {
        maze->cursor.x--;
        if (solveMaze(maze)) return true;
        maze->cursor.x++;
    }

    if (maze->elements[maze->cursor.y][maze->cursor.x + 1] == '.') {
        maze->cursor.x++;
        if (solveMaze(maze)) return true;
        maze->cursor.x--;
    }

    if (maze->elements[maze->cursor.y + 1][maze->cursor.x] == '.') {
        maze->cursor.y++;
        if (solveMaze(maze)) return true;
        maze->cursor.y--;
    }

    if (maze->elements[maze->cursor.y - 1][maze->cursor.x] == '.') {
        maze->cursor.y--;
        if (solveMaze(maze)) return true;
        maze->cursor.y++;
    }

    // maze->steps--;
    // maze->elements[maze->cursor.y][maze->cursor.x] = '.';
    return false;
}

void populateMaze(FILE *stream, Maze *maze) {
    maze->elements = malloc(sizeof(char *) * maze->lines);
    for (int i = 0; i < maze->lines; i++) {
        maze->elements[i] = malloc(sizeof(char) * maze->cols);
        for (int j = 0; j < maze->cols; j++) {
            char tmp = fgetc(stream);

            if (tmp == '#') maze->people++;
            else if (tmp == '.') maze->paths++;

            maze->elements[i][j] = tmp; 
        }
        fgetc(stream);
    }

    fgetc(stdin);
}

void plotMazeData(Maze *maze) {
    printMaze(maze);

    printf("Voce escapou de todos! Ninguem conseguiu te segurar!\n");
    printf("Veja abaixo os detalhes da sua fuga:\n");

    printf("----Pessoas te procurando: %d\n", maze->people);

    printf("----Numero total de caminhos validos: %d\n", maze->paths);

    printf("----Numero total de caminhos visitados: %d\n", maze->steps);

    printf("----Exploracao total do labirinto: %.1lf%%\n", 100.0 * maze->steps / maze->paths);
}

bool isCursorInEdge(Maze *maze) {
    if (maze->cursor.x == maze->cols - 1 || maze->cursor.x == 0) return true;
    if (maze->cursor.y == maze->lines - 1 || maze->cursor.y == 0) return true;

    return false;
}

void deleteMaze(Maze *maze) {
    for (int i = 0; i < maze->lines; i++)
        free(maze->elements[i]);
    free(maze->elements);
}

void printMaze(Maze *maze) {
    for (int i = 0; i < maze->lines; i++) {
        for (int j = 0; j < maze->cols; j++)
            putchar(maze->elements[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

char *readLine(FILE *stream) {

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