/*******************************************************************************
 |                        USP - Universidade de São Paulo                      |
 |             ICMC - Instituto de Ciências Matemáticas e de Computação        |
 *******************************************************************************
 |                     Bacharelado em Ciências de Computação                   |
 |                                    2021/1                                   |
 |                                                                             |
 |                       Autor: Benício Januário (12543843)                    |
 *******************************************************************************
  > Cleyton, o Punk de 2077
 ******************************************************************************
 amei a historinha
 */

#include <stdio.h>
#define TAPE_LEN 512 // rever logica do cursor

int main() {
    int tape[TAPE_LEN];
    for (int i = 0; i < TAPE_LEN; i++) {
        scanf("%i", &tape[i]);
    }

    int cursorAddress = 0;
    printf("Saida do programa:\n");

    while (tape[cursorAddress] != 0 && cursorAddress < TAPE_LEN - 1) { // HLT (Halt)
        switch (tape[cursorAddress])
        {

        case 1: { // ADD
            int addend1 = tape[ tape[cursorAddress + 1] ];
            int addend2 = tape[ tape[cursorAddress + 2] ];
            int sumDestiny = tape[cursorAddress + 3];

            tape[sumDestiny] = addend1 + addend2;
            cursorAddress += 4;
            break;
        }
        
        case 2: { // MUL (Multiply)
            int factor1 = tape[ tape[cursorAddress + 1] ];
            int factor2 = tape[ tape[cursorAddress + 2] ];
            int multiplicationDestiny = tape[cursorAddress + 3];

            tape[multiplicationDestiny] = factor1 * factor2;
            cursorAddress += 4;
            break;
        }

        case 3: { // CLT (Compare Less Than)
            int compared1 = tape[ tape[cursorAddress + 1] ];
            int compared2 = tape[ tape[cursorAddress + 2] ];
            int comparisonDestiny = tape[cursorAddress + 3];

            tape[comparisonDestiny] = (compared1 < compared2) ? 1 : 0;
            cursorAddress += 4;
            break;
        }

        case 4: { // CEQ (Compare Equals)
            int compared1 = tape[ tape[cursorAddress + 1] ];
            int compared2 = tape[ tape[cursorAddress + 2] ];
            int comparisonDestiny = tape[cursorAddress + 3];

            tape[comparisonDestiny] = (compared1 == compared2) ? 1 : 0;
            cursorAddress += 4;
            break;
        }

        case 5: { // JMP (Jump)
            int jumpAddress = tape[cursorAddress + 1];
            cursorAddress = tape[jumpAddress];
            break;
        }

        case 6: { // JEQ (Jump if Equal)
            int conditional = tape[ tape[cursorAddress + 1] ];
            int jumpAddress = tape[cursorAddress + 2];

            cursorAddress = (conditional != 0)
                ? tape[jumpAddress]
                : cursorAddress + 3;
            break;
        }

        case 7: { // CPY (Copy)
            int copiedContent = tape[ tape[cursorAddress + 1] ];
            int copyAddress = tape[cursorAddress + 2];

            tape[copyAddress] = copiedContent;
            cursorAddress += 3;
            break;
        }

        case 8: { // PUT
            char asciiOutput = tape[ tape[cursorAddress + 1] ];

            printf("%c", asciiOutput);
            cursorAddress += 2;
            break;
        }

        case 9: { // PTN (Put Number)
            int numberOutput = tape[ tape[cursorAddress + 1] ];
            
            printf("%i", numberOutput);
            cursorAddress += 2;
            break;
        }
        }
    }

    printf("\nEstado final da fita:");
    for (int i = 0; i < TAPE_LEN; i++) printf("\n%i", tape[i]);
    return 0;
}