/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
|            ICMC - Instituto de Ciências Matemáticas e de Computação         |
*******************************************************************************
|                    Bacharelado em Ciências de Computação                    |
|                                   2021/1                                    |
|                                                                             |
|                      Autor: Benício Januário (12543843)                     |
*******************************************************************************
> A Esteira de Plínio
*******************************************************************************

─────────────███████████████────────────
──────────████▒▒▒▒▒▒▒▒▒▒▒▒▒████─────────
────────███▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒███───────
───────██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒███─────
──────██▒▒▒▒▒▒▒▒▒▒██▒▒▒▒███████▒▒▒██────
─────██▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒██▒▒▒██───
────██▒▒██▒▒▒▒███▒▒▒▒▒▒▒▒▒▒▒▒▒▒███▒▒██──
───██▒▒▒▒▒████▒▒▒▒██▒▒▒██▒▒▒▒▒▒▒▒██▒▒█──
───█▒▒▒▒▒▒▒▒▒▒▒███░█▒▒▒█░███▒▒▒▒▒▒▒▒▒█──
───█▒▒▒▒▒██████░░░░█▒▒▒█░░░░██████▒▒▒█──
───█▒▒▒▒▒▒▒█░░░░▓▓██▒▒▒██▓▓░░░░█▒▒▒▒▒█──
───█▒▒▒▒▒▒▒▒██████▒▒▒▒▒▒▒██████▒█▒▒▒▒█──
───█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒█──
───█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█░█▒▒▒█──
───██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█░█▒▒██──
────██▒▒▒▒▒▒▒▒▒▒▒████████▒▒▒▒▒▒██▒▒██───
─────██▒▒▒▒▒▒█████▒▒▒▒▒▒█████▒▒▒▒▒██────
──────██▒▒▒███▒▒▒▒▒████▒▒▒▒▒███▒▒██─────
───────███▒▒▒▒▒▒▒▒█▒▒▒▒█▒▒▒▒▒▒▒▒██──────
─────────███▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒███───────
───────────█████▒▒▒▒▒▒▒▒▒██████─────────
───────────────████████████─────────────
PQ TODA VEZ QUE EU ABRO O RUN CODES TEM 20 EX NOVOS

*/

#include <stdio.h>

#define BELTMAP_AMT_ROWS    32
#define BELTMAP_AMT_COLUMNS 32

int main() {
	int currBeltmapRow, currBeltmapCol;
	char beltMap[BELTMAP_AMT_ROWS][BELTMAP_AMT_COLUMNS];
	for (int i = 0; i < BELTMAP_AMT_ROWS; i++) {
		for (int j = 0; j < BELTMAP_AMT_COLUMNS; j++) {
			beltMap[i][j] = getchar();
			getchar();

			if (beltMap[i][j] == '[') {
				currBeltmapRow = i;
				currBeltmapCol = j + 1;
			}
		}
		getchar();
	}

	char prevCell;
	char currCell = beltMap[currBeltmapRow][currBeltmapCol];
	while (currCell != ']' && currCell != ' ' && currCell != '.') {
		if (currCell == '#') currCell = prevCell;
		else beltMap[currBeltmapRow][currBeltmapCol] = '.';
	
		if (currCell == '>')      currBeltmapCol++;
		else if (currCell == '<') currBeltmapCol--;
		else if (currCell == 'v') currBeltmapRow++;
		else if (currCell == '^') currBeltmapRow--;
	
		prevCell = currCell;
		currCell = beltMap[currBeltmapRow][currBeltmapCol];
	}

	if (currCell == ' ') printf("Falha na esteira.\n");
	else if (currCell == '.') printf("Loop infinito.\n");
	else printf("Ok.\n");

	for (int i = 0; i < BELTMAP_AMT_ROWS; i++) {
		for (int j = 0; j < BELTMAP_AMT_COLUMNS - 1; j++) {
			printf("%c ", beltMap[i][j]);
		}
		printf("%c\n", beltMap[i][BELTMAP_AMT_COLUMNS - 1]);
	}

	return 0;
}