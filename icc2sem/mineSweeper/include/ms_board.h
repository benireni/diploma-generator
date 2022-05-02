#ifndef _MS_BOARD_H_
#define _MS_BOARD_H_

#include <stdio.h>

// space and bomb
#define SPACE '.'
#define BOMB '*'
#define HIDDEN 'X'

// Cell 2D coordinates
typedef struct coordinates { int x, y; } Coordinates;

// Coordinates set to be revealed
typedef struct revealedCoordinates RevealedCoordinates;

// Mine Sweeper Board
typedef struct {
    char  **grid;
    int height, length;
} MSBoard;

// Builds board hints, alocating them overwriting space cells
void hintBoard(MSBoard *board);

// Retrieves how many bombs are in target's 8-sided neighbourhood
int countNearbyBombs(MSBoard *board, Coordinates target);

// Generates hidden board respecting baseBoard dimensions
MSBoard *generateHiddenBoard(MSBoard *baseBoard);

// Reveals target and prints the result of the reveal action
void reveal(MSBoard *board, Coordinates target);

// Reveals hiddenBoard side effected cells affected by targetSlot reveal
void revealSideEffects(Coordinates targetSlot, MSBoard *board, MSBoard *hiddenBoard);

// Prints mine sweeper board
void printBoard(MSBoard *board);

// Frees up board
void destroyBoard(MSBoard *msBoard);

#endif