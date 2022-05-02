/*******************************************************************************
 |                        USP - Universidade de São Paulo                      |
 |             ICMC - Instituto de Ciências Matemáticas e de Computação        |
 *******************************************************************************
 |                     Bacharelado em Ciências de Computação                   |
 |                                    2021/1                                   |
 |                                                                             |
 |                       Autor: Benício Januário (12543843)                    |
 *******************************************************************************
  > Estado do Jogo da Velha
 *******************************************************************************
 a prova de calculo é depois de amanha to programando pra ameniza meu desespero 
*/

#include <stdio.h>
#include <stdbool.h>

bool containsBool(bool container[3], bool contained) {
    for (int i = 0; i < 3; i++) {
		if (container[i] == contained) return true;
	}
  
    return false;
}

bool winsInLine(char gameboard[3][3], int linIdx, char symbol) {
    for (int j = 0; j < 3; j++) {
		if (gameboard[linIdx][j] != symbol) return false;
	}
  
    return true;
}

bool winsInColumn(char gameboard[3][3], int colIdx, char symbol) {
    for (int i = 0; i < 3; i++) {
		if (gameboard[i][colIdx] != symbol) return false;
	}
  
    return true;
}

bool winsInDiagonals(char gameboard[3][3], char symbol) {
	bool isMainDiag = (
		gameboard[0][0] == symbol && gameboard[1][1] == symbol && gameboard[2][2] == symbol
	);

	bool isSecdDiag = (
		gameboard[0][2] == symbol && gameboard[1][1] == symbol && gameboard[2][0] == symbol
	);

    return (isMainDiag || isSecdDiag);
}

int main() {
	char gameboard[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf(" %c", &gameboard[i][j]);
		}
	}

	bool hasFinish = true;

	bool xColumnWins[] = {true, true, true};
	for (int i = 0; i < 3; i++) {
		if (winsInLine(gameboard, i, 'x')) {
			printf("x ganhou\n");
			return 0;
		}

		for (int j = 0; j < 3; j++) {
			if (gameboard[i][j] != 'x') xColumnWins[j] = false;
			if (gameboard[i][j] == '-') hasFinish      = false;
		}
	}

	if (containsBool(xColumnWins, true) || winsInDiagonals(gameboard, 'x')) {
		printf("x ganhou\n");
		return 0;
	}

	bool oColumnWins[] = {true, true, true};
	for (int i = 0; i < 3; i++) {
		if (winsInLine(gameboard, i, 'o')) {
			printf("o ganhou\n");
			return 0;
		}

		for (int j = 0; j < 3; j++) {
			if (gameboard[i][j] != 'o') oColumnWins[j] = false;
		}
	}

	if (containsBool(oColumnWins, true) || winsInDiagonals(gameboard, 'o')) {
		printf("o ganhou\n");
		return 0;
	}

	printf(hasFinish ? "empate\n" : "em jogo\n");
	
	return 0;
}
