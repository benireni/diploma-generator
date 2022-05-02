/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Calculadora de média com descarte
 ******************************************************************************/

#include <stdio.h>
#include <float.h>

int main() {
    double values[4];
    scanf("%lf %lf %lf %lf", &values[0], &values[1], &values[2], &values[3]);

    double minValue = DBL_MAX;
    for (int i = 0; i < 4; i++) {
        if (values[i] < minValue) minValue = values[i];
    }

    printf("%.4lf\n", (values[0] + values[1] + values[2] + values[3] - minValue) / 3);
}
