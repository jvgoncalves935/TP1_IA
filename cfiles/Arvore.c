#include "../headers/Arvore.h"
void aproximacao(Estado *e, int mis, int can, int *lado){
    //while(e->ladoDireito[0] < 3 || e->ladoDireito[1] < 3){
    //while(k<3){
    int misEsquerdo,canEsquerdo,misDireito,canDireito;
    misEsquerdo = e->ladoEsquerdo[0];
    canEsquerdo = e->ladoEsquerdo[1];
    misDireito = e->ladoDireito[0];
    canDireito = e->ladoDireito[1];
    int i=0,j=0;
    if(!*lado){

    }else{

    }
        for(i=misEsquerdo;i>=0;i--){
            for(j=canEsquerdo;j>=0;j--){
                if(i+j<=3 && i+j>0){//&& (acaoValida(misEsquerdo-i,canEsquerdo-j,misDireito+i,canDireito+j))){
                    if(i>=j || (i==0 && j>0)){
                        if(acaoValida(misEsquerdo-i,canEsquerdo-j,misDireito+i,canDireito+j)){
                            printEstado(misEsquerdo-i,canEsquerdo-j,misDireito+i,canDireito+j);
                        }
                    }
                }
            }
            j=canEsquerdo;
        }
        i=misEsquerdo;

    if(!*lado){
        *lado=1;
    }else{
        *lado=0;
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
