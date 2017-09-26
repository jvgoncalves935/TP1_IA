#ifndef TAD_H_INCLUDED
#define TAD_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct estado{
    int *ladoEsquerdo;
    int *ladoDireito;
}Estado;

Estado *iniciarEstado(int mis, int can);

#endif // TAD_H_INCLUDED
