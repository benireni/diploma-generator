/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > to com mt saudade da morena :(
 ******************************************************************************/

#include <stdio.h>

#define HISTOGRAM_LEN      25
#define HISTOGRAM_PIX_CLRS 5

int getMax(int arr[HISTOGRAM_PIX_CLRS]);

int main() {
    int currentColor,  pixelColorsCounts[] = {0, 0, 0, 0, 0}, pixelColors[HISTOGRAM_LEN];
    for (int i = 0; i < HISTOGRAM_LEN; i++) {
        scanf(" %i", &currentColor);
        pixelColors[i] = currentColor;
        pixelColorsCounts[currentColor]++;
    }

    for (int i = 0; i < HISTOGRAM_PIX_CLRS; i++) {
        printf("%i: |", i);
        for (int j = 0; j < pixelColorsCounts[i]; j++) printf("#");
        printf("\n");
    };

    int mostFrequentColor = getMax(pixelColors);
    for (int i = 0; i < HISTOGRAM_LEN; i++)
        if (pixelColors[i] == mostFrequentColor) printf("%i\n", i);

    return 0;
}

int getMax(int arr[HISTOGRAM_PIX_CLRS]) {
    int max = arr[0];
    for (int i = 1; i < HISTOGRAM_PIX_CLRS; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}