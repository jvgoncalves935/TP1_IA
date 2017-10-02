#include "../headers/Arvore.h"
Estado *iniciarEstado(int mis, int can, int flag){
    Estado *e = malloc(sizeof(Estado));
    e->ladoEsquerdo=malloc(sizeof(Lado));
    e->ladoDireito=malloc(sizeof(Lado));
    if(flag){

        e->ladoEsquerdo->mis=mis;
        e->ladoEsquerdo->can=can;
        e->ladoDireito->mis=0;
        e->ladoDireito->can=0;
        e->lado=0;
    }

    //printf("xddddd %d",(*e->lado));

    return e;
}

Arvore *iniciarArvore(Estado *e){
    Arvore *a = malloc(sizeof(Arvore));
    No *noRaiz = malloc(sizeof(No));
    noRaiz->e = e;
    noRaiz->pai = NULL;
    noRaiz->numFolhas = 0;
    noRaiz->id = 0;
    noRaiz->nodo = malloc(sizeof(No));
    a->raiz = noRaiz;

    //printEstadoObjeto(a->raiz->e);
    a->numFolhas=1;
    return a;
}


Estado *criarEstado(int misEsquerdo, int canEsquerdo,int misDireito, int canDireito, int lado){
    Estado *e = malloc(sizeof(Estado));
    e->ladoEsquerdo = malloc(sizeof(Lado));
    e->ladoDireito = malloc(sizeof(Lado));
    e->ladoEsquerdo->mis = misEsquerdo;
    e->ladoEsquerdo->can = canEsquerdo;
    e->ladoDireito->mis = misDireito;
    e->ladoDireito->can = canDireito;
    e->lado = lado;
    return e;
}




void buscaEmProfundidade(No *no, int nivel, int numNo){
    int i;
    for(i=numNo;i<no->numFolhas;i++){
        printf("[%d]  ", nivel);
        printEstadoObjeto(no->e);
        //if(no->nodo[i] != NULL){
            //buscaEmProfundidade(no->nodo[i], nivel+1,i);
        //}
    }
}

