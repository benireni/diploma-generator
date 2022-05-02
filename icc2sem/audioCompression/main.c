/*******************************************************************************
|                       USP - Universidade de São Paulo                       |
|            ICMC - Instituto de Ciências Matemáticas e de Computação         |
*******************************************************************************
|                    Bacharelado em Ciências de Computação                    |
|                                   2021/2                                    |
|                                                                             |
|                      Autor: Benício Januário (12543843)                     |
*******************************************************************************
 > Audio Compression
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "./includes/waveHandler.h"
#include "./includes/audioSines.h"
#include "./includes/audioCompressor.h"
#include "./includes/streamReader.h"

int main() {
    char *wavFilename = readLine(stdin);
    AudioSines *as = extractAudioDataFromFile(wavFilename);
    free(wavFilename);

    int relevantWavesCoefficient;
    if (scanf(" %d", &relevantWavesCoefficient) <= 0) {
        perror("Unable to read desired coefficient numbers from stdin.");
        exit(EXIT_FAILURE);
    }

    zeroLessSignificantCoefficients(as, relevantWavesCoefficient);

    destroyAudioSines(as);
    return 0;
}
