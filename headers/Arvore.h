#ifndef ARVORE_H
#define ARVORE_H

#include "estado.h"

typedef struct No{
    Estado e;
    int num_adj; ///Número de nós adjacentes.
    int *adj;///Endereco dos nós adjacentes na hash.
    int visitado;
    No *pai;
    
}No;

typedef No * Arvore;

No cria_no(No *pai, Estado e);

Arvore iniciar_arvore();

void adicionar_adj(Arvore arvore, No *atual, No *novo);

#endif /* ARVORE_H */
