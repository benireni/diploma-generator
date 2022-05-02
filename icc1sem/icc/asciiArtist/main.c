/*******************************************************************************
 |                        USP - Universidade de São Paulo                      |
 |             ICMC - Instituto de Ciências Matemáticas e de Computação        |
 *******************************************************************************
 |                     Bacharelado em Ciências de Computação                   |
 |                                    2021/1                                   |
 |                                                                             |
 |                       Autor: Benício Januário (12543843)                    |
 *******************************************************************************
  > ASCII Artist
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INITIAL_SIZE 4

typedef struct {
	char **elements;
	int length, height;
} Canvas;

typedef struct {
	char newFill, prevFill;
} Filling;

char *readLine(FILE *stream);
Canvas *readCanvas(FILE *stream);

void printCanvas(Canvas *canvas);
void printPortrait(char *fileName, int canvasHeight, int canvasLength);

void writeCanvasToFile(char *fileName, Canvas *canvas);

void executeFilling(Filling filling, int currI, int currJ, Canvas *canvas);
bool isBaseCase(Filling filling, int currI, int currJ, Canvas *canvas);

int main() {
	char *artFilename = readLine(stdin);

	FILE *artFile = fopen(artFilename, "r");
	Canvas *artCanvas = readCanvas(artFile);
	fclose(artFile);

	printf("Arte inicial:\n");
	printCanvas(artCanvas);

	int fillingsQty;
	scanf(" %d", &fillingsQty);

	Filling currFilling;
	for (int i = 0; i < fillingsQty; i++) {
		int currI, currJ;
		scanf(" %c %d %d", &currFilling.newFill, &currI, &currJ);

		currFilling.prevFill = artCanvas->elements[currI][currJ];

		executeFilling(currFilling, currI, currJ, artCanvas);

		printf("Arte apos a etapa %d:\n", i);
		printCanvas(artCanvas);
	}

	writeCanvasToFile(artFilename, artCanvas);

	printf("Arte enquadrada:\n");
	printPortrait(artFilename, artCanvas->height, artCanvas->length);
	free(artFilename);

	for (int i = 0; i < artCanvas->height; i++)
		free(artCanvas->elements[i]);
	free(artCanvas->elements);
	free(artCanvas);

	return 0;
}

void executeFilling(Filling filling, int currI, int currJ, Canvas *canvas) {
	if (isBaseCase(filling, currI, currJ, canvas)) return;

	canvas->elements[currI][currJ] = filling.newFill;

	// Rigth Fill
	executeFilling(filling, currI + 1, currJ, canvas);

	// Left Fill
	executeFilling(filling, currI - 1, currJ, canvas);

	// Down Fill
	executeFilling(filling, currI, currJ + 1, canvas);

	// Up Fill
	executeFilling(filling, currI, currJ - 1, canvas);
}

bool isBaseCase(Filling filling, int currI, int currJ, Canvas *canvas) {
	if (currI < 0 || currI == canvas->height)
		return true;
	if (currJ < 0 || currJ == canvas->length)
		return true;
	if (canvas->elements[currI][currJ] != filling.prevFill)
		return true;

	return false;
}

Canvas *readCanvas(FILE *stream) {
	int allocatedLines = INITIAL_SIZE;
	Canvas *canvas = malloc(sizeof(Canvas));
	canvas->length = 0, canvas->height = 0;

	canvas->elements = malloc(allocatedLines * sizeof(char *)); // allocates with initial len
	do {
		// if at any point there is no available alocated memory left, double it
		if (canvas->height == allocatedLines) {
			allocatedLines *= 2;
			canvas->elements = realloc(canvas->elements, allocatedLines * sizeof(char *));
		}

		canvas->elements[canvas->height++] = readLine(stream);
	} while (canvas->elements[canvas->height - 1] != NULL);
	canvas->length = strlen(canvas->elements[0]);

	canvas->height--;
	canvas->elements = realloc(canvas->elements, canvas->height *  sizeof(char *)); // dismiss unused alocated mem

	return canvas;
}

char *readLine(FILE *stream) {

	int allocatedBytes = INITIAL_SIZE, currentLength = 0;
	char *line = malloc(allocatedBytes*sizeof(char)); // allocates with initial len

	bool hasFinished = false;
	do {
		// if at any point there is no available alocated memory left, double it
		if (currentLength == allocatedBytes) {
			allocatedBytes *= 2;
			line = realloc(line, allocatedBytes*sizeof(char));
		}

		char c = fgetc(stream);
		hasFinished = (c == '\n' || c == EOF);

		line[currentLength++] = hasFinished ? '\0' : c;
	} while (!hasFinished);

	if (line[0] == '\0') {
		free(line);
		return NULL;
	}
	line = realloc(line, sizeof(char) * currentLength); // dismiss unused alocated mem and trim \n or EOF

	return line;
}

void writeCanvasToFile(char *fileName, Canvas *canvas) {
	FILE *canvasFile = fopen(fileName, "w");
	if (canvasFile == NULL) {
		printf("FODEU CARALHO!");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < canvas->height; i++) {
		for (int j = 0; j < canvas->length; j++)
			fputc(canvas->elements[i][j], canvasFile);
		if (i < canvas->height - 1) fputc('\n', canvasFile);
	}
	fclose(canvasFile);
}

void printCanvas(Canvas *canvas) {
	for (int i = 0; i < canvas->height; i++) {
		for (int j = 0; j < canvas->length; j++)
			printf("%c", canvas->elements[i][j]);
		printf("\n");
	}
	printf("\n");
}

void printPortrait(char *fileName, int canvasHeight, int canvasLength) {
	FILE *canvasFile = fopen(fileName, "r");
	if (canvasFile == NULL) {
		perror(
			"Erro na abertura do arquivo, "
			"Você esqueceu de fechar o arquivo antes? "
			"Ou deu free na string com o nome sem querer?\n"
		);

		exit(EXIT_FAILURE);
	}

	int leftSpaces;
	const char *portrait;
	if (canvasLength % 2 == 0) {
		leftSpaces = canvasLength / 2;
		portrait   = "/\\";
	} else {
		leftSpaces = canvasLength / 2 + 1;
		portrait   = "Ʌ";
	}

	for (int i = 0; i < leftSpaces; i++) printf(" ");
	printf("%s\n", portrait);

	printf("╭");
	for (int i = 0; i < canvasLength; i++) printf("—");
	printf("╮\n");

	for (int i = 0; i < canvasHeight; i++) {
		printf("|");
		for (int j = 0; j < canvasLength; j++) {
			char currentPixel = fgetc(canvasFile);
			printf("%c", currentPixel);
		}
		printf("|");

		char lineBreak = fgetc(canvasFile);
		if (lineBreak != EOF) printf("%c", lineBreak);
	};
	fclose(canvasFile);

	printf("\n╰");
	for (int i = 0; i < canvasLength; i++) printf("—");
	printf("╯\n");
}