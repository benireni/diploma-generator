#include <stdio.h>
#include <stdlib.h>

#include "../includes/matrix.h"

Matrix *readMatrix(FILE *stream, int order) {

    Matrix *mx = malloc(sizeof(Matrix));

    mx->elements = malloc(order * sizeof(int *));
    for (int i = 0; i < order; i++) {
        mx->elements[i] = malloc(order * sizeof(int));
        for (int j = 0; j < order; j++) {
            // mx->elements[i][j] = fgetc(stream) - '0'; // char to int cast
            // fgetc(stream);
            scanf("%d", &mx->elements[i][j]);
            fgetc(stream);
        }

        putchar('\n');
    }

    return mx;
}

void destroyMatrix(Matrix *mx) {
    for (int i = 0; i < mx->order; i++)
        free(mx->elements[i]);
    free(mx->elements);
    
    free(mx);
}