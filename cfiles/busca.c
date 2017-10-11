#include "busca.h"

/* Constantes usadas em todas as buscas */
#define HASH_INICIAL 3300
#define HASH_FINAL 10033
Estado estado_inicial = {{0,0}, {3,3}, ESQUERDO};
Estado estado_final = {{3,3}, {0,0}, DIREITO};


/* APROFUNDAMENTO ITERATIVO */

void busca_aprofundamento_iterativo(){
	Arvore arvore = criar_arvore();
	
	arvore[HASH_INICIAL] = criar_no(estado_inicial, 0);
	
	gerar_arvore(arvore, HASH_INICIAL);
	
	Pile *pilha = aprofundamento_iterativo(arvore, HASH_INICIAL, HASH_FINAL);
	printPile(pilha);
	deletePile(pilha);
}

Pile *aprofundamento_iterativo(Arvore arvore, int indiceInicial, int indiceFinal){        
    
    Pile *pilha = newPile();
    int *indHash = malloc(sizeof(int));
    *indHash = indiceInicial;
    arvore[*indHash].visitado = 1;
    addPile(pilha, (void *)indHash);        
    if(*indHash == indiceFinal){ // se a raiz for a solução 
                             // retorna a raiz.   
        return pilha;
    }
    int v = indiceInicial; // recebe o hash do no inicial.
    int j, proxV; // proxV recebe o próximo vertice a ser 
                  // visitado no retorno do algorimto    
    while(1){ // enquanto a solução não for obtida...
                        
        j = 0;
        proxV = -1;        
        while(j < arvore[v].num_adj){
            
            int *hashTemp = malloc(sizeof(int));
            *hashTemp = indice_hash(arvore[arvore[v].adj[j]].e);                
            if(*hashTemp == indiceFinal){ // Se a solução for encontrada.
                
                addPile(pilha, (void *)hashTemp);                                
                return pilha;
            }else if(!arvore[arvore[v].adj[j]].visitado && proxV == -1){
                
                proxV = indice_hash(arvore[arvore[v].adj[j]].e);                
            }
            j++;            
        }
        int *temp;
        if(proxV == -1){ // Se não encontrou solução e nao tem mais vizinhos para ir.
                        
            removePile(pilha);
            temp = (int *)pilha->top->obj;            
            v = *temp;            
        }else{ // Se não encontrar a solução mas existir vizinhos para ir.
            
            temp = malloc(sizeof(int));
            *temp = proxV;
            addPile(pilha, (void *)temp);
            v = proxV;
            arvore[v].visitado = 1;            
        }                
    }        
}

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
	aprofundamento_iterativo_recursivo(arvore, HASH_INICIAL, pilha, &achou);
	printPile(pilha);
	deletePile(pilha);
}

void aprofundamento_iterativo_recursivo(Arvore arvore, int indice_atual, Pile *pilha, int *achou){
	
	No *atual = &arvore[indice_atual];
    int *indice_novo = malloc(sizeof(int));
	int i;
	if(!arvore[indice_atual].visitado){
		arvore[indice_atual].visitado=1;

		//Largura
		for(i=0;i<arvore[indice_atual].num_adj;i++){
			if(indice_hash(arvore[atual->adj[i]].e) == HASH_FINAL){
			   (*achou) = 1;
			   *indice_novo = indice_hash(arvore[atual->adj[i]].e);
			   addPile(pilha, (void *) indice_novo);
			   return;
			}
		}

		//Profundidade
		for(i=0;i<arvore[indice_atual].num_adj;i++){
			if(!arvore[arvore[indice_atual].adj[i]].visitado){
				*indice_novo = indice_hash(arvore[arvore[indice_atual].adj[i]].e);
				addPile(pilha, (void *) indice_novo);
				atual = &arvore[*indice_novo];
				aprofundamento_iterativo_recursivo(arvore, *indice_novo, pilha, achou);
				if(!(*achou)){
					removePile(pilha);
				}else{
					return;
				}
			}
		}
	}
}
