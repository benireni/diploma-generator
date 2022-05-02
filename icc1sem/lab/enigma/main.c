/*******************************************************************************
 |                        USP - Universidade de São Paulo                      |
 |             ICMC - Instituto de Ciências Matemáticas e de Computação        |
 *******************************************************************************
 |                     Bacharelado em Ciências de Computação                   |
 |                                    2021/1                                   |
 |                                                                             |
 |                       Autor: Benício Januário (12543843)                    |
 *******************************************************************************
  > E n i g m a
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ROTOR_LEN 26

int main() {
    int rotors[3][ROTOR_LEN];

    scanf("%*[^\r\n]s"); // Skip line "Rotores:"
    scanf("%*[\r\n]s");  // Skip line break
    for (int currentRotor = 0; currentRotor < 3; currentRotor++) {
        for (int i = 0; i < ROTOR_LEN; i++) {
            scanf(" %i", &rotors[currentRotor][i]);
        }
    }

    scanf("%*[\r\n]s");  // Skip line break
    scanf("%*[\r\n]s");  // Skip line break

    scanf("%*[^\r\n]s"); // Skip "Mensagem:"
    scanf("%*[\r\n]s");  // Skip line break

    int rotations[2] = {0, 0}, charCode; 
    char encryptedChar, decryptedChar;
    while(scanf("%c", &encryptedChar) != EOF) {
        
        if (encryptedChar >= 'A' && encryptedChar <= 'Z') charCode = encryptedChar - 'A';
        else if (encryptedChar >= 'a' && encryptedChar <= 'z') charCode = encryptedChar - 'a';
        else { printf("%c", encryptedChar); continue; }

        decryptedChar = rotors[2][rotors[1][rotors[0][charCode]]];
        decryptedChar += (encryptedChar <= 'Z') ? 'A' : 'a';
        printf("%c", decryptedChar);

        int firstElement = rotors[0][0];
        for(int j = 0; j < ROTOR_LEN - 1; j++) rotors[0][j] = rotors[0][j+1];
        rotors[0][ROTOR_LEN - 1] = firstElement;
        rotations[0]++;

        if (rotations[0] == 26) {
            int firstElement = rotors[1][0];
            for(int j = 0; j < ROTOR_LEN - 1; j++) rotors[1][j] = rotors[1][j+1];
            rotors[1][ROTOR_LEN - 1] = firstElement;

            rotations[0] = 0;
            rotations[1]++;
        }
        
        if (rotations[1] == 26) {
            int firstElement = rotors[2][0];
            for(int j = 0; j < ROTOR_LEN - 1; j++) rotors[2][j] = rotors[2][j+1];
            rotors[2][ROTOR_LEN - 1] = firstElement;

            rotations[1] = 0;
        }

    }

    return 0;
}