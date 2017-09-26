#include "../headers/Arvore.h"
void aproximacao(Estado *e, int mis, int can){
    //while(e->ladoDireito[0] < 3 || e->ladoDireito[1] < 3){
    //while(k<3){
        for(;e->ladoEsquerdo[0]>=0;e->ladoEsquerdo[0]--){
            for(;e->ladoEsquerdo[1]>=0;e->ladoEsquerdo[1]--){
                if(acaoValida(e)){
                    printEstado(e);
                }
                e->ladoDireito[1]++;
            }
            e->ladoDireito[1]=0;
            e->ladoDireito[0]++;
            e->ladoEsquerdo[1]=can;
        }
        e->ladoEsquerdo[0]=0;
    //}
}

int acaoValida(Estado *e){
    //int valido=0;
    if(!e->ladoEsquerdo[0]){
        if(e->ladoDireito[0] >= e->ladoDireito[1]){
            return 1;
        }
        return 0;
    }

    if(!e->ladoDireito[0]){
        if(e->ladoEsquerdo[0] >= e->ladoEsquerdo[1]){
            return 1;
        }
        return 0;
    }


    if((e->ladoEsquerdo[0] >= e->ladoEsquerdo[1]) && (e->ladoDireito[0] >= e->ladoDireito[1])){
        return 1;
    }
    return 0;
}

void printEstado(Estado *e){
    printf("[Esquerdo] M:%d C:%d \t [Direito] M:%d C:%d\n",e->ladoEsquerdo[0],e->ladoEsquerdo[1],e->ladoDireito[0],e->ladoDireito[1]);
}

void gerarEstados(){

}
