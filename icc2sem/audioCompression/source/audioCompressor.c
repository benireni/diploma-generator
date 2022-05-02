#include <stdio.h>
#include <stdlib.h>

#include "../includes/audioCompressor.h"
#include "../includes/waveHandler.h"

AudioSines *extractAudioDataFromFile(char *wavFilename) {
    WavData *wavData = readWavData(wavFilename);
    double complex *sineWavesCoefficients = DFT(
        wavData->audioSamples, wavData->samplesQty);

    AudioSines *as = createAudioSines(sineWavesCoefficients, wavData->samplesQty);

    free(wavData->audioSamples);
    free(wavData);
    return as;
}