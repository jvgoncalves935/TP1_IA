#include "arvore.h"

No criar_no(Estado e, int pai){
    No no;
    
    no.e = e;
    no.pai = pai;
    no.num_adj = 0;
    no.adj = NULL;
    no.visitado = 0;
    
    return no;
}

Arvore criar_arvore(){
    return calloc(TAM_HASH, sizeof(No));
}

int acao_valida(Estado estado, int mis_c, int can_c){
	if(mis_c + can_c > 0 && mis_c + can_c <= 2 && (can_c <= mis_c || mis_c == 0)){

		if(estado_valido(estado)){
			return 1;
		}
	}

	return 0;
}

void adicionar_adj(Arvore arvore, int indice_atual, int indice_novo){
	No *atual = &arvore[indice_atual];
	
	//O indice do novo nó é inserido na lista de adjacentes do atual.
	int temp = atual->num_adj;
	atual->num_adj++;
	atual->adj = realloc(atual->adj, atual->num_adj * sizeof(int));
	atual->adj[temp] = indice_novo;
}

int nivel = 0, total = 1;
void gerar_arvore(Arvore arvore, int indice_atual, int *nivel_arvore){
	No *atual = &arvore[indice_atual];
	
	//Marca o nó como visitado.
	//atual->visitado = 1;
	
	nivel++;
        if(nivel>(*nivel_arvore)){
            (*nivel_arvore) = nivel;
        }
	printf("\tPai: %d", arvore[atual->pai].visitado); printE(arvore[atual->pai].e);
	printf("%d %d Atual: ", nivel, atual->visitado); printE(atual->e);
	puts("");
	
	//TO-DO: organizar isso numa funçao.
	//No novo_no;
	Estado estado_novo;
	Lado esquerdo_novo;
	int mis, can;
	int indice_novo;
	
	Lado lado_atual;
	int wtf;
	
	if(atual->e.canoa == ESQUERDO){
		lado_atual = atual->e.esquerdo;
		wtf = -1;
	}else{
		lado_atual = atual->e.direito;
		wtf = 1;
	}
	for(mis = lado_atual.mis; mis >= 0; mis--){
		for(can = lado_atual.can; can >= 0; can--){

			esquerdo_novo.mis = atual->e.esquerdo.mis + (wtf * mis);
			esquerdo_novo.can = atual->e.esquerdo.can + (wtf * can);
			estado_novo = criar_estado(esquerdo_novo, !atual->e.canoa);

			if(acao_valida(estado_novo, mis, can)){
				indice_novo = indice_hash(estado_novo);
				if(!arvore[indice_novo].visitado){
					arvore[indice_novo] = criar_no(estado_novo, indice_atual);
					total++;
				}
				adicionar_adj(arvore, indice_atual, indice_novo);
			}
		}
	}

	int i;
	
	printf("Filhos:\n");
	for(i=0; i<atual->num_adj; i++){
		printf("    %d: ", arvore[atual->adj[i]].visitado);
		printE( arvore[atual->adj[i]].e );
	}
	
	for(i=0; i<atual->num_adj; i++){
		if(!arvore[atual->adj[i]].visitado){
			arvore[atual->adj[i]].visitado = 1;
			gerar_arvore(arvore, atual->adj[i],nivel_arvore);
		}
	}
	nivel--;
}

void zerar_nodos_visitados(Arvore arvore, int tamanho){
    int i;
    for(i=0;i<tamanho;i++){
        arvore[i].visitado=0;
    }
}

int nivel_recursao=0;

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