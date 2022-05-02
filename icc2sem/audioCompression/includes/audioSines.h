#pragma once

#include <complex.h>

// Samples Structure
typedef struct audioSines AudioSines;

// Create audio sines data by its coefficients and quantity
AudioSines *createAudioSines(double complex *audioSinesCoefficients, int coefsQty);

// Anulates the significantsQty less relevants coefficients by DFT
void zeroLessSignificantCoefficients(AudioSines *s, int significantsQty);

// Retrieves given sine wave coefficient magnitude
double calculateMagnitude(double complex sampleCoef);

// Zeros the given coefficient index
void zeroCoefficient(AudioSines *s, int index);

// Print coefficients
void printCoefficients(AudioSines *s);

// Frees samples up
void destroyAudioSines(AudioSines *s);
