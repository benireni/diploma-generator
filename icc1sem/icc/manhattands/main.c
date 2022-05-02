/*******************************************************************************
 |                       USP - Universidade de São Paulo                       |
 |            ICMC - Instituto de Ciências Matemáticas e de Computação         |
 *******************************************************************************
 |                    Bacharelado em Ciências de Computação                    |
 |                                   2021/1                                    |
 |                                                                             |
 |                      Autor: Benício Januário (12543843)                     |
 *******************************************************************************
  > Manhattan Delivery Service®
 *******************************************************************************

                                   ,-~ |
       ________________          o==]___|
      |                |            \ \
      |________________|            /\ \
 __  /  _,-----._      )           |  \ \.
|_||/_-~         `.   /()          |  /|]_|_____
  |//              \ |              \/ /_-~     ~-_
  //________________||              / //___________\
 //__|______________| \____________/ //___/-\ \~-_
((_________________/_-o___________/_//___/  /\,\  \
 |__/(  ((====)o===--~~                 (  ( (o/)  )
      \  ``==' /                         \  `--'  /
       `-.__,-'         VRUM VRUM         `-.__,-'
*/


#include <stdio.h>
#include <math.h>

typedef struct {
    int y, x, groundAhead;
} DeliveryPoint;

double calculateLinearDistance(DeliveryPoint origin, DeliveryPoint destiny);
double calculateOutlineDistance(DeliveryPoint origin, DeliveryPoint destiny);

void incrementDistances(DeliveryPoint origin, DeliveryPoint destiny,
    double *euclidesAbsDist, double *hermannsAbsDist);

int main() {
    int deliveryLength, wastelands = 0, residentialLands = 0, parks = 0;
    scanf("%d", &deliveryLength);
    if (deliveryLength <= 0) { printf("Falha no processamento dos dados.\n"); return 0; }

    double euclidesTravelDist = 0, hermannsTravelDist = 0;
    DeliveryPoint currentDelivery, previousDelivery;
    scanf("%d %d %d", &previousDelivery.x, &previousDelivery.y,
                &previousDelivery.groundAhead);

    DeliveryPoint startingPoint = previousDelivery;

    for (int i = 0; i < deliveryLength; i++) {

        if (i != deliveryLength - 1){
            if (scanf("%d %d %d", &currentDelivery.x, &currentDelivery.y, 
            &currentDelivery.groundAhead) == -1) {
                printf("Falha no processamento dos dados.\n");
                return 0;
            }
        } else currentDelivery.x = startingPoint.x, currentDelivery.y = startingPoint.y;

        switch (previousDelivery.groundAhead)
        {
        case 0: {
            double groundOutline = calculateOutlineDistance(previousDelivery, currentDelivery);
            euclidesTravelDist += groundOutline, hermannsTravelDist += groundOutline;
            residentialLands++;
            break;
        }

        case -1:{
            double groundDiagonal = calculateLinearDistance(previousDelivery, currentDelivery);
            euclidesTravelDist += groundDiagonal, hermannsTravelDist += groundDiagonal;
            wastelands++;
            break;
        }

        case +1:
            euclidesTravelDist += calculateLinearDistance(previousDelivery, currentDelivery);
            hermannsTravelDist += calculateOutlineDistance(previousDelivery, currentDelivery);
            parks++;
            break;
        }

        previousDelivery = currentDelivery;
    }

    printf("Ao todo, foi passado por %d terrenos baldios, %d terrenos "
    "residenciais e %d parques.\n", wastelands, residentialLands, parks);

    printf(
        "A diferenca total de distancia percorrida foi de %.2f metros.\n",
        hermannsTravelDist - euclidesTravelDist
    );
}

double calculateLinearDistance(DeliveryPoint origin, DeliveryPoint destiny) {
    return sqrt( pow(destiny.x - origin.x, 2) + pow(destiny.y - origin.y, 2) );
}

double calculateOutlineDistance(DeliveryPoint origin, DeliveryPoint destiny) {
    return fabs(destiny.x - origin.x) + fabs(destiny.y - origin.y);
}