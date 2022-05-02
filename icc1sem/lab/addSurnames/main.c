/*******************************************************************************
 |                        USP - Universidade de São Paulo                      |
 |             ICMC - Instituto de Ciências Matemáticas e de Computação        |
 *******************************************************************************
 |                     Bacharelado em Ciências de Computação                   |
 |                                    2021/1                                   |
 |                                                                             |
 |                       Autor: Benício Januário (12543843)                    |
 *******************************************************************************
  > Adicionando Sobrenomes
 ******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_SIZE 10

char *readLine(char *del);
char *getLastName(char *name);
char *joinStrs(char *first, char sep, char *second);

int main() {
	int namesLen = 0, alocatedNames = INITIAL_SIZE;
	char *currentName;
	char **names = malloc(alocatedNames * sizeof(char *));
	while ((currentName = readLine("$")) != NULL) {
		names[namesLen] = currentName;
		if (++namesLen == alocatedNames) {
			alocatedNames *= 2;
			names = realloc(names, alocatedNames);
		}
	}

	names = realloc(names, namesLen * sizeof(char *));

	char *currentLastName;
	for (int i = 0; i < namesLen - 1; i += 2) {
		currentLastName = getLastName(names[i]);
		char *newName = joinStrs(names[i + 1], ' ', currentLastName);

		free(names[i + 1]);
		names[i + 1] = newName;

		free(currentLastName);
	}

	for (int i = 0; i < namesLen; i++) {
		printf("%s\n", names[i]);
		free(names[i]);
	}

	free(names);

	return 0;
}


char *getLastName(char *name) {
	int lastNameSize = 0, lastNameIndex = strlen(name);
	while (lastNameIndex > 0 && name[lastNameIndex] != ' ') {
		lastNameSize++;
		lastNameIndex--;
	}

	char *lastName = malloc(lastNameSize * sizeof(char));
	for (int i = 0; i < lastNameSize; i++) {
		lastName[i] = name[++lastNameIndex];
	}

	return lastName;
}


char *joinStrs(char *first, char sep, char *second) {
	int fLen = strlen(first);
	int sLen = strlen(second);

	int joinSize = fLen + 1 + sLen + 1;
	char *joined = malloc(joinSize * sizeof(char));

	for (int i = 0, j = 0; i < joinSize; i++) {
		if (i < fLen) {
			joined[i] = first[j];
			j++;
		}
		else if (i == fLen) {
			joined[i] = sep;
			j = 0;
		}
		else {
			joined[i] = second[j];
			j++;
		}
	}

	return joined;
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