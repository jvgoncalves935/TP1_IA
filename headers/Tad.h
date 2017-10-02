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
    Estado *vetorEstados;
    struct no *nodo;
    struct no *pai;
    int numFolhas;
    int numEstados;
    int id;
}No;

typedef struct arvore{
    No *raiz;
    int numFolhas;
}Arvore;

Estado *iniciarEstado(int mis, int can, int flag);
Arvore *iniciarArvore(Estado *e);
void buscaEmProfundidade(No *no, int nivel, int numNo);
Estado *criarEstado(int misEsquerdo, int canEsquerdo,int misDireito, int canDireito, int lado);


#endif // TAD_H_INCLUDED
