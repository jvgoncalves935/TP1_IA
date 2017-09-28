#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#include "Tad.h"

void aproximacao(Arvore *a, Estado *e, int mis, int can, Estado **vetor_estados, int *num_estados);
void gerarEstados();
void printEstado(int misEsquerdo, int canEsquerdo,int misDireito, int canDireito, int lado, Estado **vetor_estados, int *num_estados);
int acaoValida(int misEsquerdo, int canEsquerdo, int misDireito, int canDireito);
void printEstadoObjeto(Estado *e);


#endif // ARVORE_H_INCLUDED
