/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Potência manual
 ******************************************************************************/

#include <stdio.h>

int main() {
    int base, exp;
    scanf("%i %i", &base, &exp);

    if (exp == 0) {
        printf("1");
        return 0;
    }

    int result = base;
    for (int i = 1; i < exp; i++) {
        result *= base;
    }

    printf("%i\n", result);
}