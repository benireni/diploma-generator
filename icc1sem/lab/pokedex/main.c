/*******************************************************************************
 |                        USP - Universidade de São Paulo                      |
 |             ICMC - Instituto de Ciências Matemáticas e de Computação        |
 *******************************************************************************
 |                     Bacharelado em Ciências de Computação                   |
 |                                    2021/1                                   |
 |                                                                             |
 |                       Autor: Benício Januário (12543843)                    |
 *******************************************************************************
  > Pokedex
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 4

enum {
    HALT        = '0',
    ADD_POKEMON = '1',
    ADD_ATTACK  = '2',
    GET_POKEMON = '3',
    GET_ATTACK  = '4'
};

typedef struct {
    int HP, attack, defense, specialAttack, specialDefense, speed;
} Attributes;

typedef struct {
    char name[20];
    int basePower;
    float accuracy;
    char class;
} Attack;

typedef struct {
    char name[50], primaryType[20], secondaryType[20];
    Attack attacks[4];
    Attributes attributes;
} Pokemon;

typedef struct {
    Pokemon *pokemons;
    int length, size;
} Pokedex;

Pokemon consumePokemon();
Attack consumeAttack();

void printPokemon(Pokemon pokemon);
void printAttack(Attack attack);

int main() {
    char command;
    Pokedex pokedex = {
        .pokemons = malloc(INITIAL_SIZE * sizeof(Pokemon)),
        .size = INITIAL_SIZE, .length = 0
    };

    while ((command = fgetc(stdin)) != HALT) {

        if (command == ADD_POKEMON) {
            if (pokedex.length == pokedex.size) {
                pokedex.size *= 2;
                pokedex.pokemons = realloc(pokedex.pokemons, pokedex.size);
            }

            Pokemon newPokemon = consumePokemon();
            pokedex.pokemons[pokedex.length++] = newPokemon;
        }

        if (command == ADD_ATTACK) {
            int pokemonIndex, attackIndex;
            scanf(" %d", &pokemonIndex);
            scanf(" %d", &attackIndex);

            Attack newAttack = consumeAttack();
            pokedex.pokemons[pokemonIndex].attacks[attackIndex] = newAttack;
        }

        if (command == GET_POKEMON) {
            int pokemonIndex;
            scanf(" %d", &pokemonIndex);

            printPokemon(pokedex.pokemons[pokemonIndex]);
        }

        if (command == GET_ATTACK) {
            int pokemonIndex, attackIndex;
            scanf(" %d", &pokemonIndex);
            scanf(" %d", &attackIndex);

            printAttack(pokedex.pokemons[pokemonIndex].attacks[attackIndex]);
        }
    }

    free(pokedex.pokemons);
    return 0;
}

void printPokemon(Pokemon pokemon) {
    printf("Nome do Pokemon: %s\n", pokemon.name);
    printf("Tipo primario: %s\n", pokemon.primaryType);
    printf("Tipo secundario: %s\n", pokemon.secondaryType);
    printf("Status:\n");
    printf("\tHP: %d\n", pokemon.attributes.HP);
    printf("\tAtaque: %d\n", pokemon.attributes.attack);
    printf("\tDefesa: %d\n", pokemon.attributes.defense);
    printf("\tAtaque Especial: %d\n", pokemon.attributes.specialAttack);
    printf("\tDefesa Especial: %d\n", pokemon.attributes.specialDefense);
    printf("\tVelocidade: %d\n\n", pokemon.attributes.speed);
}

void printAttack(Attack attack) {
    printf("Nome do Ataque: %s\n", attack.name);
    printf("Poder base: %d\n", attack.basePower);
    printf("Acuracia: %f\n", attack.accuracy);
    printf("Classe: %c\n\n", attack.class);
}

Pokemon consumePokemon() {
    Pokemon pokemon;    
    scanf(" %s", &pokemon.name[0]);
    scanf(" %s", &pokemon.primaryType[0]);
    scanf(" %s", &pokemon.secondaryType[0]);
    scanf(" %d", &pokemon.attributes.HP);
    scanf(" %d", &pokemon.attributes.attack);
    scanf(" %d", &pokemon.attributes.defense);
    scanf(" %d", &pokemon.attributes.specialAttack);
    scanf(" %d", &pokemon.attributes.specialDefense);
    scanf(" %d", &pokemon.attributes.speed);
    fgetc(stdin);

    return pokemon;
}

Attack consumeAttack() {
    Attack attack;
    scanf(" %s", &attack.name[0]);
    scanf(" %d", &attack.basePower);
    scanf(" %f", &attack.accuracy);
    scanf(" %c", &attack.class);
    fgetc(stdin);

    return attack;
}
