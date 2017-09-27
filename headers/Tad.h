#ifndef TAD_H_INCLUDED
#define TAD_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct lado{
    int mis;
    int can;
}Lado;

typedef struct estado{
    Lado *ladoEsquerdo;
    Lado *ladoDireito;
    int lado; //0: Canoa lado esquerdo, 1: Canoa lado esquerdo.
}Estado;



typedef struct arvore{
    Estado *e;
    struct arvore **nodo;
    struct arvore *pai;
}Arvore;

Estado *iniciarEstado(int mis, int can);

#endif // TAD_H_INCLUDED
