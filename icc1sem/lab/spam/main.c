/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > rompi com o mundo, queimei meus navios
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INITIAL_SIZE  69
#define MAX_EMAIL_LEN 76

#define FORBIDDEN_SUBSTRS (char*[]){"gratuit", "atenc", "urgente", "imediat",\
   "zoombie", "oferta", "dinheiro", "renda", "fundo", "limitad", "ajud", "SOS"}

char *readLine();

bool containsMultipleForbiddenWords(char *container);
bool containsForbiddenWord(char *container);

int main() {

    bool emailHasForbiddenWord = false;
    char *emailLine, *emailClassification = "Inbox";
    while (emailLine = readLine(), emailLine != NULL) {
        if (strlen(emailLine) > MAX_EMAIL_LEN || containsMultipleForbiddenWords(emailLine)
            || (containsForbiddenWord(emailLine) && emailHasForbiddenWord)) {
            emailClassification = "Spam";
            break;
        }
        
        if (containsForbiddenWord(emailLine)) emailHasForbiddenWord = true;
        free(emailLine);
    }
    
    printf("%s", emailClassification);
    free(emailLine);
    return 0;
}

bool containsMultipleForbiddenWords(char *container) {
    bool hasSingleForbiddenWord = false;
    for (int i = 0; i < 12; i++)
        if (strstr(container, FORBIDDEN_SUBSTRS[i])) {
            if (hasSingleForbiddenWord) return true;
            else hasSingleForbiddenWord = true;
        }
    return false;
}

bool containsForbiddenWord(char *container) {
    for (int i = 0; i < 12; i++)
        if (strstr(container, FORBIDDEN_SUBSTRS[i])) return true;
    return false;
}

char *readLine() {
    int cur_len = INITIAL_SIZE;
    char *str = malloc(sizeof(char) * cur_len);

    int i = 0;
    do {
        if (i == cur_len) {
            cur_len *= 2;
            str = realloc(str, sizeof(char) * cur_len);
        }

        char c = getchar();
        if (c == '\r') c = getchar();

        str[i] = c;
        i++;
    } while (str[i - 1] != '\n' && str[i - 1] != EOF);

    if (i == 1 && str[i - 1] == EOF) {
        free(str);
        return NULL;
    }

    str[i - 1] = '\0';
    str = realloc(str, sizeof(char) * i);

    return str;
}