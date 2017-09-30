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
    a->raiz = noRaiz;
    //printEstadoObjeto(a->raiz->e);
    a->numFolhas=1;
    return a;
}


void adicionarNoArvore(Arvore *a, No *pai, Estado *filho, int nivel){
    pai->numFolhas++;
    //printf("%d tam %p nodo\n",(pai->numFolhas),pai->nodo);
    //if(!pai->numFolhas){
        //pai->nodo = malloc(sizeof(No));
    //}else{
        //pai->numFolhas++;
        pai->nodo = realloc(pai->nodo,(pai->numFolhas)*sizeof(No));
    //}
    No *no = malloc(sizeof(No));
    no->pai = pai;
    no->e = filho;
    no->numFolhas = 0;
    //printf("pai nodo:%d  nivel:%d\n",pai->numFolhas-1,nivel);
    pai->nodo[pai->numFolhas-1] = *no;
    a->numFolhas++;

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

No *criarNo(Estado *e, Estado **vetor_estados, int num_estados){
    int i;
    No *no = malloc(sizeof(No));
    no->nodo = malloc(sizeof(No));
    no->e = e;
    //no->vetorEstados = vetor_estados;
    no->vetorEstados = malloc(num_estados*sizeof(Estado *));
    no->vetorEstados[0] = malloc(num_estados*sizeof(Estado));

    printf("ENTROU numEst:%d\n",(num_estados));
    no->numEstados=0;





    for(i=0;i<num_estados;i++){

        no->vetorEstados[0][i] = vetor_estados[0][i];
        printf("BBB");

        printEstadoObjetoNotPointer(no->vetorEstados[0][i]);
        no->numEstados++;
        getchar();
        getchar();
        //memcpy(no->vetorEstados[i],vetor_estados[i],sizeof(Estado));
    }
    printf("acabou ");
    //getchar();
    //getchar();
    no->numFolhas=0;

    return no;
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

