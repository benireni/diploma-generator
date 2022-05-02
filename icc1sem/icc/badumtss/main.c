/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Fizz Buzzer versão Bio sz
 *******************************************************************************

======o     o======
   ___________
  |___________|  
   |\  /\  /\|
   |_\/__\/__|
  |___________| BA DUM TSS

*/

#include <stdio.h>
#include <string.h>

int main() {
    int decimalCount;
    scanf("%i", &decimalCount);

    char bdtCount[11];
    unsigned short bdtLength = 0;
    if (decimalCount % 11 == 0) strcat(bdtCount, "Ba"); (bdtLength += 2);
    if (decimalCount % 13 == 0) strcat(bdtCount, "Dum"); (bdtLength += 3);
    if (decimalCount % 19 == 0) strcat(bdtCount, "Tss"); (bdtLength += 3);

    if (bdtLength == 0) {
        printf("%i\n", decimalCount);
    } else if (bdtLength <= 3) {
        printf("Ba%s\n", bdtCount);
    } else if (bdtLength <= 6) {
        char repo[20];
        int brokerChar = (bdtLength % 2 == 0) ? 4 : 3;

        strncpy(repo, bdtCount, brokerChar);
        repo[brokerChar] = '\0';

        strcat(repo, "Dum");
        strcat(repo, bdtCount + brokerChar);

        printf("%s\n", repo);
    } else {
        printf("%sTss\n", bdtCount);
    }
}
