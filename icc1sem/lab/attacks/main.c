/*******************************************************************************
 |                        USP - Universidade de São Paulo                      |
 |             ICMC - Instituto de Ciências Matemáticas e de Computação        |
 *******************************************************************************
 |                     Bacharelado em Ciências de Computação                   |
 |                                    2021/1                                   |
 |                                                                             |
 |                       Autor: Benício Januário (12543843)                    |
 *******************************************************************************
  > Ataques e tipos
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 4

typedef struct {
    double power; // To also receive attack power increased by the type multiplier
    int type, index;
} Attack;

typedef struct {
    Attack *attacks;
    int length;
} AttackDeck;

typedef struct {
    double **matrix;
    int order;
} TypeMultipliersTable;

AttackDeck consumeAttacks();
double **consumeDoublesMatrix(int mxOrder);

Attack getBestAttack(AttackDeck attDeck, int enemyType, TypeMultipliersTable multipliersTable);

int main() {
    int typesQuantity;
    scanf(" %d", &typesQuantity);

    TypeMultipliersTable typeMultipliersTable = {
        .matrix = consumeDoublesMatrix(typesQuantity),
        .order = typesQuantity
    };

    AttackDeck attackDeck = consumeAttacks();

    int enemyType;
    scanf(" %d", &enemyType);

    Attack bestAttack = getBestAttack(attackDeck, enemyType, typeMultipliersTable);

    printf("O melhor ataque possui indice %d e dano %.2lf\n", bestAttack.index, bestAttack.power);

    for (int i = 0; i < typeMultipliersTable.order; i++) free(typeMultipliersTable.matrix[i]);
    free(typeMultipliersTable.matrix);
    free(attackDeck.attacks);

    return 0;
}

Attack getBestAttack(AttackDeck attDeck, int enemyType, TypeMultipliersTable multipliersTable) {
    double currentDamage;
    Attack currentAttack, bestAttack = { .power = -1 };
    for (int i = 0; i < attDeck.length; i++) {
        currentAttack = attDeck.attacks[i];
        currentDamage = multipliersTable.matrix[currentAttack.type][enemyType] * currentAttack.power;
        if (currentDamage > bestAttack.power) {
            bestAttack.type = currentAttack.type;
            bestAttack.index = currentAttack.index;
            bestAttack.power = currentDamage;
        }
    }
    return bestAttack;
}

double **consumeDoublesMatrix(int mxOrder) {
    double **matrix = malloc(sizeof(double *) * mxOrder);
    for (int i = 0; i < mxOrder; i++) {
        matrix[i] = malloc(sizeof(double) * mxOrder);
        for (int j = 0; j < mxOrder; j++)
            scanf(" %lf", &matrix[i][j]);
    }

    fgetc(stdin);
    return matrix;
}

AttackDeck consumeAttacks() {
    Attack *attacksArray = malloc(sizeof(Attack) * INITIAL_SIZE);
    int attacksQty = 0, attacksSize = INITIAL_SIZE;

    char currentChar;
    while ((currentChar = fgetc(stdin)) != '-') {
        if (attacksQty == attacksSize) {
            attacksSize *= 2;
            attacksArray = realloc(attacksArray, sizeof(Attack) * attacksSize);
        }

        ungetc(currentChar, stdin);
        scanf(" %lf %d",
            &attacksArray[attacksQty].power,
            &attacksArray[attacksQty].type
        );
        attacksArray[attacksQty].index = attacksQty;

        attacksQty++;
        fgetc(stdin);
    }

    fgetc(stdin);
    attacksArray = realloc(attacksArray, sizeof(Attack) * attacksQty);
    return (AttackDeck) {
        .attacks = attacksArray,
        .length = attacksQty
    };
}