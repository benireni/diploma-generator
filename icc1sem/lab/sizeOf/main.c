
/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Programa que imprime o tamanho dos tipos primitivos do C
 ******************************************************************************/

#include <stdio.h>

int main() {
    printf("%ld\n", sizeof(unsigned char));
    printf("%ld\n", sizeof(char));
    printf("%li\n", sizeof(unsigned int));
    printf("%ld\n", sizeof(short int));
    printf("%ld\n", sizeof(int));
    printf("%ld\n", sizeof(long int));
    printf("%li\n", sizeof(unsigned long int));
    printf("%ld\n", sizeof(long long int));
    printf("%ld\n", sizeof(float));
    printf("%ld\n", sizeof(double));
    printf("%ld\n", sizeof(long double));
}