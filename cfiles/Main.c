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

    aproximacao(e,MIS,CAN,&vetor_estados,num_estados);
    e->ladoEsquerdo[0]=2;
    e->ladoEsquerdo[1]=2;
    e->ladoDireito[0]=1;
    e->ladoDireito[1]=1;
    aproximacao(e,MIS,CAN,&vetor_estados,num_estados);
    e->ladoEsquerdo[0]=3;
    e->ladoEsquerdo[1]=2;
    e->ladoDireito[0]=0;
    e->ladoDireito[1]=1;
    aproximacao(e,MIS,CAN,&vetor_estados,num_estados);
    return 0;
}
