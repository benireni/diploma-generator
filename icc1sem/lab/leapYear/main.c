/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Programa que determina se um dado ano é bissexto ou não
 ******************************************************************************/

#include <stdio.h>

int main() {
    int year;
    scanf("%d", &year);
    printf("%s", (year % 4 == 0) ? "SIM\n" : "NAO\n");
}