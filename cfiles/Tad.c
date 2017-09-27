#include "../headers/Arvore.h"
Estado *iniciarEstado(int mis, int can){
    Estado *e = malloc(sizeof(Estado));
    e->ladoEsquerdo=malloc(2*sizeof(int));
    e->ladoDireito=malloc(2*sizeof(int));
    e->ladoEsquerdo[0]=mis;
    e->ladoEsquerdo[1]=can;
    e->ladoDireito[0]=0;
    e->ladoDireito[1]=0;
    e->lado=0;

    //printf("xddddd %d",(*e->lado));

    return e;
}
