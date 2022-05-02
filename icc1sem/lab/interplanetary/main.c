/*******************************************************************************
 |                        USP - Universidade de São Paulo                      |
 |             ICMC - Instituto de Ciências Matemáticas e de Computação        |
 *******************************************************************************
 |                     Bacharelado em Ciências de Computação                   |
 |                                    2021/1                                   |
 |                                                                             |
 |                       Autor: Benício Januário (12543843)                    |
 *******************************************************************************
  > eu te vejo sumir por aí
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EARTH_DAY_SECS    86400
#define VENUS_DAY_SECS    20995200
#define MERCURY_DAY_SECS  5068800
#define JUPITER_DAY_SECS  35760

#define HOUR_SECS         3600
#define MIN_SECS          60

void parseEarthSeconds(
    long long unsigned int *days,
    long long unsigned int *hours,
    long long unsigned int *minutes,
    long long unsigned int *seconds,
    char targetPlanet[]
);

int main() {
    char planet[8];
    long long unsigned int *seconds = malloc(sizeof(long long unsigned int));
    long long unsigned int *days = malloc(sizeof(long long unsigned int));
    long long unsigned int *hours = malloc(sizeof(long long unsigned int));
    long long unsigned int *minutes = malloc(sizeof(long long unsigned int));

    scanf("%llu %s", seconds, &planet[0]);
    printf("%llu segundos no planeta %s equivalem a:\n", *seconds, planet);

    parseEarthSeconds(days, hours, minutes, seconds, planet);

    printf("%llu dias, %llu horas, %llu minutos e %llu segundos\n", *days, *hours, *minutes, *seconds);

    free(seconds);
    free(days);
    free(hours);
    free(minutes);
    return 0;
}

void parseEarthSeconds(
    long long unsigned int *days,
    long long unsigned int *hours,
    long long unsigned int *minutes,
    long long unsigned int *seconds,
    char targetPlanet[]
) {
    if (strcmp(targetPlanet, "Terra") == 0) {
        *days = (*seconds)/EARTH_DAY_SECS; *seconds -= EARTH_DAY_SECS*(*days);
        *hours = (*seconds)/HOUR_SECS; *seconds -= HOUR_SECS*(*hours);
        *minutes = (*seconds)/MIN_SECS; *seconds -= MIN_SECS*(*minutes);
    }

    if (strcmp(targetPlanet, "Venus") == 0) {
        *days = (*seconds)/VENUS_DAY_SECS; *seconds -= VENUS_DAY_SECS*(*days);
        *hours = (*seconds)/HOUR_SECS; *seconds -= HOUR_SECS*(*hours);
        *minutes = (*seconds)/MIN_SECS; *seconds -= MIN_SECS*(*minutes);
    }

    if (strcmp(targetPlanet, "Mercurio") == 0) {
        *days = (*seconds)/MERCURY_DAY_SECS; *seconds -= MERCURY_DAY_SECS*(*days);
        *hours = (*seconds)/HOUR_SECS; *seconds -= HOUR_SECS*(*hours);
        *minutes = (*seconds)/MIN_SECS; *seconds -= MIN_SECS*(*minutes);
    }

    if (strcmp(targetPlanet, "Jupiter") == 0) {
        *days = (*seconds)/JUPITER_DAY_SECS; *seconds -= JUPITER_DAY_SECS*(*days);
        *hours = (*seconds)/HOUR_SECS; *seconds -= HOUR_SECS*(*hours);
        *minutes = (*seconds)/MIN_SECS; *seconds -= MIN_SECS*(*minutes);
    }
}