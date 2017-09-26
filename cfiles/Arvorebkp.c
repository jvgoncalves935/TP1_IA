#include "../headers/Arvore.h"
void aproximacao(Estado *e, int mis, int can, int *lado){
    //while(e->ladoDireito[0] < 3 || e->ladoDireito[1] < 3){
    //while(k<3){
    int misEsquerdo,canEsquerdo,misDireito,canDireito;
    misEsquerdo = e->ladoEsquerdo[0];
    canEsquerdo = e->ladoEsquerdo[1];
    misDireito = e->ladoDireito[0];
    canDireito = e->ladoDireito[1];
    if(!lado){
        for(;misEsquerdo>=0;misEsquerdo--){
            for(;canEsquerdo>=0;canEsquerdo--){
                if(acaoValida(misEsquerdo, canEsquerdo, misDireito, canDireito)){
                    printEstado(misEsquerdo, canEsquerdo, misDireito, canDireito);
                }
                canDireito++;
            }
            canDireito=0;
            misDireito++;
            canEsquerdo=can;
        }
        misEsquerdo=0;
        lado=1;
    }else{

    }
    //}
}

int acaoValida(int misEsquerdo, int canEsquerdo, int misDireito, int canDireito){
    //int valido=0;
    if(!misEsquerdo){
        if(misDireito >= canDireito){
            return 1;
        }
        return 0;
    }

    if(!misDireito){
        if(misEsquerdo >= canEsquerdo){
            return 1;
        }
        return 0;
    }


    if((misEsquerdo >= canEsquerdo) && (misDireito >= canDireito)){
        return 1;
    }
    return 0;
}

void printEstado(int misEsquerdo, int canEsquerdo,int misDireito, int canDireito){
    printf("[Esquerdo] M:%d C:%d \t [Direito] M:%d C:%d\n",misEsquerdo,canEsquerdo,misDireito,canDireito);
}

void gerarEstados(){

}
