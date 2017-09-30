#ifndef TAD_H_INCLUDED
#define TAD_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lado{
    int mis;
    int can;
}Lado;

typedef struct estado{
    Lado *ladoEsquerdo;
    Lado *ladoDireito;
    int lado; //0: Canoa lado esquerdo, 1: Canoa lado esquerdo.
}Estado;



typedef struct no{
    Estado *e;
    Estado **vetorEstados;
    struct no *nodo;
    struct no *pai;
    int numFolhas;
    int numEstados;
}No;

typedef struct arvore{
    No *raiz;
    int numFolhas;
}Arvore;

Estado *iniciarEstado(int mis, int can);
Arvore *iniciarArvore(Estado *e);
void adicionarNoArvore(Arvore *a, No *pai, Estado *filho, int nivel);
void buscaEmProfundidade(No *no, int nivel, int numNo);
Estado *criarEstado(int misEsquerdo, int canEsquerdo,int misDireito, int canDireito, int lado);
No *criarNo(Estado *e, Estado **vetor_estados, int num_estados);

#endif // TAD_H_INCLUDED