#ifndef BUSCA_H
#define BUSCA_H

#include "arvore.h"
#include "pilha.h"

/* APROFUNDAMENTO ITERATIVO RECURSIVO */

void busca_aprofundamento_iterativo_recursivo();

void aprofundamento_iterativo_recursivo(Arvore arvore, int indice_atual, Pile *pilha, int *achou);



/* APROFUNDAMENTO ITERATIVO */

void busca_aprofundamento_iterativo();


/* BUSCA BI-DIRECIONAL */

void busca_bi_direcional();

#endif /* BUSCA_H */
