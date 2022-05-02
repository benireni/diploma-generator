
/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Operações bitwise com operandos fornecidos pelo usuário
 ******************************************************************************/

#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d\n", a & b);
    printf("%d\n", a | b);
    printf("%d\n", a ^ b);
    printf("%d\n", ~a);
    printf("%d\n", ~b);
    printf("%d\n", a >> 2);
    printf("%d\n", b << 2);
}