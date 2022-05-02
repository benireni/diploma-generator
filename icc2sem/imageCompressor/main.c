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
  > Image Compressor
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// Matrix instantiation and destroying
int **readMatrix(int order);
void destroyMatrix(int **matrix, int order);

// Image compression features
void printCompressedImage(int iniLin, int iniCol, int fimLin, int fimCol, int **image);
int shouldCompress(int iniLin, int iniCol, int fimLin, int fimCol, int **image);

int main() {

    int order;
    scanf("%d %d", &order, &order);

    int **image = readMatrix(order);

    printCompressedImage(0, 0, order - 1, order - 1, image);

    destroyMatrix(image, order);

    return 0;
}

int shouldCompress(
    int initialLine,
    int initialCol,
    int lineLimit,
    int colLimit,
    int **image
) {
    for(int i = initialLine; i <= lineLimit; i++)
    for(int j = initialCol; j <= colLimit; j++)
        if(image[initialLine][initialCol] != image[i][j]) return 0;
    return 1;
}

void printCompressedImage(
    int initialLine,
    int initialColumn,
    int lineLimit,
    int colLimit,
    int **image
) {
    if(shouldCompress(initialLine, initialColumn, lineLimit, colLimit, image)){
        printf("%d ", image[initialLine][initialColumn]);
        return;
    }

    printf("%d ", -1);

    int yCenter = (initialLine + lineLimit) / 2;
    int xCenter = (initialColumn + colLimit) / 2;

    // Top Right
    printCompressedImage(initialLine, initialColumn, yCenter, xCenter, image);

    // Top Left
    printCompressedImage(initialLine, xCenter + 1, yCenter, colLimit, image);

    // Bottom Left
    printCompressedImage(yCenter + 1, initialColumn, lineLimit, xCenter, image);

    // Bottom Right
    printCompressedImage(yCenter + 1, xCenter + 1, lineLimit, colLimit, image);
}

int **readMatrix(int order) {

    int **matrix = malloc(order * sizeof(int *));
    for (int i = 0; i < order; i++) {
        matrix[i] = malloc(order * sizeof(int));
        for (int j = 0; j < order; j++) {
                scanf("%d", &matrix[i][j]);
                fgetc(stdin);
        }
    }

    return matrix;
}

void destroyMatrix(int **matrix, int order) {
    for (int i = 0; i < order; i++) free(matrix[i]);
    free(matrix);
}
