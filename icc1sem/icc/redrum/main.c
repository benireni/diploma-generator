/*******************************************************************************
 |                        USP - Universidade de São Paulo                      |
 |             ICMC - Instituto de Ciências Matemáticas e de Computação        |
 *******************************************************************************
 |                     Bacharelado em Ciências de Computação                   |
 |                                    2021/1                                   |
 |                                                                             |
 |                       Autor: Benício Januário (12543843)                    |
 *******************************************************************************
  > REDRUM
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define INITIAL_SIZE 4

bool isPalindrome(char *sentence);
bool isSimetric(char *sentence);

char *strCopy(char *copiedStr, int start, int end);
char *removeSeparators(char *baseStr);
char *readLine();

int main() {
    char *sentence = readLine();
    char *cleanSentence = removeSeparators(sentence);

    if (isPalindrome(cleanSentence)) {
        if (isPalindrome(sentence)) printf("Palindromo direto\n");
        else printf("Palindromo indireto\n");
    } else printf("Nao eh um palindromo\n");

    free(sentence);
    free(cleanSentence);
    
    return 0;
}

bool isPalindrome(char *sentence) {
    int sentenceLen = strlen(sentence);
    if (sentenceLen <= 1) return true;

    bool substringKind;
    char *newSentence, start = tolower(sentence[0]), end = tolower(sentence[sentenceLen - 1]);
    if (start == end) {
        newSentence = strCopy(sentence, 1, sentenceLen - 1);
        substringKind = isPalindrome(newSentence);
        free(newSentence);
        return substringKind;
    } else return false;
}

char *removeSeparators(char *baseStr) {
    int baseStrLen = strlen(baseStr);
    char *cleanStr = malloc((baseStrLen + 1) * sizeof(char));

    int i = 0, j = 0;
    for (i = 0; i < baseStrLen; i++) {
        if (!isalnum(baseStr[i])) continue;
        else cleanStr[j++] = baseStr[i];
    }

    cleanStr = realloc(cleanStr, (j + 1) * sizeof(char));
    cleanStr[j] = '\0';
    return cleanStr;
}

char *strCopy(char *copiedStr, int start, int end) { // Not inclusive
    int copyLen = end - start + 1;
    char *copy = malloc(copyLen * sizeof(char));

    int i, j = 0;
    for (i = start; i < end; i++, j++) {
        copy[j] = copiedStr[i];
    }

    copy[copyLen - 1] = '\0';
    return copy;
}

char *readLine() {

    int allocatedBytes = INITIAL_SIZE, currentLength = 0;
    char *line = malloc(allocatedBytes*sizeof(char)); // allocates with initial len

    do {

        // if at any point there is no available alocated memory left, double it
        if (currentLength == allocatedBytes) {
            allocatedBytes *= 2;
            line = realloc(line, allocatedBytes*sizeof(char));
        }

        char c = fgetc(stdin);
        if (!isalnum(c) && c != ' ' && c != '/') c = fgetc(stdin);
        line[currentLength++] = c;

    } while (line[currentLength - 1] != '\n' && line[currentLength - 1] != EOF);

    if (currentLength == 1 && line[currentLength - 1] == EOF) {
        free(line);
        return NULL;
    }

    line[currentLength - 1] = '\0';
    line = realloc(line, sizeof(char) * currentLength); // dismiss unused alocated mem

    return line;
}