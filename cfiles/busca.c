#include "busca.h"

/* Constantes usadas em todas as buscas */
#define HASH_INICIAL 3300
#define HASH_FINAL 10033
Estado estado_inicial = {{0,0}, {3,3}, ESQUERDO};
Estado estado_final = {{3,3}, {0,0}, DIREITO};


/* APROFUNDAMENTO ITERATIVO RECURSIVO */

void busca_aprofundamento_iterativo_recursivo(){
	Arvore arvore = criar_arvore();
	
	arvore[HASH_INICIAL] = criar_no(estado_inicial, 0);
	
	gerar_arvore(arvore, HASH_INICIAL);
	
	Pile *pilha = newPile();
	
	//Insere o estado inicial na pilha.
	int hash_inicial = HASH_INICIAL;
	addPile(pilha, (void *) &hash_inicial);
	
	int achou = 0;
	aprofundamento_iterativo_recursivo(arvore, &arvore[indice_hash(estado_inicial)], indice_hash(estado_final), 0, pilha, &achou);
	printPile(pilha);
	deletePile(pilha);
}

void aprofundamento_iterativo_recursivo(Arvore arvore, No *atual, int solucao, int nivel_arvore, Pile *pilha, int *achou){
    int index = indice_hash(atual->e);
    int *valor = malloc(sizeof(int));
    if(!(*achou)){
        if(index != solucao){
            int i;
            if(!arvore[index].visitado){
                arvore[index].visitado=1;
                
                //Largura
                for(i=0;i<arvore[index].num_adj;i++){
                    if(indice_hash(arvore[atual->adj[i]].e) == solucao){
                       (*achou) = 1;
                       *valor = indice_hash(arvore[atual->adj[i]].e);
                       addPile(pilha, (void *) valor);
                       return;   
                    }
                }
                
                //Profundidade
                for(i=0;i<arvore[index].num_adj;i++){
                    if(!arvore[arvore[index].adj[i]].visitado){
                        *valor = indice_hash(arvore[arvore[index].adj[i]].e);
                        addPile(pilha, (void *) valor);
                        atual = &arvore[*valor];
                        aprofundamento_iterativo_recursivo(arvore,atual,solucao,nivel_arvore+1,pilha,achou);
                        if(!(*achou)){
                            removePile(pilha);
                        }else{
                            return;
                        }
                    }
                }   
            }
        }else{
            (*achou) = 1;
            *valor = indice_hash(arvore[index].e);
            addPile(pilha, (void *) valor);
        }
    }
}


/* APROFUNDAMENTO ITERATIVO */

void busca_aprofundamento_iterativo(){
	Arvore arvore = criar_arvore();
	
	arvore[HASH_INICIAL] = criar_no(estado_inicial, 0);
	
	gerar_arvore(arvore, HASH_INICIAL);
	
	Pile *pilha = aprofundamento_iterativo(arvore, HASH_INICIAL, HASH_FINAL);
	printPile(pilha);
	deletePile(pilha);
}

Pile *aprofundamento_iterativo(Arvore arvore, int indiceAtual, int solucao){        
    
    Pile *pilha = newPile();
    int *indHash = malloc(sizeof(int));
    *indHash = indiceAtual;
    arvore[*indHash].visitado = 1;
    addPile(pilha, (void *)indHash);        
    if(*indHash == solucao){ // se a raiz for a soluﾃｧﾃ｣o 
                             // retorna a raiz.   
        return pilha;
    }
    int v = indiceAtual; // recebe o hash do no atual.
    int j, proxV; // proxV recebe o prﾃｳximo vertice a ser 
                       // visitado no retorno do algorimto    
    while(1){ // enquanto a soluﾃｧﾃ｣o nﾃ｣o for obtida...
                        
        j = 0;
        proxV = -1;        
        while(j < arvore[v].num_adj){
            
            int *hashTemp = malloc(sizeof(int));
            *hashTemp = indice_hash(arvore[arvore[v].adj[j]].e);                
            if(*hashTemp == solucao){ // Se a soluﾃｧﾃ｣o for encontrada.
                
                addPile(pilha, (void *)hashTemp);                                
                return pilha;
            }else if(!arvore[arvore[v].adj[j]].visitado && proxV == -1){
                
                proxV = indice_hash(arvore[arvore[v].adj[j]].e);                
            }
            j++;            
        }
        int *temp;
        if(proxV == -1){ // Se nﾃ｣o encontrou soluﾃｧﾃ｣o e nao tem mais vizinhos para ir.
                        
            removePile(pilha);
            temp = (int *)pilha->top->obj;            
            v = *temp;            
        }else{ // Se nﾃ｣o encontrar a soluﾃｧﾃ｣o mas existir vizinhos para ir.
            
            temp = malloc(sizeof(int));
            *temp = proxV;
            addPile(pilha, (void *)temp);
            v = proxV;
            arvore[v].visitado = 1;            
        }                
    }        
}
