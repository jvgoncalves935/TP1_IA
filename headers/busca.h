#ifndef BUSCA_H
#define BUSCA_H

#include "arvore.h"
#include "pilha.h"

/* APROFUNDAMENTO ITERATIVO RECURSIVO */

void busca_aprofundamento_iterativo_recursivo();

void aprofundamento_iterativo_recursivo(Arvore arvore, int indice_atual, Pile *pilha, int *achou);



/* APROFUNDAMENTO ITERATIVO */

void busca_aprofundamento_iterativo();

Pile *aprofundamento_iterativo(Arvore arvore, int indiceAtual, int solucao);


/* BUSCA BI-DIRECIONAL */
//TO-DO

#endif /* BUSCA_H */