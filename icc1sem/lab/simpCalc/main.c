/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Calculadora simples
 ******************************************************************************/

#include <stdio.h>

int main() {
    double a, b;
    char op;

    scanf("%lf %c %lf", &a, &op, &b);

    switch (op) {
    case '+':
        printf("%.5lf\n", a+b);
        break;
    case '-':
        printf("%.5lf\n", a-b);
        break;
    case '*':
        printf("%.5lf\n", a*b);
        break;
    case '/':
        printf("%.5lf\n", a/b);
        break;
    case '%':
        printf("%.5lf\n", a*100/b);
        break;
    }
}