/*******************************************************************************
 |                        USP - Universidade de São Paulo                      |
 |             ICMC - Instituto de Ciências Matemáticas e de Computação        |
 *******************************************************************************
 |                     Bacharelado em Ciências de Computação                   |
 |                                    2021/1                                   |
 |                                                                             |
 |                       Autor: Benício Januário (12543843)                    |
 *******************************************************************************
  > Image Padding
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void printImage(int **image, int imageHeight, int imageLength);

int main() {
    int baseCols;
    scanf(" %d", &baseCols);

    int baseLines;
    scanf(" %d", &baseLines);

    int **sourceImg = malloc(baseLines * sizeof(int *));
    for (int i = 0; i < baseLines; i++) {
        sourceImg[i] = malloc(baseCols * sizeof(int));
        for (int j = 0; j < baseCols; j++)
            scanf("%d", &sourceImg[i][j]);
        fgetc(stdin);
    }

    int padding;
    scanf("%d", &padding);

    int imageLines = baseLines + 2*padding;
    int imageColumns = baseCols + 2*padding;

    int **image = malloc(imageLines * sizeof(int *));
    for (int i = 0; i < imageLines; i++) {
        image[i] = malloc(imageColumns * sizeof(int));
        for (int j = 0; j < imageColumns; j++) {
            if (i > padding - 1 && i < imageLines - padding
            && j > padding - 1 && j < imageColumns - padding)
                image[i][j] = sourceImg[i - padding][j - padding];
            else
                image[i][j] = 0;
        }
    }

    printImage(image, imageLines, imageColumns);
    printf("\n");
    printImage(sourceImg, baseLines, baseCols);

    for (int i = 0; i < baseLines; i++) free(sourceImg[i]);
    free(sourceImg);

    for (int i = 0; i < imageLines; i++) free(image[i]);
    free(image);

    return 0;
}

void printImage(int **image, int imageHeight, int imageLength) {
    for (int i = 0; i < imageHeight; i++)
    for (int j = 0; j < imageLength; j++)
        printf("%d%c", image[i][j], (j < imageLength - 1) ? ' ' : '\n');
}