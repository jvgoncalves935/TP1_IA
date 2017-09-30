#include "../headers/Arvore.h"
void aproximacao(Arvore *a, No *no_inicial, Estado **vetor_estados, int *num_estados, int nivel){
    //while(e->ladoDireito->mis < 3 || e->ladoDireito->can < 3){
    //while(k<3){
    int misEsquerdo,canEsquerdo,misDireito,canDireito;
    misEsquerdo = no_inicial->e->ladoEsquerdo->mis;
    canEsquerdo = no_inicial->e->ladoEsquerdo->can;
    misDireito = no_inicial->e->ladoDireito->mis;
    canDireito = no_inicial->e->ladoDireito->can;
    int i=0,j=0;
    if(!no_inicial->e->lado){
        for(i=misEsquerdo;i>=0;i--){
            for(j=canEsquerdo;j>=0;j--){
                if((i+j<=2 && i+j>0) && (i>=j || (i==0 && j>0)) && (acaoValida(misEsquerdo-i,canEsquerdo-j,misDireito+i,canDireito+j))){//&& (acaoValida(misEsquerdo-i,canEsquerdo-j,misDireito+i,canDireito+j))){
                    //printf("aaaaa %d",(*vetor_estados)[i].ladoEsquerdo[0]);
                    Estado *estadoGerado = criarEstado(misEsquerdo-i,canEsquerdo-j,misDireito+i,canDireito+j,1);
                    int numE = (*num_estados);
                    No *no = criarNo(estadoGerado,vetor_estados,numE);
                    adicionarNoArvore(a,no,estadoGerado,nivel+1);
                    int valido = adicionarEstado(misEsquerdo-i,canEsquerdo-j,misDireito+i,canDireito+j,no_inicial->e->lado,no,num_estados,nivel+1,no->numFolhas);
                    if(valido){
                        //printf("COME");
                        aproximacao(a,no,no->vetorEstados,num_estados,nivel+1);
                    }

                }
            }
            j=canEsquerdo;
        }
        i=misEsquerdo;
        //no_inicial->e->lado=1;
        //printf("num estados:%d\n",*num_estados);
    }else{
        for(i=misDireito;i>=0;i--){
            for(j=canDireito;j>=0;j--){
                if((i+j<=2 && i+j>0) && (i>=j || (i==0 && j>0)) && (acaoValida(misEsquerdo+i,canEsquerdo+j,misDireito-i,canDireito-j))){//&& (acaoValida(misEsquerdo-i,canEsquerdo-j,misDireito+i,canDireito+j))){
                    //printf("bbbb %d",(*vetor_estados)[i].ladoEsquerdo[0]);
                    Estado *estadoGerado = criarEstado(misEsquerdo+i,canEsquerdo+j,misDireito-i,canDireito-j,0);
                    int numE = (*num_estados);
                    No *no = criarNo(estadoGerado,vetor_estados,numE);
                    adicionarNoArvore(a,a->raiz,estadoGerado,nivel+1);
                    int valido = adicionarEstado(misEsquerdo+i,canEsquerdo+j,misDireito-i,canDireito-j,no_inicial->e->lado,no,num_estados,nivel+1,no->numFolhas);
                    if(valido){
                        //printf("VAIEM");
                        aproximacao(a,no,no->vetorEstados,num_estados,nivel+1);
                    }
                }
            }
            j=canDireito;
        }
        i=misDireito;
        //printf("\n");
        no_inicial->e->lado=0;
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

int adicionarEstado(int misEsquerdo, int canEsquerdo,int misDireito, int canDireito, int lado, No *no, int *num_estados, int nivel, int pos){

    Estado *e = iniciarEstado(3,3);
    int i;
    int achou=0;
    for(i=0;i<(*num_estados);i++){
        if(no->vetorEstados[0][i].ladoEsquerdo->mis == misEsquerdo && (*no->vetorEstados)[i].ladoEsquerdo->can == canEsquerdo &&
           (*no->vetorEstados)[i].ladoDireito->mis == misDireito && (*no->vetorEstados)[i].ladoDireito->can == canDireito && (*no->vetorEstados)[i].lado == lado){
            achou = 1;
            break;
        }
    }

    if(!achou){
        (*num_estados)++;
        printf("%d num",(*num_estados));
        no->vetorEstados = realloc(no->vetorEstados,(*num_estados)*sizeof(Estado*));
        e->ladoEsquerdo->mis = misEsquerdo;
        e->ladoEsquerdo->can = canEsquerdo;
        e->ladoDireito->mis = misDireito;
        e->ladoDireito->can = canDireito;
        e->lado = lado;
        no->vetorEstados[i] = e;
        no->numEstados =
        printf("[%d,%d]\t [Esq] M:%d C:%d \t [Dir] M:%d C:%d -- Canoa Lado:%d\n",nivel,pos,misEsquerdo,canEsquerdo,misDireito,canDireito,lado);
        return 1;
    }else{
        //printf("[Esquerdo] M:%d C:%d \t [Direito] M:%d C:%d -- Canoa Lado:%d  REPETIDO\n",misEsquerdo,canEsquerdo,misDireito,canDireito,lado);
        return 0;
    }

}

void printEstadoObjeto(Estado *e){
    printf("[Esquerdo] M:%d C:%d \t [Direito] M:%d C:%d -- Canoa Lado:%d\n",(e->ladoEsquerdo->mis),(e->ladoEsquerdo->can),(e->ladoDireito->mis),(e->ladoDireito->can),(e->lado));
}

void gerarEstados(){

}
