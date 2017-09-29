#include "../headers/Arvore.h"

#define MIS 3
#define CAN 3

int main(){
    Estado *e = iniciarEstado(MIS,CAN);
    //printEstado(e);
    Estado *vetor_estados = malloc(sizeof(int));
    vetor_estados[0] = *e;
    int *num_estados=malloc(sizeof(int));
    (*num_estados)=1;
    Arvore *a = iniciarArvore(e);
    aproximacao(a,a->raiz,&vetor_estados,num_estados,1);
    /*
    e->ladoEsquerdo->mis=2;
    e->ladoEsquerdo->can=2;
    e->ladoDireito->mis=1;
    e->ladoDireito->can=1;
    aproximacao(a,e,&vetor_estados,num_estados);
    e->ladoEsquerdo->mis=3;
    e->ladoEsquerdo->can=2;
    e->ladoDireito->mis=0;
    e->ladoDireito->can=1;
    aproximacao(a,e,&vetor_estados,num_estados);
    */
    return 0;
}
