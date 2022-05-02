/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Programa que lê um inteiro, extrai seus quatro bytes adjacentes e imprime os
    caracteres ASCII correspontentes aos valores decimais dos binários extraídos
 *******************************************************************************

       /\                                                        /\
      |  |                    BOA NOITE LEO                     |  |
     /----\           BEM VINDO AO CÓDIGO DO BITWISE           /----\
    [______]                                                  [______]
     |    |         _____                        _____         |    |
     |[]  |        [     ]                      [     ]        |  []|
     |    |       [_______][ ][ ][ ][][ ][ ][ ][_______]       |    |
     |    [ ][ ][ ]|     |  ,----------------,  |     |[ ][ ][ ]    |
     |             |     |/'    ____..____    '\|     |             |
      \  []        |     |    /'    ||    '\    |     |        []  /
       |      []   |     |   |o     ||     o|   |     |  []       |
       |           |  _  |   |     _||_     |   |  _  |           |
       |   []      | (_) |   |    (_||_)    |   | (_) |       []  |
       |           |     |   |     (||)     |   |     |           |
       |           |     |   |      ||      |   |     |           |
     /''           |     |   |o     ||     o|   |     |           ''\
    [_____________[_______]--'------''------'--[_______]_____________]

*/

#include <stdio.h>

int main() {
    int formatedBytes;
    scanf("%d", &formatedBytes);

    int bitwiseExtractor = 4278190080; // -> 11111111 0...0 0...0 00000000
    for (int i = 0; i < 4; i++) {
        int charBinary = (bitwiseExtractor&formatedBytes)>>8*(3-i);
        bitwiseExtractor = bitwiseExtractor>>8;

        printf("%c", charBinary);
    }
}
