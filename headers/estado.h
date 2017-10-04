#ifndef ESTADO_H
#define ESTADO_H

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#define MAX_C 3
#define MAX_M 3
#define TAM_HASH 13300

typedef enum Canoa{
    ESQUERDO,
    DIREITO
}Canoa;

typedef struct Lado{
    int mis;
    int can;
}Lado;

typedef struct Estado{
    Lado esquerdo;
    Lado direito;
    Canoa canoa;
}Estado;

Estado criar_estado(Lado lado, Canoa canoa);

int lado_valido(Lado lado);

int estado_valido(Estado estado);

Lado calcula_lado_oposto(Lado lado);

int indice_hash(Estado estado);

/*
 * DEBUG
 */

void printE(Estado e);

#endif /* ESTADO_H */
