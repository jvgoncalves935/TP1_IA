#include "busca.h"

/* Constantes usadas em todas as buscas */
#define HASH_INICIAL 3300
#define HASH_FINAL 10033
Estado estado_inicial = {{0,0}, {3,3}, ESQUERDO};
Estado estado_final = {{3,3}, {0,0}, DIREITO};


/* APROFUNDAMENTO ITERATIVO */

void busca_aprofundamento_iterativo(){
	Arvore arvore = criar_arvore(HASH_INICIAL);
	
	Pile *pilha = newPile();
	arvore[HASH_INICIAL].visitado = 1;
    addPile(pilha, HASH_INICIAL);

    int v = HASH_INICIAL; // recebe o hash do no inicial.
    int j, proxV; // proxV recebe o próximo vertice a ser
                  // visitado no retorno do algorimto
    while(1){ // enquanto a solução não for obtida...
        j = 0;
        proxV = -1;
        while(j < arvore[v].num_adj){
            
            int hashTemp;
            hashTemp = indice_hash(arvore[arvore[v].adj[j]].e);
            if(hashTemp == HASH_FINAL){ // Se a solução for encontrada.
                
                addPile(pilha, hashTemp);
                goto label_fim;
            }else if(!arvore[arvore[v].adj[j]].visitado && proxV == -1){
                
                proxV = indice_hash(arvore[arvore[v].adj[j]].e);
            }
            j++;
        }
		
        if(proxV == -1){ // Se não encontrou solução e nao tem mais vizinhos para ir.

            removePile(pilha);
            v = pilha->top->obj;
        }else{ // Se não encontrar a solução mas existir vizinhos para ir.
            
            addPile(pilha, proxV);
            v = proxV;
            arvore[v].visitado = 1;
        }
    }
	
	label_fim:
	printPile(pilha, printH);
	deletePile(pilha);
}


/* APROFUNDAMENTO ITERATIVO RECURSIVO */

void busca_aprofundamento_iterativo_recursivo(){
	Arvore arvore = criar_arvore(HASH_INICIAL);
	
	Pile *pilha = newPile();
	
	//Insere o estado inicial na pilha.
	addPile(pilha, HASH_INICIAL);
	
	int achou = 0;
	aprofundamento_iterativo_recursivo(arvore, HASH_INICIAL, pilha, &achou);
	printPile(pilha, printH);
	deletePile(pilha);
}

void aprofundamento_iterativo_recursivo(Arvore arvore, int indice_atual, Pile *pilha, int *achou){
	
	No *atual = &arvore[indice_atual];
    int indice_novo;
	int i;
	if(!arvore[indice_atual].visitado){
		arvore[indice_atual].visitado=1;

		//Largura
		for(i=0;i<arvore[indice_atual].num_adj;i++){
			if(indice_hash(arvore[atual->adj[i]].e) == HASH_FINAL){
			   (*achou) = 1;
			   indice_novo = indice_hash(arvore[atual->adj[i]].e);
			   addPile(pilha, indice_novo);
			   return;
			}
		}

		//Profundidade
		for(i=0;i<arvore[indice_atual].num_adj;i++){
			if(!arvore[arvore[indice_atual].adj[i]].visitado){
				indice_novo = indice_hash(arvore[arvore[indice_atual].adj[i]].e);
				addPile(pilha, indice_novo);
				atual = &arvore[indice_novo];
				aprofundamento_iterativo_recursivo(arvore, indice_novo, pilha, achou);
				if(!(*achou)){
					removePile(pilha);
				}else{
					return;
				}
			}
		}
	}
}


/* BUSCA BI-DIRECIONAL */

///Busca em largura para funcionar no bi-direcional
int larg(int *ini, int *end, int *qnt, No fila[30], int busca[MAX_HASH],
		 Arvore arvore, int flag){
	int j, hash, count=0;
	while((*ini) < (*end)){ //Enquanto não acabou a fila
		No no_atual = fila[((*ini))], aux; //Pega um nó
		hash = indice_hash(no_atual.e); //Gera a hash do nó

		//Verifica quais filhos do nó não foram adicionados
		for(j = 0; j < no_atual.num_adj; j++){ 
			aux = arvore[no_atual.adj[j]];
			if(busca[indice_hash(aux.e)] == 0){ //Se não foi adicionado
				busca[indice_hash(aux.e)] = flag*hash;
				fila[(*end) + count++] = arvore[no_atual.adj[j]]; 
				(*qnt)++;
			}else //Achou a ponta do caminho do lado oposto
				if(busca[indice_hash(aux.e)]*flag < 0){ 
				return indice_hash(aux.e); //Encontrou uma rota
			}
		}
		(*ini)++; (*qnt)--;
	}
	count = 0;
	*end += *qnt; *end %= 30;
	return 0;
}

///Imprime retrocedendo à raiz de inicio
void imprime_ini(int busca[MAX_HASH], int agente, int end){
	if(agente == end){
		return;
	}
	agente = busca[agente];
	if(agente < 0)agente *= -1;
	imprime_ini(busca,agente,end);
	printH(agente);
	return;
}

void busca_bi_direcional(){

	Arvore arvore = criar_arvore(HASH_INICIAL);
	
	//Definindo os dois lados da busca
	int busca[MAX_HASH] = {0};
	//Define um pai inicial para o ini
	busca[indice_hash(estado_inicial)] = indice_hash(estado_inicial); 
	//Define um pai inicial para o end
	busca[indice_hash(estado_final)] = -indice_hash(estado_final); 

	//Descritores fila para a busca no inicio
	int i_ini = 0, i_end = 0, i_qnt = 0; 
	//Descritores fila para a busca no final
	int e_ini = 0, e_end = 0, e_qnt = 0; 
	No i_fila[30], e_fila[30];
	i_fila[i_end++] = arvore[indice_hash(estado_inicial)]; i_qnt++;
	e_fila[e_end++] = arvore[indice_hash(estado_final)]; e_qnt++;

	int agente, objetivo;

	while(1){
		agente = 
		larg(&i_ini, &i_end, &i_qnt, ///Partindo do inicio
			i_fila, busca, arvore, 1);
		objetivo =
		larg(&e_ini, &e_end, &e_qnt, ///Partindo do final
			e_fila, busca, arvore, -1);

		if(agente > 0 || objetivo > 0){
			break;
		}
	}

	imprime_ini(busca,objetivo,indice_hash(estado_inicial));
	printH(objetivo);
	printH(agente);
	while(agente != indice_hash(estado_final)){
		printH(busca[agente] * -1);
		agente = busca[agente];
		if(agente < 0)agente *= -1;
	}
}

