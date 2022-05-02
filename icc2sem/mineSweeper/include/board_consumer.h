#ifndef _BOARD_CONSUMER_H_
#define _BOARD_CONSUMER_H_

#include <stdio.h>

#include "./ms_board.h"

// Defines the board's initial allocation size
#define INITIAL_SIZE 6

/* Consumes a board, allocating it in the proper
 struct and returning its pointer */
MSBoard *consumeBoard(FILE *stream);

// Consumes a single input line and retrives its pointer
char *consumeLine(FILE *stream);

#endif