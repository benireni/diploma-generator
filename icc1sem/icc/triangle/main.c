/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Programa que faz um triângulo com a altura e caracter definidos pelo usuário
 *******************************************************************************



*/

#include <stdio.h>
#include <string.h>

int main() {
    int triangleHeight;
    scanf("%d\n", &triangleHeight);
    if (triangleHeight > 25 || triangleHeight <= 0) {
        printf("Altura invalida\n");
        return 0;
    }

    char triangleBrick;
    scanf("%c", &triangleBrick);

    int charsInRow;
    for (int currentLevel = 1; currentLevel <= triangleHeight; ++currentLevel) {
        charsInRow = 0;

        for (int i = 1; i <= triangleHeight - currentLevel; ++i) printf(" ");      // Positioning
        while (charsInRow++ != 2 * currentLevel - 1) printf("%c", triangleBrick);  // Printing

        printf("\n");
    }
}