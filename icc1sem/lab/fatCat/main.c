/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Veterinário de gato
 ******************************************************************************/

#include <stdio.h>

int main() {
        int ballPlays, foodBites;
        scanf("%i %i", &ballPlays, &foodBites);

        int weightLossGain = ballPlays * 5;
        int weightGramsGain = foodBites * 3;

        int deltaWeight = weightGramsGain - weightLossGain; 
        if (deltaWeight <= -30) {
            printf("P\n");
        } else if (deltaWeight <= 0) {
            printf("B\n");
        } else {
            printf("R\n");
        }
}