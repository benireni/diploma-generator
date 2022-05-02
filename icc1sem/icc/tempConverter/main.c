
/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Conversor de temperatura [°F -> °C]
 *******************************************************************************

======o     o======
   ___________
  |___________|  
   |\  /\  /\|
   |_\/__\/__|
  |___________| PARARA PA PA BOA NOITE FERNANDO

*/

#include <stdio.h>

int main() {
    double fahrenheitDegrees;
    scanf("%lf", &fahrenheitDegrees);

    double celsiusDegrees = (fahrenheitDegrees - 32) * 5 / 9;
    printf("%.2lf\n", celsiusDegrees);

    return 0;
}