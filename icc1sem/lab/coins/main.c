/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > conta moeda
 ******************************************************************************/

#include <stdio.h>

typedef struct {
    int real, c50, c25, c10, c5, c1;
} Change;

void calculateChangeComposition(int cents, Change *change);

int main() {
    long int cents;
    scanf("%li", &cents);

    Change change;
    calculateChangeComposition(cents, &change);
    
    printf("O valor consiste em %d moedas de 1 real\n", change.real);
    printf("O valor consiste em %d moedas de 50 centavos\n", change.c50);
    printf("O valor consiste em %d moedas de 25 centavos\n", change.c25);
    printf("O valor consiste em %d moedas de 10 centavos\n", change.c10);
    printf("O valor consiste em %d moedas de 5 centavos\n", change.c5);
    printf("O valor consiste em %d moedas de 1 centavo\n", change.c1);

    return 0;
}

void calculateChangeComposition(int cents, Change *change) {
    change->real = cents/100; cents -= change->real*100;
    change->c50 = cents/50; cents -= change->c50*50;
    change->c25 = cents/25; cents -= change->c25*25;
    change->c10 = cents/10; cents -= change->c10*10;
    change->c5 = cents/5; cents -= change->c5*5;
    change->c1 = cents;
}