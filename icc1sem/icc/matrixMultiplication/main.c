/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Multiplicador de matrizes
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int rowsA, columnsA, rowsB, columnsB;
    scanf("%i %i", &rowsA, &columnsA);
    scanf("%i %i", &rowsB, &columnsB);

    if (rowsA < 0 || columnsA < 0 || rowsB < 0 || columnsB < 0 || columnsA != rowsB) {
          printf("Valores invalidos para a multiplicacao.\n");
          return 0;
    }

    int randSeed;
    scanf("%i", &randSeed);
    srand(randSeed);

    int matrixA[rowsA][columnsA];
    for (int line = 0; line < rowsA; line++) {
        for (int column = 0; column < columnsA; column++) {
            matrixA[line][column] = rand()%50 - 25;
        }
    }

    int matrixB[rowsB][columnsB];
    for (int line = 0; line < rowsB; line++) {
        for (int column = 0; column < columnsB; column++) {
            matrixB[line][column] = rand()%50 - 25;
        }
    }

    for (int line = 0; line < rowsA; line++) {
        printf("Linha %i:", line);
        for (int column = 0; column < columnsB; column++) {
            int productElement = 0;
            for (int i = 0; i < columnsA; i++) {
                productElement += matrixA[line][i] * matrixB[i][column];
            }

            printf((column < columnsB - 1) ? " %i" : " %i\n", productElement);
        }
    }

}
                                                                                                                              