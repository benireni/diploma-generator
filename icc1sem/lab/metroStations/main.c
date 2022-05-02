/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > 
 *******************************************************************************

░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
░░░░░░█████░░████░░████░░░░░░░
░░░░░██░░░░░░█░░█░░█░░░░░░░░░░
░░░░░█░░░░░░░█░░█░░████░░░░░░░
░░░░░██░░░░░░█░░█░░█░░░░░░░░░░
░░░░░░█████░░████░░████░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
coe.jpg

*/

#include <stdio.h>

const char stations[10][30] = {
    "* Morumbi",
    "* Butanta",
    "* Pinheiros",
    "* Faria Lima",
    "* Fradique Coutinho",
    "* Oscar Freire",
    "* Paulista",
    "* Higienopolis-Mackenzie",
    "* Republica",
    "* Luz"
};

int main() {

    int currentStationIndex;
    scanf("%i", &currentStationIndex);

    while (currentStationIndex != 5 && currentStationIndex != 9) { // Travel
        printf("%s\n|\n", stations[currentStationIndex++]);
    } printf("%s\n", stations[currentStationIndex]); // Arrival

}