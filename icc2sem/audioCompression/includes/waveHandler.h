#pragma once

#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct wavData {
    unsigned char *audioSamples;
    int samplesQty;
} WavData;

// Reads data from .wav files
WavData *readWavData(char *fname);

// Performs Discrete Fourier Transform (DFT)
double complex *DFT(unsigned char *audio, int length);

// Performs Inverse Discrete Fourier Transform (IDFT)
unsigned char *IDFT(double complex *coefficients, int length);
