#pragma once

// Matrix type definition
typedef struct {
    int **elements;
    int order;
} Matrix;

// Instantiates a matrix
Matrix *readMatrix(FILE *stream, int order);

// Frees up a matrix instance
void destroyMatrix(Matrix *mx);
