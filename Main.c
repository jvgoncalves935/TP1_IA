#include "arvore.h"

int main(int argc, char** argv) {
	Lado l = {3, 3};
	Estado e = criar_estado(l, ESQUERDO);

	Arvore arvore = criar_arvore();

	No inicial = criar_no(e, 0);
	
	extern int total;
        int nivel_arvore=0;

	arvore[indice_hash(inicial.e)] = inicial;
	arvore[indice_hash(inicial.e)].visitado = 1;

	gerar_arvore(arvore, indice_hash(inicial.e),&nivel_arvore);

	printE(arvore[indice_hash(inicial.e)].e);
	
	printf("total: %d  nivel:%d\n", total,nivel_arvore);
        
        zerar_nodos_visitados(arvore,TAM_HASH);
        
        Lado l2 = {0,0};
        Estado solucao = criar_estado(l2,DIREITO);
        //int inicio = indice_hash(inicial.e);
        printf("\nAPROFUNDAMENTO ITERATIVO:\n\n");
        Pile *pilha = getPile();
        int valor = indice_hash(arvore[indice_hash(e)].e);
        addPile(pilha, (void *) &valor);
        printPile(pilha);
        int achou=0;
        aprofundamento_iterativo(arvore,&arvore[indice_hash(e)],indice_hash(solucao),0,pilha,&achou);
        printPile(pilha);
        
	return 0;
}
