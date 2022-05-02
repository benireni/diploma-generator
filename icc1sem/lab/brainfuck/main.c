/*******************************************************************************
 |                        USP - Universidade de São Paulo                      |
 |             ICMC - Instituto de Ciências Matemáticas e de Computação        |
 *******************************************************************************
 |                     Bacharelado em Ciências de Computação                   |
 |                                    2021/1                                   |
 |                                                                             |
 |                       Autor: Benício Januário (12543843)                    |
 *******************************************************************************
  > Brainfuck JIT Compiler
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROGRAM_MEMORY 30000

#define PROGRAM_START "#include <stdio.h>\n\nint main() {\n\tchar mem[30000];\
\n\tint i = 0;\n\tfor (int j = 0; j < 30000; j++) mem[j] = 0;\n"

#define ALL_CELLS_PRINT "\n\tprintf(\"\\n\");\n\tfor (int j = 0; j < 30000; j++)\
\n\t\tif (mem[j] != 0) printf(\"%d \", mem[j]);\n\tprintf(\"\\n\");"

#define CELL_INCREMENT "\tmem[i]++;\n"
#define CELL_DECREMENT "\tmem[i]--;\n"

#define FORWARD_STEP   "\ti++;\n"
#define BACKWARD_STEP  "\ti--;\n"

#define LOOP_OPENING   "\twhile (mem[i]) {\n"
#define LOOP_CLOSING   "\t}\n"

#define PRINT_CELL     "\tputchar(mem[i]);\n"


int main() {
    FILE *transpiledFile = fopen("jit-bf.c", "w");

    fwrite(PROGRAM_START, sizeof(char), strlen(PROGRAM_START), transpiledFile);

    char operation;
    unsigned int additionalTabs = 0;
    while ((operation = fgetc(stdin)) != EOF) {

        for (int i = 0; i < additionalTabs; i++) fwrite("\t", sizeof(char), 1, transpiledFile);
        
        if (operation == '+')
            fwrite(CELL_INCREMENT, sizeof(char), strlen(CELL_INCREMENT), transpiledFile);
        
        else if (operation == '-')
            fwrite(CELL_DECREMENT, sizeof(char), strlen(CELL_DECREMENT), transpiledFile);
        
        else if (operation == '>')
            fwrite(FORWARD_STEP, sizeof(char), strlen(FORWARD_STEP), transpiledFile);
        
        else if (operation == '<')
            fwrite(BACKWARD_STEP, sizeof(char), strlen(BACKWARD_STEP), transpiledFile);

        else if (operation == '.')
            fwrite(PRINT_CELL, sizeof(char), strlen(PRINT_CELL), transpiledFile);
        
        else if (operation == '[') {
            fwrite(LOOP_OPENING, sizeof(char), strlen(LOOP_OPENING), transpiledFile);
            additionalTabs++;
        }

        else if (operation == ']') {
            fseek(transpiledFile, -1 * sizeof(char), SEEK_CUR);
            fwrite(LOOP_CLOSING, sizeof(char), strlen(LOOP_CLOSING), transpiledFile);
            additionalTabs--;   
        }
    }

    fwrite(ALL_CELLS_PRINT, sizeof(char), strlen(ALL_CELLS_PRINT), transpiledFile);
    fwrite("\n}", sizeof(char), 2, transpiledFile);

    fclose(transpiledFile);

    system("gcc jit-bf.c -o jit-bf-exe");
    system("./jit-bf-exe");

    return 0;
}