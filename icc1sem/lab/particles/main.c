/*******************************************************************************
 |                        USP - Universidade de São Paulo                      |
 |             ICMC - Instituto de Ciências Matemáticas e de Computação        |
 *******************************************************************************
 |                     Bacharelado em Ciências de Computação                   |
 |                                    2021/1                                   |
 |                                                                             |
 |                       Autor: Benício Januário (12543843)                    |
 *******************************************************************************
  > simulação de partículas
 ******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define FRAME_HEIGHT 32
#define FRAME_WIDTH  64

#define CEMENT '@'
#define WATER  '~'
#define SAND   '#'
#define AIR    ' '

void applyPhysics(char (*frame)[FRAME_HEIGHT][FRAME_WIDTH]);

void moveWaterParticle(char refFrame[FRAME_HEIGHT][FRAME_WIDTH],
  char (*frame)[FRAME_HEIGHT][FRAME_WIDTH], int baseX, int baseY);

void moveSandParticle(char refFrame[FRAME_HEIGHT][FRAME_WIDTH],
  char (*frame)[FRAME_HEIGHT][FRAME_WIDTH], int baseX, int baseY);

void printFrame(char frame[FRAME_HEIGHT][FRAME_WIDTH]);

int main() {
    char frameState[FRAME_HEIGHT][FRAME_WIDTH];
    for (int i = 0; i < FRAME_HEIGHT; i++)
        for (int j = 0; j < FRAME_WIDTH; j++)
            frameState[i][j] = ' ';

    int totalFrames, currentFrame, x, y;
    char newParticle;
    scanf("%d", &totalFrames);

    int counter = 0;
    while (counter < totalFrames) {
        int n_lido = scanf(" %d: %d %d %c", &currentFrame, &x, &y, &newParticle);
        if (n_lido == EOF) currentFrame = totalFrames;

        while (counter < currentFrame) {
                printf("frame: %d\n", counter + 1);
                printFrame(frameState);
                applyPhysics(&frameState);
                counter++;
        }

        if (n_lido != EOF) frameState[y][x] = newParticle;
    }

    return 0;
}

void applyPhysics(char (*frame)[FRAME_HEIGHT][FRAME_WIDTH]) {

    char refFrame[FRAME_HEIGHT][FRAME_WIDTH];
    memcpy(refFrame, *frame, FRAME_HEIGHT*FRAME_WIDTH*sizeof(char));

    for (int i = 0; i < FRAME_HEIGHT; i++)
        for (int j = 0; j < FRAME_WIDTH; j++) {
            if (refFrame[i][j] == WATER) moveWaterParticle(refFrame, frame, j, i);
            else if (refFrame[i][j] == SAND) moveSandParticle(refFrame, frame, j, i);
        }
}

void moveWaterParticle(char refFrame[FRAME_HEIGHT][FRAME_WIDTH],
  char (*frame)[FRAME_HEIGHT][FRAME_WIDTH], int baseX, int baseY) {
    
    if (baseY + 1 < FRAME_HEIGHT)
    if (refFrame[baseY + 1][baseX] == AIR) {
        char particleBuffer = (*frame)[baseY][baseX];
        (*frame)[baseY][baseX] = (*frame)[baseY + 1][baseX];
        (*frame)[baseY + 1][baseX] = particleBuffer;
        return;
    }

    if (baseY + 1 < FRAME_HEIGHT && baseX - 1 >= 0)
    if (refFrame[baseY + 1][baseX - 1] == AIR) {
        char particleBuffer = (*frame)[baseY][baseX];
        (*frame)[baseY][baseX] = (*frame)[baseY + 1][baseX - 1];
        (*frame)[baseY + 1][baseX - 1] = particleBuffer;
        return;
    }

    if (baseY + 1 < FRAME_HEIGHT && baseX + 1 < FRAME_WIDTH)
    if (refFrame[baseY + 1][baseX + 1] == AIR) {
        char particleBuffer = (*frame)[baseY][baseX];
        (*frame)[baseY][baseX] = (*frame)[baseY + 1][baseX + 1];
        (*frame)[baseY + 1][baseX + 1] = particleBuffer;
        return;
    }

    if (baseX - 1 >= 0)
    if (refFrame[baseY][baseX - 1] == AIR) {
        char particleBuffer = (*frame)[baseY][baseX];
        (*frame)[baseY][baseX] = (*frame)[baseY][baseX - 1];
        (*frame)[baseY][baseX - 1] = particleBuffer;
        return;
    }

    if (baseX + 1 < FRAME_WIDTH)
    if (refFrame[baseY][baseX + 1] == AIR) {
        char particleBuffer = (*frame)[baseY][baseX];
        (*frame)[baseY][baseX] = (*frame)[baseY][baseX + 1];
        (*frame)[baseY][baseX + 1] = particleBuffer;
        return;
    }
    
}

void moveSandParticle(char refFrame[FRAME_HEIGHT][FRAME_WIDTH],
  char (*frame)[FRAME_HEIGHT][FRAME_WIDTH], int baseX, int baseY) {

    if (baseY + 1 < FRAME_HEIGHT)
    if (refFrame[baseY + 1][baseX] == WATER || refFrame[baseY + 1][baseX] == AIR) {
        char particleBuffer = (*frame)[baseY][baseX];
        (*frame)[baseY][baseX] = (*frame)[baseY + 1][baseX];
        (*frame)[baseY + 1][baseX] = particleBuffer;
        return;
    }

    if (baseY + 1 < FRAME_HEIGHT && baseX - 1 >= 0)
    if (refFrame[baseY + 1][baseX - 1] == WATER || refFrame[baseY + 1][baseX - 1] == AIR) {
        char particleBuffer = (*frame)[baseY][baseX];
        (*frame)[baseY][baseX] = (*frame)[baseY + 1][baseX - 1];
        (*frame)[baseY + 1][baseX - 1] = particleBuffer;
        return;
    }

    if (baseY + 1 < FRAME_HEIGHT && baseX + 1 < FRAME_WIDTH)
    if (refFrame[baseY + 1][baseX + 1] == WATER || refFrame[baseY + 1][baseX + 1] == AIR) {
        char particleBuffer = (*frame)[baseY][baseX];
        (*frame)[baseY][baseX] = (*frame)[baseY + 1][baseX + 1];
        (*frame)[baseY + 1][baseX + 1] = particleBuffer;
        return;
    }

}

void printFrame(char frame[FRAME_HEIGHT][FRAME_WIDTH]) {
    for (int i = 0; i < FRAME_HEIGHT; i++) {
        for (int j = 0; j < FRAME_WIDTH; j++) {
            printf("%c", frame[i][j]);
        }
        printf("\n");
    }
}