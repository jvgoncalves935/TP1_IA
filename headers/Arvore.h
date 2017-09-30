#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#include "Tad.h"

void aproximacao(Arvore *a, No *no_inicial, Estado **vetor_estados, int *num_estados, int nivel);
void gerarEstados();
int adicionarEstado(int misEsquerdo, int canEsquerdo,int misDireito, int canDireito, int lado, No *no, int *num_estados, int nivel, int pos);
int acaoValida(int misEsquerdo, int canEsquerdo, int misDireito, int canDireito);
void printEstadoObjeto(Estado *e);


#endif // ARVORE_H_INCLUDED
