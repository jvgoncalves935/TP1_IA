#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#include "Tad.h"

void aproximacao(Estado *e, int mis, int can, int *lado);
void gerarEstados();
void printEstado(int misEsquerdo, int canEsquerdo,int misDireito, int canDireito);
int acaoValida(int misEsquerdo, int canEsquerdo, int misDireito, int canDireito);



#endif // ARVORE_H_INCLUDED
