#include "../headers/Arvore.h"

#define MIS 3
#define CAN 3

int main(){
    Estado *e = iniciarEstado(MIS,CAN,1);
    Estado *vetor_estados = malloc(sizeof(Estado));
    vetor_estados[0] = *e;
    Arvore *a = iniciarArvore(e);
    a->raiz->vetorEstados = &vetor_estados;
    a->raiz->numEstados=1;
    aproximacao(a,a->raiz,a->raiz->vetorEstados,1);
    return 0;
}
