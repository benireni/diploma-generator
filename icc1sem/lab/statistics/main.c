/*******************************************************************************
 |                        USP - Universidade de São Paulo                      |
 |             ICMC - Instituto de Ciências Matemáticas e de Computação        |
 *******************************************************************************
 |                     Bacharelado em Ciências de Computação                   |
 |                                    2021/1                                   |
 |                                                                             |
 |                       Autor: Benício Januário (12543843)                    |
 *******************************************************************************
  > voce era a mais bonita das cabrochas dessa ala
 ******************************************************************************/

#include <stdio.h>
#include <limits.h>

#define OPERANDS_LEN 10

int max(int elements[OPERANDS_LEN]);
int min(int elements[OPERANDS_LEN]);
float mean(int elements[OPERANDS_LEN]);
int mode(int elements[OPERANDS_LEN]);

int main() {
    int operands[OPERANDS_LEN];
    for (int i = 0; i < OPERANDS_LEN; i++) scanf(" %d", &operands[i]);

    int maxOperand = max(operands);
    int minOperand = min(operands);
    float operandsMean = mean(operands);
    int operandsMode = mode(operands);

    printf("%d %d %.2f %d", maxOperand, minOperand, operandsMean, operandsMode);
}

int max(int elements[OPERANDS_LEN]) {
    int max = INT_MIN;
    for (int i = 0; i < OPERANDS_LEN; i++) max = (elements[i] > max) ? elements[i] : max;
    return max;
}

int min(int elements[OPERANDS_LEN]) {
    int min = INT_MAX;
    for (int i = 0; i < OPERANDS_LEN; i++) min = (elements[i] < min) ? elements[i] : min;
    return min;
}

float mean(int elements[OPERANDS_LEN]) {
    float sum = 0.0;
    for (int i = 0; i < OPERANDS_LEN; i++) sum += elements[i];
    return sum / OPERANDS_LEN;
}

int mode(int elements[OPERANDS_LEN]) {
    int modeValue, maxFrequency = 0;
    for (int i = 0; i < OPERANDS_LEN; i++) {

        int currentFreq = 0;
        for (int j = 0; j < OPERANDS_LEN; j++)
            if (elements[i] == elements[j]) currentFreq++;
        
        if (currentFreq > maxFrequency) {
            maxFrequency = currentFreq;
            modeValue = elements[i];
        }
    }

    return modeValue;
}