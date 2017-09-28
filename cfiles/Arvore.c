#include "../headers/Arvore.h"
void aproximacao(Arvore *a, Estado *e, int mis, int can, Estado **vetor_estados, int *num_estados){
    //while(e->ladoDireito->mis < 3 || e->ladoDireito->can < 3){
    //while(k<3){
    int misEsquerdo,canEsquerdo,misDireito,canDireito;
    misEsquerdo = e->ladoEsquerdo->mis;
    canEsquerdo = e->ladoEsquerdo->can;
    misDireito = e->ladoDireito->mis;
    canDireito = e->ladoDireito->can;
    int i=0,j=0;
    if(!e->lado){
        for(i=misEsquerdo;i>=0;i--){
            for(j=canEsquerdo;j>=0;j--){
                if((i+j<=3 && i+j>0) && (i>=j || (i==0 && j>0)) && (acaoValida(misEsquerdo-i,canEsquerdo-j,misDireito+i,canDireito+j))){//&& (acaoValida(misEsquerdo-i,canEsquerdo-j,misDireito+i,canDireito+j))){
                    //printf("aaaaa %d",(*vetor_estados)[i].ladoEsquerdo[0]);
                    Estado *estadoGerado = criarEstado(misEsquerdo-i,canEsquerdo-j,misDireito+i,canDireito+j,e->lado);

                    adicionarNoArvore(a,e,estadoGerado);
                    printEstado(misEsquerdo-i,canEsquerdo-j,misDireito+i,canDireito+j,e->lado,vetor_estados,num_estados);
                }
            }
            j=canEsquerdo;
        }
        i=misEsquerdo;
        e->lado=1;
        printf("\n");
    }else{
        for(i=misDireito;i>=0;i--){
            for(j=canDireito;j>=0;j--){
                if((i+j<=3 && i+j>0) && (i>=j || (i==0 && j>0)) && (acaoValida(misEsquerdo+i,canEsquerdo+j,misDireito-i,canDireito-j))){//&& (acaoValida(misEsquerdo-i,canEsquerdo-j,misDireito+i,canDireito+j))){
                    //printf("bbbb %d",(*vetor_estados)[i].ladoEsquerdo[0]);
                    Estado *estadoGerado = criarEstado(misEsquerdo+i,canEsquerdo+j,misDireito-i,canDireito-j,e->lado);
                    adicionarNoArvore(a,e,estadoGerado);
                    printEstado(misEsquerdo+i,canEsquerdo+j,misDireito-i,canDireito-j,e->lado,vetor_estados,num_estados);

                }
            }
            j=canDireito;
        }
        i=misDireito;
        printf("\n");
        e->lado=0;
    }
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

void printEstado(int misEsquerdo, int canEsquerdo,int misDireito, int canDireito, int lado, Estado **vetor, int *num_estados){

    Estado *e = iniciarEstado(3,3);
    int i;
    int achou=0;
    for(i=0;i<(*num_estados);i++){
        if((*vetor)[i].ladoEsquerdo->mis == misEsquerdo && (*vetor)[i].ladoEsquerdo->can == canEsquerdo && (*vetor)[i].ladoDireito->mis == misDireito && (*vetor)[i].ladoDireito->can == canDireito && (*vetor)[i].lado == lado){
            achou = 1;
            break;
        }
    }

    if(!achou){
        (*num_estados)++;
        //printf("%d num",(*num_estados));
        *vetor = realloc(*vetor,(*num_estados)*sizeof(Estado));
        e->ladoEsquerdo->mis = misEsquerdo;
        e->ladoEsquerdo->can = canEsquerdo;
        e->ladoDireito->mis = misDireito;
        e->ladoDireito->can = canDireito;
        e->lado = lado;
        (*vetor)[i] = *e;
        printf("[Esquerdo] M:%d C:%d \t [Direito] M:%d C:%d -- Canoa Lado:%d\n",misEsquerdo,canEsquerdo,misDireito,canDireito,lado);
    }else{
        printf("[Esquerdo] M:%d C:%d \t [Direito] M:%d C:%d -- Canoa Lado:%d  REPETIDO\n",misEsquerdo,canEsquerdo,misDireito,canDireito,lado);
    }

}

void printEstadoObjeto(Estado *e){
    printf("[Esquerdo] M:%d C:%d \t [Direito] M:%d C:%d -- Canoa Lado:%d\n",(e->ladoEsquerdo->mis),(e->ladoEsquerdo->can),(e->ladoDireito->mis),(e->ladoDireito->can),(e->lado));
}

void gerarEstados(){

}
