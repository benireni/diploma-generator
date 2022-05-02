/*******************************************************************************
|                       USP - Universidade de São Paulo                       |
|            ICMC - Instituto de Ciências Matemáticas e de Computação         |
*******************************************************************************
|                    Bacharelado em Ciências de Computação                    |
|                                   2021/2                                    |
|                                                                             |
|                      Autor: Benício Januário (12543843)                     |
*******************************************************************************
 > Trabalho 7
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

unsigned int potenciaModular(unsigned int base, unsigned int exp, unsigned int mod) {
    unsigned int pot = base % mod, res = 1;

    // Iteração de potenciação
    for (;exp > 0; exp /= 2) {

        // Caso o bit menos significativo seja 1:
        if (exp % 2 == 1) res = (res * pot) % mod;

        pot = (pot * pot) % mod;
    } /* A cada iteração da potência, garante-se que o resultado é < mod - 1
        ao realixar % mod no valor atribuído ao resultado (res) */

    return res;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Os parâmetros passados não são suficientes.");
        exit(EXIT_FAILURE);
    }

    unsigned int base = atoi(argv[1]), expoente = atoi(argv[2]), mod = atoi(argv[3]);
    printf(
        "\n\n  %u∧%u (mod %u) =%u  ",
        base, expoente, mod,
        potenciaModular(base, expoente, mod)
    );

    return 0;
}