
/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Calculadora de Multa
 ******************************************************************************/

#include <stdio.h>
#define SPEED_LIMIT 80.00

int main() {
    float speed;
    scanf("%f", &speed);

    if (speed > SPEED_LIMIT) {
        printf("Limite de velocidade excedido! Multado no valor de R$%.2f!\n", 2*(speed - SPEED_LIMIT));
    } else {
        printf("Velocidade dentro do limite permitido.\n");
    }
}