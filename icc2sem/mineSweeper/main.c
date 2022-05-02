/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                              SCC0201 - ICC II
 |                                   2021/2                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Mine Sweeper
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "./include/board_consumer.h"
#include "./include/ms_board.h"

enum OPTIONS {
    PRINT_BOARD  = '1',
    PRINT_HINTS  = '2',
    USER_CONTROL = '3'
};

int main() {

    char option = fgetc(stdin); fgetc(stdin); // Consume \n

    switch (option) {
        
        case PRINT_BOARD: {

            char *fileName = consumeLine(stdin);
            FILE *msFile = fopen(fileName, "r");
            free(fileName);

            MSBoard *msBoard = consumeBoard(msFile);
            fclose(msFile);

            printBoard(msBoard);
            destroyBoard(msBoard);
            break;
        }
        
        case PRINT_HINTS: {

            char *fileName = consumeLine(stdin);
            FILE *msFile = fopen(fileName, "r");
            free(fileName);

            MSBoard *msBoard = consumeBoard(msFile);
            fclose(msFile);

            hintBoard(msBoard);

            printBoard(msBoard);
            destroyBoard(msBoard);
            break;
        }

        case USER_CONTROL:{

            char *fileName = consumeLine(stdin);
            FILE *msFile = fopen(fileName, "r");
            free(fileName);

            MSBoard *msBoard = consumeBoard(msFile);
            fclose(msFile);

            hintBoard(msBoard);

            Coordinates targetSlot;
            int ok = scanf(" %d %d", &targetSlot.y, &targetSlot.x);
            if (ok <= 0) {
                perror("Unable to get reveal target.");
                exit(EXIT_FAILURE);
            }

            reveal(msBoard, targetSlot);

            destroyBoard(msBoard);
            break;
        }

    }

    return 0;
}