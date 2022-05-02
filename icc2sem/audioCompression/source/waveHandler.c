#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <complex.h>
#include <math.h>

// ------------SAUDACOES E AGRADECIMENTOS AO KU------------
#include "../includes/waveHandler.h"

WavData *readWavData(char *fname) {
    FILE* fp = fopen(fname, "rb");
    unsigned char buf4[4];

    WavData *wavData = malloc(sizeof(WavData));

    fseek(fp, 40, SEEK_SET);
    fread(buf4, sizeof(buf4), 1, fp);
    wavData->samplesQty = buf4[0] | buf4[1]<<8 | buf4[2]<<16 | buf4[3]<<24;
    printf("%d\n", wavData->samplesQty);

    wavData->audioSamples = malloc(sizeof(*wavData->audioSamples) * (wavData->samplesQty));
    
    int i = 0, nonPositiveCoefficientsCounter = 0;
    while (i < wavData->samplesQty)
        fread(&wavData->audioSamples[i++], sizeof(unsigned char), 1, fp);
    fclose(fp);

    return wavData;
}

double complex *DFT(unsigned char *audio, int length) {
    double complex *coef = calloc(length, sizeof(double complex));

    int nonPositiveCoefficientsCounter = 0;

    for (int k = 0; k < length; k++) {
        for (int n = 0; n < length; n++)
            coef[k] += audio[n] * cexp((-2.0 * M_PI * (((k+1) * n * 1.0) / (length * 1.0))) * _Complex_I);
        if (creal(coef[k]) <= 0 && cimag(coef[k]) <= 0) nonPositiveCoefficientsCounter++;
    }

    printf("%d\n", nonPositiveCoefficientsCounter);

    return coef;
}

unsigned char *IDFT(double complex *audioCoefficients, int length) {
    double complex *samples = calloc(length, sizeof(double complex));
    unsigned char *audioSamples = malloc(length * sizeof(unsigned char));

    for (int n = 0; n < length; n++) {
        for (int k = 0; k < length; k++)
            samples[n] += audioCoefficients[k] * cexp((2.0 * M_PI * (((k+1) * n * 1.0) / (length * 1.0))) * _Complex_I);
        samples[n] = samples[n] / length;
        audioSamples[n] = creal(samples[n]);
    }
    return audioSamples;
}