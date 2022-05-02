/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Calculadora de caixinha
 *******************************************************************************

     ░░░░░░░░░░░░░░░░░░░░░░█████████
     ░░███████░░░░░░░░░░███▒▒▒▒▒▒▒▒███
     ░░█▒▒▒▒▒▒█░░░░░░░███▒▒▒▒▒▒▒▒▒▒▒▒▒███
     ░░░█▒▒▒▒▒▒█░░░░██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██
     ░░░░█▒▒▒▒▒█░░░██▒▒▒▒▒██▒▒▒▒▒▒██▒▒▒▒▒███
     ░░░░░█▒▒▒█░░░█▒▒▒▒▒▒████▒▒▒▒████▒▒▒▒▒▒██
     ░░░█████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██
     ░░░█▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒██
     ░██▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒██▒▒▒▒▒▒▒▒▒▒██▒▒▒▒██
     ██▒▒▒███████████▒▒▒▒▒██▒▒▒▒▒▒▒▒██▒▒▒▒▒██
     █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒████████▒▒▒▒▒▒▒██
     ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██
     ░█▒▒▒███████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██
     ░██▒▒▒▒▒▒▒▒▒▒████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█
     ░░████████████░░░█████████████████

O COMPILADOR DO RUNCODES TA ACABANO CA MINHA VIDA

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long x;
    long y;

    long width;
    long height;
} Box;

typedef struct {
    long start;
    long extension;
} LinearColision;

LinearColision *calculateLinearColision(long primaryStart, long primaryLen, long secondaryStart, long secondaryLen) {

    LinearColision *colision = malloc(sizeof(LinearColision));

    colision->start = secondaryStart;
    if (primaryStart == secondaryStart) {
        colision->extension = (primaryLen < secondaryLen) ? primaryLen : secondaryLen;
        return colision;
    }

    colision->extension = primaryStart + primaryLen - secondaryStart;

    if (colision->extension < 0) {
        free(colision);
        return NULL;
    }

    colision->extension = (secondaryLen < colision->extension) ? secondaryLen : colision->extension;
    return colision;
}

int main() {
    Box boxA, boxB;
    scanf("%li %li %li %li", &boxA.x, &boxA.y, &boxA.width, &boxA.height);
    scanf("%li %li %li %li", &boxB.x, &boxB.y, &boxB.width, &boxB.height);

    LinearColision *xColision = (boxA.x < boxB.x)
        ? calculateLinearColision(boxA.x, boxA.width, boxB.x, boxB.width)
        : calculateLinearColision(boxB.x, boxB.width, boxA.x, boxA.width);

    LinearColision *yColision = (boxA.y < boxB.y)
        ? calculateLinearColision(boxA.y, boxA.height, boxB.y, boxB.height)
        : calculateLinearColision(boxB.y, boxB.height, boxA.y, boxA.height);

    if (xColision == NULL || yColision == NULL) printf("MISS\n");
    else {
        printf("HIT: %li %li %li %li\n", xColision->start, yColision->start, xColision->extension, yColision->extension);
        free(xColision); free(yColision);
    }
}