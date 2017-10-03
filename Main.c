#include "../headers/Arvore.h"

#define MIS 3
#define CAN 3

int main(){
    Estado e = criarEstado(MIS,CAN,0,0,0);
    Arvore *a = iniciarArvore(e);
    printf("\n");
    aproximacao(a,a->raiz,a->raiz->vetorEstados,0);
    printf("\nFIM\n");
    return 0;
}
