#include "arvore.h"

No cria_no(No *pai, Estado e){
    No no;
    
    no->e = e;
    no->pai = pai;
    no->num_adj = 0;
    no->adj = malloc(0);
    no->visitado = 0;
    
    return no;
}

Arvore iniciar_arvore(){
    return malloc(TAM_HASH*sizeof(No));
}

void adicionar_adj(Arvore arvore, No *atual, No *novo){
    if(!arvore[indice_hash(atual->e)].visitado){
        int indice = atual->num_adj;
        atual->num_adj++;
        atual->adj = realloc(atual->adj, atual->num_adj * sizeof(int));
        atual->adj[indice] = indice_hash(novo->e);
        novo->visitado = 1;
    }
}
