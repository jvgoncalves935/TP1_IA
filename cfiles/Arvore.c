#include "../headers/Arvore.h"
void aproximacao(Arvore *a, No *pai, Estado *vetor_estados, int nivel){
    //while(e->ladoDireito->mis < 3 || e->ladoDireito->can < 3){
    //while(k<3){
    int misEsquerdo,canEsquerdo,misDireito,canDireito;
    misEsquerdo = pai->e->ladoEsquerdo->mis;
    canEsquerdo = pai->e->ladoEsquerdo->can;
    misDireito = pai->e->ladoDireito->mis;
    canDireito = pai->e->ladoDireito->can;
    int i=0,j=0;
    if(!pai->e->lado){
        for(i=misEsquerdo;i>=0;i--){
            for(j=canEsquerdo;j>=0;j--){
                if((i+j<=2 && i+j>0) && (i>=j || (i==0 && j>0)) && (acaoValida(misEsquerdo-i,canEsquerdo-j,misDireito+i,canDireito+j))){//&& (acaoValida(misEsquerdo-i,canEsquerdo-j,misDireito+i,canDireito+j))){
                    //printf("aaaaa %d",(*vetor_estados)[i].ladoEsquerdo[0]);
                    Estado *estadoGerado = criarEstado(misEsquerdo-i,canEsquerdo-j,misDireito+i,canDireito+j,1);
                    int numE = (pai->numEstados);
                    int valido = verificarEstado(misEsquerdo-i,canEsquerdo-j,misDireito+i,canDireito+j,1,pai,nivel+1,pai->numFolhas);
                    if(valido>-1){
                        No *no = criarNo(estadoGerado,vetor_estados,numE);
                        adicionarNoArvore(a,pai,no,estadoGerado,nivel+1,valido);
                        printf("RECURSAO_1\n");
                        aproximacao(a,no,no->vetorEstados,nivel+1);
                    }

                }
            }
            j=canEsquerdo;
        }
        i=misEsquerdo;

    }else{
        for(i=misDireito;i>=0;i--){
            for(j=canDireito;j>=0;j--){
                if((i+j<=2 && i+j>0) && (i>=j || (i==0 && j>0)) && (acaoValida(misEsquerdo+i,canEsquerdo+j,misDireito-i,canDireito-j))){//&& (acaoValida(misEsquerdo-i,canEsquerdo-j,misDireito+i,canDireito+j))){
                    //printf("bbbb %d",(*vetor_estados)[i].ladoEsquerdo[0]);
                    Estado *estadoGerado = criarEstado(misEsquerdo+i,canEsquerdo+j,misDireito-i,canDireito-j,0);
                    int numE = (pai->numEstados);
                    int valido = verificarEstado(misEsquerdo+i,canEsquerdo+j,misDireito-i,canDireito-j,0,pai,nivel+1,pai->numFolhas);
                    if(valido>-1){
                        No *no = criarNo(estadoGerado,vetor_estados,numE);
                        adicionarNoArvore(a,pai,no,estadoGerado,nivel+1,valido);
                        printf("RECURSAO_2\n");
                        aproximacao(a,no,no->vetorEstados,nivel+1);
                    }
                }
            }
            j=canDireito;
        }
        i=misDireito;

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

int verificarEstado(int misEsquerdo, int canEsquerdo,int misDireito, int canDireito, int lado, No *no, int nivel, int pos){


    int i;
    int achou=0;

    for(i=0;i<(no->numEstados);i++){
        if((no->vetorEstados)[i].ladoEsquerdo->mis == misEsquerdo && (no->vetorEstados)[i].ladoEsquerdo->can == canEsquerdo &&
           (no->vetorEstados)[i].ladoDireito->mis == misDireito && (no->vetorEstados)[i].ladoDireito->can == canDireito && (no->vetorEstados)[i].lado == lado){
            achou = 1;
            break;
        }
    }

    if(!achou){
        /*
        printf("ADD ESTADO\n");
        (no->numEstados)++;
        no->vetorEstados = realloc(no->vetorEstados,(no->numEstados)*sizeof(Estado*));
        Estado *e = criarEstado(misEsquerdo,canEsquerdo,misDireito,canDireito,lado);
        no->vetorEstados[i] = *e;
        //no->numEstados++;
        printf("[%d,%d]\t [Esq] M:%d C:%d \t [Dir] M:%d C:%d -- Canoa Lado:%d\n",nivel,pos,misEsquerdo,canEsquerdo,misDireito,canDireito,lado);
        printListaEstados(no);
        */
        return i;
    }else{
        //printf("[Esquerdo] M:%d C:%d \t [Direito] M:%d C:%d -- Canoa Lado:%d  REPETIDO\n",misEsquerdo,canEsquerdo,misDireito,canDireito,lado);
        return -1;
    }

}

void printEstadoObjeto(Estado *e){
    printf("[Esquerdo] M:%d C:%d \t [Direito] M:%d C:%d -- Canoa Lado:%d\n",(e->ladoEsquerdo->mis),(e->ladoEsquerdo->can),(e->ladoDireito->mis),(e->ladoDireito->can),(e->lado));
}

void printEstadoObjetoNotPointer(Estado e){
    printf("[Esquerdo] M:%d C:%d \t [Direito] M:%d C:%d -- Canoa Lado:%d\n",(e.ladoEsquerdo->mis),(e.ladoEsquerdo->can),(e.ladoDireito->mis),(e.ladoDireito->can),(e.lado));
}

void printListaEstados(No *no){
    int num;
    num=no->numEstados;
    printf("--------------------------------------------------\n");
    printf("printLista numEst:%d\n",num);
    int k;
    getchar();
    getchar();
    for(k=0;k<num;k++){
        printf("AAA %d ",k);
        printEstadoObjetoNotPointer((no->vetorEstados)[k]);
    }
    printf("--------------------------------------------------\n");
}

void adicionarNoArvore(Arvore *a, No *pai, No *novo_no, Estado *filho, int nivel, int pos){
    pai->numFolhas++;
    novo_no->numFolhas++;
    printf("numfolhas: %d\n",pai->numFolhas);
    if(novo_no->numFolhas>0){
        novo_no->nodo = realloc(novo_no->nodo,(novo_no->numFolhas)*sizeof(No));
        printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
    //No *no = malloc(sizeof(No));
    novo_no->pai = pai;
    novo_no->e = filho;
    novo_no->numFolhas = 0;

    printf("ADD ESTADO\n");
        (novo_no->numEstados)++;
        novo_no->vetorEstados = realloc(novo_no->vetorEstados,(novo_no->numEstados)*sizeof(Estado*));
        Estado *e = criarEstado(novo_no->e->ladoEsquerdo->mis,novo_no->e->ladoEsquerdo->can,novo_no->e->ladoDireito->mis,novo_no->e->ladoDireito->can,novo_no->e->lado);
        novo_no->vetorEstados[pos] = *e;
        //no->numEstados++;
        printf("[%d,%d]\t [Esq] M:%d C:%d \t [Dir] M:%d C:%d -- Canoa Lado:%d\n",nivel,pos,novo_no->e->ladoEsquerdo->mis,novo_no->e->ladoEsquerdo->can,
               novo_no->e->ladoDireito->mis,novo_no->e->ladoDireito->can,novo_no->e->lado);

        printListaEstados(novo_no);
    printf("%d xddd ",pai->numFolhas-1);
    getchar();
    getchar();
    pai->nodo[pai->numFolhas-1] = *novo_no;

    a->numFolhas++;

}

No *criarNo(Estado *e, Estado *vetor_estados, int num_estados){

    int i;
    No *no = malloc(sizeof(No));
    no->nodo = malloc(sizeof(No));
    no->e = e;
    //no->vetorEstados = vetor_estados;
    no->vetorEstados = malloc(num_estados*sizeof(Estado));
    printf("criarNo numEst:%d\n",(num_estados));
    no->numEstados=0;

    for(i=0;i<num_estados;i++){

        no->vetorEstados[i] = vetor_estados[i];
        printf("BBB");

        printEstadoObjetoNotPointer(no->vetorEstados[i]);
        no->numEstados++;

        //memcpy(no->vetorEstados[i],vetor_estados[i],sizeof(Estado));
    }
    printf("ESTADOS ANTIGOS\n\n");
    no->numFolhas=0;
    return no;
}

void gerarEstados(){

}
