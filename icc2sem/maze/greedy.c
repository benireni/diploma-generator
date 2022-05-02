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
#include <math.h>

#define bool short int
#define false 0
#define true 1

#define INITIAL_SIZE 8

typedef struct { int x, y; } Coordinates;

typedef struct {
    char **elements;
    int lines, cols;
    int people, paths, steps;
} Maze;

char *readLine(FILE *stream);

void populateMaze(FILE *stream, Maze *maze);
bool solveMaze(Maze *maze, int i, int j);

bool isCursorOutOfBounds(Maze *maze, int i, int j);

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

    Coordinates start;
    fscanf(mazeFile, "%d %d", &start.y, &start.x);
    fgetc(mazeFile);

    populateMaze(mazeFile, maze);

    free(mazeFileName);
    fclose(mazeFile);

    solveMaze(maze, start.y, start.x);
    plotMazeData(maze);

    deleteMaze(maze);

    return 0;
}

bool solveMaze(Maze* maze, int i, int j) {
  if (isCursorOutOfBounds(maze, i, j)) return true;

  if (maze->elements[i][j] != '.') return false;
  else {
    maze->elements[i][j] = '*';
    maze->steps++;

    if (solveMaze(maze, i - 1, j)) return true;
    if (solveMaze(maze, i, j + 1)) return true;
    if (solveMaze(maze, i + 1, j)) return true;
    return solveMaze(maze, i, j - 1);
  }
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

    printf("----Numero total de caminhos validos:   %d\n", maze->paths);

    printf("----Numero total de caminhos visitados: %d\n", maze->steps);

    printf("----Exploracao total do labirinto: %.0lf.0%%\n", floor(100.0 * maze->steps/maze->paths));
}

bool isCursorOutOfBounds(Maze *maze, int i, int j) {
    return i < 0 || i >= maze->lines || j < 0 || j >= maze->cols;
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