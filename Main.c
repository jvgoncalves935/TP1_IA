#include "arvore.h"

int main(int argc, char** argv) {
	Lado l = {3, 3};
	Estado e = criar_estado(l, ESQUERDO);

	Arvore arvore = criar_arvore();

	No inicial = criar_no(e, 0);
	
	extern int total;

	arvore[indice_hash(inicial.e)] = inicial;
	arvore[indice_hash(inicial.e)].visitado = 1;

	gerar_arvore(arvore, indice_hash(inicial.e));

	printE(arvore[indice_hash(inicial.e)].e);
	
	printf("total: %d\n", total);

	return 0;
}
