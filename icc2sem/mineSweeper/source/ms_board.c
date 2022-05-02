#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../include/ms_board.h"

struct revealedCoordinates { Coordinates *coordinates; int length; };

void reveal(MSBoard *board, Coordinates target) {

    if (board->grid[target.y][target.x] != BOMB) {
        MSBoard *gameBoard = generateHiddenBoard(board);
        revealSideEffects(target, board, gameBoard);

        printBoard(gameBoard);
        destroyBoard(gameBoard);
    } else {
        printBoard(board);
    }

}

void revealSideEffects(Coordinates targetSlot, MSBoard *board, MSBoard *hiddenBoard) {

    char targetContent = board->grid[targetSlot.y][targetSlot.x];
    if (targetContent == BOMB) return;

    if (isdigit(targetContent)) {
        hiddenBoard->grid[targetSlot.y][targetSlot.x] = targetContent;
        return;
    }

    if (targetContent == SPACE && hiddenBoard->grid[targetSlot.y][targetSlot.x] == HIDDEN) {
        hiddenBoard->grid[targetSlot.y][targetSlot.x] = targetContent;

        if (targetSlot.y > 0) {
            revealSideEffects((Coordinates) {
                .x = targetSlot.x,
                .y = targetSlot.y - 1
            }, board, hiddenBoard);
        }

        if (targetSlot.y > 0 && targetSlot.x < board->length - 1)
            revealSideEffects((Coordinates) {
                .x = targetSlot.x + 1,
                .y = targetSlot.y - 1
            }, board, hiddenBoard);

        if (targetSlot.x < board->length - 1)
            revealSideEffects((Coordinates) {
                .x = targetSlot.x + 1,
                .y = targetSlot.y
            }, board, hiddenBoard);

        if (targetSlot.y < board->height - 1 && targetSlot.x < board->length - 1)
            revealSideEffects((Coordinates) {
                .x = targetSlot.x + 1,
                .y = targetSlot.y + 1
            }, board, hiddenBoard);

        if (targetSlot.y < board->height - 1)
            revealSideEffects((Coordinates) {
                .x = targetSlot.x,
                .y = targetSlot.y + 1
            }, board, hiddenBoard);

        if (targetSlot.y < board->height - 1 && targetSlot.x > 0)
            revealSideEffects((Coordinates) {
                .x = targetSlot.x - 1,
                .y = targetSlot.y + 1
            }, board, hiddenBoard);

        if (targetSlot.x > 0)
            revealSideEffects((Coordinates) {
                .x = targetSlot.x - 1,
                .y = targetSlot.y
            }, board, hiddenBoard);

        if (targetSlot.y > 0 && targetSlot.x > 0)
            revealSideEffects((Coordinates) {
                .x = targetSlot.x - 1,
                .y = targetSlot.y - 1
            }, board, hiddenBoard);
    }
}

void hintBoard(MSBoard *board) {
    for (int i = 0; i < board->height; i++)
    for (int j = 0; j < board->length; j++) {

        if (board->grid[i][j] == BOMB)
            continue;

        int nearbyBombs = countNearbyBombs(
            board,
            (Coordinates) {
                .y = i, .x = j
            }
        );

        if (nearbyBombs > 0)
            board->grid[i][j] = '0' + nearbyBombs;
    }
}

int countNearbyBombs(MSBoard *board, Coordinates target) {
    int nearbyBombs = 0;

    if (target.y > 0)
    if (board->grid[target.y - 1][target.x] == BOMB)
        nearbyBombs++;

    if (target.y > 0 && target.x < board->length - 1)
    if (board->grid[target.y - 1][target.x + 1] == BOMB)
        nearbyBombs++;

    if (target.x < board->length - 1)
    if (board->grid[target.y][target.x + 1] == BOMB)
        nearbyBombs++;

    if (target.y < board->height - 1 && target.x < board->length - 1)
    if (board->grid[target.y + 1][target.x + 1] == BOMB)
        nearbyBombs++;

    if (target.y < board->height - 1)
    if (board->grid[target.y + 1][target.x] == BOMB)
        nearbyBombs++;

    if (target.y < board->height - 1 && target.x > 0)
    if (board->grid[target.y + 1][target.x - 1] == BOMB)
        nearbyBombs++;

    if (target.x > 0)
    if (board->grid[target.y][target.x - 1] == BOMB)
        nearbyBombs++;

    if (target.y > 0 && target.x > 0)
    if (board->grid[target.y - 1][target.x - 1] == BOMB)
        nearbyBombs++;

    return nearbyBombs;
}

MSBoard *generateHiddenBoard(MSBoard *baseBoard) {

    MSBoard *gameBoard = malloc(sizeof(MSBoard));

    gameBoard->grid = malloc(baseBoard->height * sizeof(char *));
    gameBoard->height = baseBoard->height;
    gameBoard->length = baseBoard->length;


    for (int i = 0; i < baseBoard->height; i++) {
        gameBoard->grid[i] = malloc(baseBoard->length * sizeof(char));
        for (int j = 0; j < baseBoard->length; j++) {
            gameBoard->grid[i][j] = 'X';
        }
    }

    return gameBoard;
}

void printBoard(MSBoard *board) {
    for (int i = 0; i < board->height; i++) {

        for (int j = 0; j < board->length; j++)
            putchar(board->grid[i][j]);

        putchar('\n');
    }
}

void destroyBoard(MSBoard *msBoard) {
    for (int i = 0; i < msBoard->height; i++)
        free(msBoard->grid[i]);
    free(msBoard->grid);
    free(msBoard);
}