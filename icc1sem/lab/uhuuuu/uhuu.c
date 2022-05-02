/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Contador de pinguins
 ******************************************************************************/

#include <stdio.h>

int main() {
    int rounds, totalPlayers, pinguIndex;
    scanf("%i %i %i", &rounds, &totalPlayers, &pinguIndex); // KKKKKJKJJ PINGU INDEX

    int round = 0;
    int counterMultiplier = 1;
    while (round <= rounds) {

      for (int i = 0; i < counterMultiplier; i++) {
        if (++round > rounds) break;
        if ((round - pinguIndex) % totalPlayers == 0) {
          printf("%i %s\n", counterMultiplier, (counterMultiplier > 1) ? "pinguins" : "pinguim");
        }
      }

      for (int i = 0; i < counterMultiplier; i++) {
        if (++round > rounds) break;
        if ((round - pinguIndex) % totalPlayers == 0) {
          printf("no gelo\n");
        }
      }

      for (int i = 0; i < counterMultiplier; i++) {
        if (++round > rounds) break;
        if ((round - pinguIndex) % totalPlayers == 0) {
          printf("uhuu!\n");
        }
      }

      counterMultiplier++;
    }
}
