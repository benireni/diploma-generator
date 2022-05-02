/*******************************************************************************
 |                        USP - Universidade de São Paulo                      |
 |             ICMC - Instituto de Ciências Matemáticas e de Computação        |
 *******************************************************************************
 |                     Bacharelado em Ciências de Computação                   |
 |                                    2021/1                                   |
 |                                                                             |
 |                       Autor: Benício Januário (12543843)                    |
 *******************************************************************************
  > Livro Corrompido
 *******************************************************************************

    ______________________________   ______________________________
.-/|                              \ /                              |\-.
||||                               |                               ||||
||||                               |                               ||||
||||  Duvida da luz dos astros     |                               ||||
||||                               |   Duvida até da verdade,      ||||
||||    De que o sol tenha calor,  |                               ||||
||||                               |      Mas confia em meu amor.  ||||
||||                               |                               ||||
||||                               |                               ||||
||||                               |                               ||||
||||______________________________ | ______________________________||||
||/===============================\|/===============================\||
`--------------------------------~___~------------------------------''

*/

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 19

char *readLine();

int main() {
    int linesLen, validLinesLen;
    scanf("%i ", &linesLen);

    char *lines[linesLen];
    for (int i = 0; i < linesLen; i++) {
        lines[i] = readLine();
    }

    scanf("%i", &validLinesLen);
    int validLineIndex;
    for (int i = 0; i < validLinesLen; i++) {
        scanf(" %i", &validLineIndex);
        printf("%s\n", lines[validLineIndex]);
    }

    for (int i = 0; i < linesLen; i++) free(lines[i]);
}

char *readLine() {

    int allocatedBytes = INITIAL_STR_SIZE, currentLength = 0;
    char *line = malloc(allocatedBytes*sizeof(char)); // allocates with initial len

    do {

        // if at any point there is no available alocated memory left, double it
        if (currentLength == allocatedBytes) {
            allocatedBytes *= 2;
            line = realloc(line, allocatedBytes*sizeof(char));
        }

        char c = getchar();
        line[currentLength] = c;

        currentLength++;

    } while (line[currentLength - 1] != '\n' && line[currentLength - 1] != EOF);

    if (currentLength == 1 && line[currentLength - 1] == EOF) {
        free(line);
        return NULL;
    }

    line[currentLength - 1] = '\0';
    line = realloc(line, sizeof(char) * currentLength); // dismiss unused alocated mem

    return line;
}