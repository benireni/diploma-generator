/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Progressão aritmética
 ******************************************************************************/

#include <stdio.h>

int main() {
    int a1, r, n;
    scanf("%i", &a1);
    scanf("%i", &r);
    scanf("%i", &n);

    long int an = a1;
    long int sum = an;
    for (int i = 0; i < n-1; i++) {
        an += r;
        sum += an;
    }

    printf("%li\n", an);
    printf("%li\n", sum);
}