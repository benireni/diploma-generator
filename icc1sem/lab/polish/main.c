/*******************************************************************************
 |                        USP - Universidade de São Paulo                      |
 |             ICMC - Instituto de Ciências Matemáticas e de Computação        |
 *******************************************************************************
 |                     Bacharelado em Ciências de Computação                   |
 |                                    2021/1                                   |
 |                                                                             |
 |                       Autor: Benício Januário (12543843)                    |
 *******************************************************************************
  > Reverse Polish Notation
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define INITIAL_SIZE 4

typedef struct {
    double *data;
    int top, capacity;
} Stack;

double pop(Stack *stack);
void push(Stack *stack, double value);
void operate(Stack *operatorsStack, char operation);

int main() {

    Stack operators = (Stack) {
        .data = malloc(sizeof(double) * INITIAL_SIZE),
        .capacity = INITIAL_SIZE,
        .top = 0
    };

    char currentChar;
    while((currentChar = fgetc(stdin)) != EOF) {     

        if (!isdigit(currentChar)) operate(&operators, currentChar);
        
        else {
            if (operators.top == operators.capacity) {
                operators.capacity *= 2; // Unused memory is dismissed in push() and pop()
                operators.data = realloc(operators.data, sizeof(double) * operators.capacity);
            }

            ungetc(currentChar, stdin);
            scanf(" %lf", &operators.data[operators.top++]);
        }
        
        fgetc(stdin);
    }

    printf("Resultado: %.6lf\n", operators.data[0]);

    free(operators.data);
    return 0;
}

void operate(Stack *operatorsStack, char operation) {
    double secondOperand = pop(operatorsStack);
    double firstOperand = pop(operatorsStack);

    if (operation == '+') push(operatorsStack, firstOperand + secondOperand);
    else if (operation == '-') push(operatorsStack, firstOperand - secondOperand);
    else if (operation == '*') push(operatorsStack, firstOperand * secondOperand);
    else if (operation == '/') push(operatorsStack, firstOperand / secondOperand);
}

double pop(Stack *stack) {
    double poppedValue = stack->data[--stack->top];
    stack->data = realloc(stack->data, sizeof(double) * --stack->capacity);
    return poppedValue; 
}

void push(Stack *stack, double value) {
    stack->data = realloc(stack->data, sizeof(double) * ++stack->capacity);
    stack->data[stack->top++] = value;
}