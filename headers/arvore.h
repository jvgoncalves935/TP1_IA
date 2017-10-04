#ifndef ARVORE_H
#define ARVORE_H

#include "estado.h"

typedef struct No{
    Estado e;       ///Estado correspondente ao nó.
    int num_adj;    ///Número de nós adjacentes.
    int *adj;       ///Endereco dos nós adjacentes na hash.
    int visitado;   ///Indica se o nó ja foi visitado.
    int pai;        ///Indice do pai na tabela de hash.
}No;

typedef No * Arvore;

No criar_no(Estado e, int pai);

Arvore criar_arvore();

int acao_valida(Lado esquerdo, Lado direito, int mis_c, int can_c);

void adicionar_adj(Arvore arvore, No *atual, No novo);

void gerar_arvore(Arvore arvore, No *atual);

#endif /* ARVORE_H */
