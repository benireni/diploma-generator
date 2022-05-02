/*******************************************************************************
 |                        USP - Universidade de São Paulo                      |
 |             ICMC - Instituto de Ciências Matemáticas e de Computação        |
 *******************************************************************************
 |                     Bacharelado em Ciências de Computação                   |
 |                                    2021/1                                   |
 |                                                                             |
 |                       Autor: Benício Januário (12543843)                    |
 *******************************************************************************
  > Admirável Mundo Caótico
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define nextFrom(x, limit) ((x + 1) % limit)
#define prevFrom(x, limit) ((x - 1 + limit) % limit)

#define doubleNextFrom(x, limit) nextFrom(nextFrom(x, limit), limit)
#define doublePrevFrom(x, limit) prevFrom(prevFrom(x, limit), limit)

typedef struct { char state; int x, y; } Cell;

typedef struct {
    Cell **generation;
    char nMetric;
    int length, height;
} Game;

void skipGeneration(Game *game);
int countLivingNeighbours(Game game, Cell referenceCell);
Cell **copyMatrix(Cell **matrix, int mxLines, int mxColumns);
void printGeneration(Game game);
void msleep(long msec);

int main() {
    char neighbourhoodMetrics;
    int gameLines, gameColumns, totalGens;
    scanf("%d %d", &gameLines, &gameColumns);
    scanf("%d ", &totalGens);
    scanf("%c ", &neighbourhoodMetrics);

    if (gameLines <= 0 || gameColumns <= 0 || totalGens <= 0 ||
        (neighbourhoodMetrics != 'M' && neighbourhoodMetrics != 'N')) {
        printf("Dados de entrada apresentam erro.\n");
        exit(1);
    }

    Cell **gameState = malloc(sizeof(Cell *) * gameLines);
    for (int i = 0; i < gameLines; i++) {
        gameState[i] = (Cell *) malloc(sizeof(Cell) * gameColumns);

        for (int j = 0; j < gameColumns; j++)
            gameState[i][j] = (Cell) {.x = j, .y = i, .state = fgetc(stdin)};
        fgetc(stdin);
    }

    Game game = {
        .generation = gameState,
        .height = gameLines,
        .length = gameColumns,
        .nMetric = neighbourhoodMetrics
    };

    printGeneration(game);
    for (int currentGen = 0; currentGen < totalGens; currentGen++) {
        skipGeneration(&game);
        printGeneration(game);
    }

    for (int i = 0; i < game.height; i++)
        free(game.generation[i]);
    free(game.generation);

    return 0;
}

void skipGeneration(Game *game) {

    Game gameRef = *game;
    gameRef.generation = copyMatrix(game->generation, game->height, game->length);

    for (int i = 0; i < game->height; i++)
        for (int j = 0; j < game->length; j++) {
            int cellNeighbours = countLivingNeighbours(gameRef, gameRef.generation[i][j]);

            if (cellNeighbours < 2 || cellNeighbours > 3) game->generation[i][j].state = '.';
            else if (cellNeighbours == 3) game->generation[i][j].state = 'x';
        }

    for (int i = 0; i < gameRef.height; i++)
        free(gameRef.generation[i]);
    free(gameRef.generation);
}


int countLivingNeighbours(Game game, Cell referenceCell) {
    int i = referenceCell.y, j = referenceCell.x, livingNeighbours = 0;
    if (game.nMetric == 'M') { // Moore
        if (game.generation[prevFrom(i, game.height)][prevFrom(j, game.length)].state == 'x')
            livingNeighbours++;

        if (game.generation[prevFrom(i, game.height)][j].state == 'x')
            livingNeighbours++;

        if (game.generation[prevFrom(i, game.height)][nextFrom(j, game.length)].state == 'x')
            livingNeighbours++;

        if (game.generation[i][prevFrom(j, game.length)].state == 'x')
            livingNeighbours++;

        if (game.generation[i][nextFrom(j, game.length)].state == 'x')
            livingNeighbours++;

        if (game.generation[nextFrom(i, game.height)][prevFrom(j, game.length)].state == 'x')
            livingNeighbours++;

        if (game.generation[nextFrom(i, game.height)][j].state == 'x')
            livingNeighbours++;

        if (game.generation[nextFrom(i, game.height)][nextFrom(j, game.length)].state == 'x')
            livingNeighbours++;

    } else if (game.nMetric == 'N') { // Von Neumann
        if (game.generation[prevFrom(i, game.height)][j].state == 'x')
            livingNeighbours++;

        if (game.generation[doublePrevFrom(i, game.height)][j].state == 'x')
            livingNeighbours++;

        if (game.generation[i][prevFrom(j, game.length)].state == 'x')
            livingNeighbours++;

        if (game.generation[i][doublePrevFrom(j, game.length)].state == 'x')
            livingNeighbours++;

        if (game.generation[nextFrom(i, game.height)][j].state == 'x')
            livingNeighbours++;

        if (game.generation[doubleNextFrom(i, game.height)][j].state == 'x')
            livingNeighbours++;

        if (game.generation[i][nextFrom(j, game.length)].state == 'x')
            livingNeighbours++;            

        if (game.generation[i][doubleNextFrom(j, game.length)].state == 'x')
            livingNeighbours++;

    }

    return livingNeighbours;
}

Cell **copyMatrix(Cell **matrix, int mxLines, int mxColumns) {
    Cell **newMx = malloc(sizeof(Cell *) * mxLines);
    for (int i = 0; i < mxLines; i++) {
        newMx[i] = malloc(sizeof(Cell) * mxColumns);
        for (int j = 0; j < mxColumns; j++) newMx[i][j] = matrix[i][j];
    }
    return newMx;
}

void printGeneration(Game game) {
    system("clear");
    for (int i = 0; i < game.height; i++) {
        for (int j = 0; j < game.length; j++)
            printf("%c", game.generation[i][j].state);
        printf("\n");
    }
    msleep(300);
}

void msleep(long msec) {
    struct timespec ts;

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    nanosleep(&ts, &ts);
}