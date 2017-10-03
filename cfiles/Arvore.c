#include "../headers/Arvore.h"
void aproximacao(Arvore *a, No *pai, Estado *vetor_estados, int nivel){
    int misEsquerdo,canEsquerdo,misDireito,canDireito;
    misEsquerdo = pai->e.ladoEsquerdo->mis;
    canEsquerdo = pai->e.ladoEsquerdo->can;
    misDireito = pai->e.ladoDireito->mis;
    canDireito = pai->e.ladoDireito->can;
    
    printf("[%d] M:%d C:%d\t M:%d C:%d\n",pai->id,misEsquerdo,canEsquerdo,misDireito,canDireito);
    
    int i=0,j=0;
    No *no;
    if(!pai->e.lado){
        for(i=misEsquerdo;i>=0;i--){
            for(j=canEsquerdo;j>=0;j--){
                if((i+j<=2 && i+j>0) && (i>=j || (i==0 && j>0)) && (acaoValida(misEsquerdo-i,canEsquerdo-j,misDireito+i,canDireito+j))){
                    Estado estadoGerado = criarEstado(misEsquerdo-i,canEsquerdo-j,misDireito+i,canDireito+j,1);
                    int numE = (pai->numEstados);
                    int valido = verificarEstado(misEsquerdo-i,canEsquerdo-j,misDireito+i,canDireito+j,1,pai);
                    if(valido>-1){
                        no = criarNo(estadoGerado,vetor_estados,numE,a->numFolhas);
                        adicionarNoArvore(a,pai,no,estadoGerado,nivel+1,valido);
                        
                    }

                }
            }
            j=canEsquerdo;
        }
        i=misEsquerdo;

    }else{
        for(i=misDireito;i>=0;i--){
            for(j=canDireito;j>=0;j--){
                if((i+j<=2 && i+j>0) && (i>=j || (i==0 && j>0)) && (acaoValida(misEsquerdo+i,canEsquerdo+j,misDireito-i,canDireito-j))){
                    Estado estadoGerado = criarEstado(misEsquerdo+i,canEsquerdo+j,misDireito-i,canDireito-j,0);
                    int numE = (pai->numEstados);
                    int valido = verificarEstado(misEsquerdo+i,canEsquerdo+j,misDireito-i,canDireito-j,0,pai);
                    if(valido>-1){
                        no = criarNo(estadoGerado,vetor_estados,numE,a->numFolhas);
                        adicionarNoArvore(a,pai,no,estadoGerado,nivel+1,valido);
                        
                    }
                }
            }
            j=canDireito;
        }
        i=misDireito;
    }
    printStatus(pai);
    getchar();
    
    for(i=0;i<pai->numFolhas;i++){
        aproximacao(a,&pai->nodo[i],pai->nodo[i].vetorEstados,nivel+1);
    }
}

int acaoValida(int misEsquerdo, int canEsquerdo, int misDireito, int canDireito){
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

int verificarEstado(int misEsquerdo, int canEsquerdo,int misDireito, int canDireito, int lado, No *no){
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
        return i;
    }else{
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
    int k;
    for(k=0;k<num;k++){
        printEstadoObjetoNotPointer((no->vetorEstados)[k]);
    }
}

void adicionarNoArvore(Arvore *a, No *pai, No *novo_no, Estado filho, int nivel, int pos){
    novo_no->numFolhas++;
    if(!pai->numFolhas){
        pai->nodo = malloc(sizeof(No));
    }
    pai->numFolhas++;
    
    if(novo_no->numFolhas>0){
        novo_no->nodo = realloc(novo_no->nodo,(novo_no->numFolhas)*sizeof(No));
    }else{
        novo_no->nodo = malloc(sizeof(No));
    }
    novo_no->pai = pai;
    novo_no->e = filho;
    novo_no->numFolhas = 0;

    (novo_no->numEstados)++;
    novo_no->vetorEstados = realloc(novo_no->vetorEstados,(novo_no->numEstados)*sizeof(Estado));
    Estado e;
    e = criarEstado(novo_no->e.ladoEsquerdo->mis,novo_no->e.ladoEsquerdo->can,novo_no->e.ladoDireito->mis,novo_no->e.ladoDireito->can,novo_no->e.lado);
    novo_no->vetorEstados[pos] = e;      
    pai->nodo[pai->numFolhas-1] = *novo_no;

    a->numFolhas++;

}

No *criarNo(Estado e, Estado *vetor_estados, int num_estados, int id){

    int i;
    No *no = malloc(sizeof(No));
    no->id = id;
    no->nodo = malloc(sizeof(No));
    no->e = e;
    no->vetorEstados = malloc(num_estados*sizeof(Estado));
    no->numEstados=0;

    for(i=0;i<num_estados;i++){
        no->vetorEstados[i] = vetor_estados[i];
        no->numEstados++;
    }
    no->numFolhas=0;
    return no;
}

void printStatus(No *pai){
    printf("---------------------------------------------------------------------------\n");
    printf("Filhos:\n");
    printNodosFilhos(pai);
    printf("\nLista Estados:\n");
    printListaEstados(pai);
    printf("---------------------------------------------------------------------------\n\n");
}

void printNodosFilhos(No *pai){
    int i;
    for(i=0;i<pai->numFolhas;i++){
        printEstadoObjetoNotPointer((pai->nodo)[i].e);
    }
}