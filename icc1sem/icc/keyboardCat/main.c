/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Decodificador de KeyboardCat
 ******************************************************************************
 
  _._     _,-'""`-._
(,-.`._,'(       |\`-/|
    `-.-' \ )-`( , o o)
          `-    \`_`"'-  -MIAU

 */

#include <stdio.h>

#define KEYBOARD_LEN 49

int main() {

    char keyboardKeys[KEYBOARD_LEN], keyChar;
    for (int i = 0; i < KEYBOARD_LEN; i++) {
        keyChar = getchar(); getchar();
        keyboardKeys[i] = (keyChar == '_') ? ' '
            : (keyChar == 'E') ? '\n' : keyChar;
    }

    int messageSize;
    scanf("%d", &messageSize);

    int charCodes[messageSize];
    for (int i = 0; i < messageSize; i++) {
        scanf(" %d", &charCodes[i]);
        printf("%c", keyboardKeys[charCodes[i]]);
    }  

}
