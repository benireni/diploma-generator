#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#include "../includes/audioCompressor.h"
#include "../includes/waveHandler.h"

struct audioSines {
    double complex *coefficients;
    double *magnitudes;
    int length;
};

AudioSines *createAudioSines(double complex *audioSinesCoefficients, int coefsQty) {
    AudioSines *s = malloc(sizeof(AudioSines));
    s->coefficients = audioSinesCoefficients;
    s->magnitudes = malloc(coefsQty * sizeof(double));
    for (int i = 0; i < coefsQty; i++)
        s->magnitudes[i] = cabs(s->coefficients[i]);
    s->length = coefsQty;

    return s;
}

void zeroLessSignificantCoefficients(AudioSines *s, int significantsQty) {
    if (significantsQty < 0) return;

    int *sortedIndexes = malloc(s->length * sizeof(int));
    for (int i = 0; i < s->length; i++) sortedIndexes[i] = i;

    // Insertion sort based on magnitudesCopy, but modifying sortedIndexes as well
    for (int cursor = 1; cursor < s->length; cursor++) {
        int magnitudeKey = s->magnitudes[cursor];
        int indexesKey = sortedIndexes[cursor];

        int j = cursor - 1;
        while (magnitudeKey > s->magnitudes[j] && j >= 0) {
            s->magnitudes[j + 1] = s->magnitudes[j];
            sortedIndexes[j + 1] = sortedIndexes[j];
            j--;
        }
        s->magnitudes[j + 1] = magnitudeKey;
        sortedIndexes[j + 1] = indexesKey;
    }

    unsigned short isFirstPrint = 1;
    for (int i = 0; i < s->length; i++) {
        if (i < significantsQty) {
            if (isFirstPrint) isFirstPrint = 0;
            else putchar('\n');

            printf("%d", (int) s->magnitudes[i]);
        }
        else zeroCoefficient(s, sortedIndexes[i]);
    }

    free(sortedIndexes);
}

void zeroCoefficient(AudioSines *s, int index) {
    s->coefficients[index] = CMPLX(0, 0);
}

void printCoefficients(AudioSines *s) {
    for (int i = 0; i < s->length; i++)
    printf("%.2f + i%.2f\n", creal(s->coefficients[i]), cimag(s->coefficients[i]));
}

void destroyAudioSines(AudioSines *s) {
    free(s->coefficients);
    free(s->magnitudes);
    free(s);
}
