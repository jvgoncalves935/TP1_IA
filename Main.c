#include "busca.h"

int main(int argc, char** argv) {
	
	int escolha;
	printf(	"Escolha uma opcao\n\n"
			"0. Sair\n"
			"1. Aprofundamento Iterativo\n"
			"2. Aprofundamento Iterativo Recursivo\n"
			"3. Busca Bi-Direcional\n"
			"Escolha: ");
	scanf("%d", &escolha);
	
	switch(escolha){
		case 0:
			break;
		case 1:
			busca_aprofundamento_iterativo();
			break;
		case 2:
			busca_aprofundamento_iterativo_recursivo();
			break;
		case 3:
			busca_bi_direcional();
			break;
		default:
			printf("Escolha invalida.\n");
			break;
	}
	return 0;
}
