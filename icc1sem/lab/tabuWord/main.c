/*******************************************************************************
 |                        USP - Universidade de São Paulo                      |
 |             ICMC - Instituto de Ciências Matemáticas e de Computação        |
 *******************************************************************************
 |                     Bacharelado em Ciências de Computação                   |
 |                                    2021/1                                   |
 |                                                                             |
 |                       Autor: Benício Januário (12543843)                    |
 *******************************************************************************
  > Remove Tabu Word
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define INITIAL_SIZE 4

char *readLine(char *del);
char *toLowerCase(char *str);
char *removeSubstring(char *str, const char *sub);
int countOcurrences(char *substr, char *str);

int main() {

    char *tabuWord = readLine(NULL);
    char *sentence = readLine("$");

    int infractions = countOcurrences(tabuWord, sentence);
    sentence = removeSubstring(sentence, tabuWord);

    printf("A palavra tabu foi encontrada %d vezes\n", infractions);
    printf("Frase: %s\n", sentence);

    free(sentence);
    free(tabuWord);
    
    return 0;
}

int countOcurrences(char *substr, char *str) {
    int ocurrences = 0;
    const char *strTmp = str;

    while((strTmp = strstr(strTmp, substr)))
        ocurrences++, strTmp++;
    return ocurrences;
}

char *toLowerCase(char *str) {
    char *lowerStr = malloc(strlen(str) * sizeof(char));
    for (int i = 0; i < strlen(str); i++) lowerStr[i] = tolower(str[i]);

    return lowerStr;
}

char *removeSubstring(char *str, const char *sub) {
    int len = strlen(sub);
    if (len > 0) {
        char *c = str;
        while ((c = strstr(c, sub)) != NULL) {
            memmove(c, c + len, strlen(c + len) + 1);
        }
    }
    return str;
}

char *readLine(char *del) {
	int allocatedBytes = INITIAL_SIZE * sizeof(char), currentLength = 0;
	char *line = malloc(allocatedBytes); // allocates with initial len

	bool finishedReading = false;
	do {
		// if at any point there is no available alocated memory left, double it
		if (currentLength == allocatedBytes) {
			allocatedBytes *= 2;
			line = realloc(line, allocatedBytes);
		}

		char c = getchar();
		if (c == '\r') c = getchar();
		if (c == '\n' || c == EOF || (del && c == *del)) finishedReading = true;

		line[currentLength] = c;

		currentLength++;
	} while (!finishedReading);

	line[currentLength - 1] = '\0';
	if (line[0] == '\0') {
		free(line);
		return NULL;
	}

	line = realloc(line, sizeof(char) * currentLength); // dismiss unused alocated mem
	return line;
}