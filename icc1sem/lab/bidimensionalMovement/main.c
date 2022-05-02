/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Movimentação bidimensional de dado ponto
 ******************************************************************************/

#include <stdio.h>

int main() {
    int x, y = 0;
    char movement[6];
    scanf("%s", movement);

    for (int i = 0; i < 6; i++) {
        if (movement[i] == 'W') y++;
        else if (movement[i] == 'A') x--;
        else if (movement[i] == 'S') y--;
        else if (movement[i] == 'D') x++;
    }

    printf("%i %i\n", x, y);
}