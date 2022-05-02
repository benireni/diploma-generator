/*******************************************************************************
 |                        USP-Universidade de São Paulo                        |
 |            ICMC-Instituto de Ciências Matemáticas e de Computação           |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Programa que recebe dois números e eleva o primeiro à potência do segundo
 *******************************************************************************

                       /|
       =  =  =        / |
  ____| || || |______/  | -_-_-_-_-_-_-_-_
|)----| || || |______   |   BOA NOITE LEO
  ((  | || || |  ))  \  | _-_-_-_-_-_-_-_-
   \\_|_||_||_|_//    \ |
    \___________/      \|

*/

#include <stdio.h>
#include <math.h>

int main() {
    int base, exp, result;
    scanf("%i %i", &base, &exp);

    if (exp == 0) {
        printf("1");
        return 0;
    } else if (exp < 0) {
      result = 1/base;
      exp *= -1;
    } else {
      result = base;
    }

    for (int i = 1; i < exp; i++) {
        result *= base;
    }

    printf("%i\n", result);
}
