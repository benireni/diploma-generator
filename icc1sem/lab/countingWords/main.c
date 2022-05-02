/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > tuts tats
 ******************************************************************************/

#include <stdio.h>
#include <stdbool.h>

#define WORD 1
#define SEPARATOR 0

bool isSeparator(char c);

int main() {
    char currentChar;
    int stringState = WORD;
    unsigned int lines = 0, words = 0, chars = 0;
    while ((currentChar = getchar()) != EOF) {
        chars++;
        if (isSeparator(currentChar)) {
            stringState = SEPARATOR;
            if (currentChar == '\n') lines++;
        } else if (stringState == SEPARATOR) {
            stringState = WORD;
            words++;
        }
    } words++;

    printf("Linhas\tPalav.\tCarac.\n");
    printf("%i\t%i\t%i", lines, words, chars);

    return 0;
}

bool isSeparator(char c) { return c == ' ' || c == '\n' || c == '\t' || c == '\r'; }