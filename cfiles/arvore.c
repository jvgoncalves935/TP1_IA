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

int acao_valida(Lado esquerdo, Lado direito, int mis_c, int can_c){
	if(mis_c + can_c > 0 && mis_c + can_c <= 2 && (mis_c <= mis_c || mis_c == 0)){

		if(lado_valido(esquerdo) && lado_valido(direito)){
			return 1;
		}
	}

	return 0;
}

void adicionar_adj(Arvore arvore, No *atual, No novo){
	int indice_novo = indice_hash(novo.e);
	
    if(!arvore[indice_novo].visitado){
		//Adiciona o vértice novo na árvore.
		arvore[indice_novo] = novo;
		arvore[indice_novo].visitado = 1;

		//O indice do novo no e inserido na lista de adjacentes do atual.
		int temp = atual->num_adj;
        atual->num_adj++;
        atual->adj = realloc(atual->adj, atual->num_adj * sizeof(int));
        atual->adj[temp] = indice_novo;
    }
}

int nivel = 0;
void gerar_arvore(Arvore arvore, No *atual){
	int hash_atual = indice_hash(atual->e); //Cache da hash do no atual para evitar
											//recalculo.
	
	nivel++;
	printf("%d Atual: ", nivel); printE(atual->e);
	//TO-DO: organizar isso numa funçao.
	No novo_no;
	Lado esquerdo_novo, direito_novo;
	int mis, can;
	if(atual->e.canoa == ESQUERDO){
		for(can = atual->e.esquerdo.mis; can >= 0; can--){
			for(mis = atual->e.esquerdo.can; mis >= 0; mis--){
				
				direito_novo.mis = mis;
				direito_novo.can = can;
				esquerdo_novo = calcula_lado_oposto(direito_novo); //Lado esquerdo apos a movimentaçao da canoa.
				
				if(acao_valida(esquerdo_novo, direito_novo, mis, can)){ //Se ambos sao validos.
					novo_no = criar_no(criar_estado(esquerdo_novo, DIREITO), hash_atual);
					adicionar_adj(arvore, atual, novo_no);
				}
			}
		}
	}else{
		for(can = atual->e.direito.mis; can >= 0; can--){
			for(mis = atual->e.direito.can; mis >= 0; mis--){
				
				esquerdo_novo.mis = mis;
				esquerdo_novo.can = can;
				direito_novo = calcula_lado_oposto(esquerdo_novo); //Lado direito após a movimentaçao da canoa.
				
				if(acao_valida(esquerdo_novo, direito_novo, mis, can)){ //Se ambos são válidos.
					novo_no = criar_no(criar_estado(direito_novo, ESQUERDO), hash_atual);
					adicionar_adj(arvore, atual, novo_no);
				}
			}
		}
	}

	int i;
	for(i=0; i<atual->num_adj; i++){
		gerar_arvore(arvore, &arvore[atual->adj[i]]);
	}
	nivel--;
}
