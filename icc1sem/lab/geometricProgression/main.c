/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Progressão geométrica
 ******************************************************************************/

#include <stdio.h>

int main() {
    double a1, q, n;
    scanf("%lf", &a1);
    scanf("%lf", &q);
    scanf("%lf", &n);

    double an = a1;
    double sum = an;
    for (int i = 0; i < n-1; i++) {
        an *= q;
        sum += an;
    }

    printf("%.2lf\n", an);
    printf("%.2lf\n", sum);
}