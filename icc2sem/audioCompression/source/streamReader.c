#include <stdio.h>
#include <stdlib.h>

#include "../includes/streamReader.h"

char *readLine(FILE *stream) {

	int allocatedBytes = INITIAL_SIZE, currentLength = 0;
	char *line = malloc(allocatedBytes); // allocates with initial len

	bool hasFinished = false;
	do {
		// if at any point there is no available alocated memory left, double it
		if (currentLength == allocatedBytes) {
			allocatedBytes *= 2;
			line = realloc(line, allocatedBytes * sizeof(char));
		}

		if (currentLength == STR_MAX_LENGTH) {
			line[currentLength] = '\0';
			break;
		}

		char c = fgetc(stream);
		if (c == '\r') c = fgetc(stream);

		hasFinished = (c == '\n' || (char) c == EOF);

		line[currentLength++] = hasFinished ? '\0' : c;

	} while (!hasFinished);

	if (line[0] == '\0') {
		free(line);
		return NULL;
	}
	line = realloc(line, sizeof(char) * currentLength); // dismiss unused alocated mem and trim \n or EOF

	return line;
}
