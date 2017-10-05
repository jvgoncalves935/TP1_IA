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
	if(mis_c + can_c > 0 && mis_c + can_c <= 2 && (mis_c <= mis_c || mis_c == 0)){

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
	No novo_no;
	Estado estado_novo;
	Lado esquerdo_novo, direito_novo;
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
void aprofundamento_iterativo(Arvore arvore, int *atual, int solucao, int nivel_arvore){
    if((*atual) != solucao){
        int i;
        arvore[*atual].visitado=1;
        for(i=0;i<arvore[*atual].num_adj;i++){
            
        }
    }
    
}