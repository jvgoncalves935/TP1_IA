#include "../headers/Arvore.h"
Estado *iniciarEstado(int mis, int can){
    Estado *e = malloc(sizeof(Estado));
    e->ladoEsquerdo=malloc(sizeof(Lado));
    e->ladoDireito=malloc(sizeof(Lado));
    e->ladoEsquerdo->mis=mis;
    e->ladoEsquerdo->can=can;
    e->ladoDireito->mis=0;
    e->ladoDireito->can=0;
    e->lado=0;

    //printf("xddddd %d",(*e->lado));

    return e;
}
