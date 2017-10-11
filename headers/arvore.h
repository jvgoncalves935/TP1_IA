#ifndef ARVORE_H
#define ARVORE_H

#include "estado.h"

typedef struct No{
    Estado e;       ///Estado correspondente ao nó.
    int num_adj;    ///Número de nós adjacentes.
    int *adj;       ///Endereco dos nós adjacentes na hash.
    int criado;     ///Se o nó já foi criado. (usado na geração da árvore)
    int visitado;   ///Indica se o nó ja foi visitado.
    int pai;        ///Indice do pai na tabela de hash.
}No;

///Árvore é um vetor de No.
typedef No * Arvore;

No criar_no(Estado e, int pai);

Arvore criar_arvore(int hash_inicial);

int acao_valida(Estado estado, int mis_c, int can_c);

void adicionar_adj(Arvore arvore, int indice_atual, int indice_novo);

void gerar_adj(Arvore arvore, int indice_atual, Lado lado, Canoa);

void gerar_arvore(Arvore arvore, int indice_atual);

#endif /* ARVORE_H */
