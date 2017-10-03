#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#include "Tad.h"

void aproximacao(Arvore *a, No *pai, Estado *vetor_estados, int nivel);
void gerarEstados();
int verificarEstado(int misEsquerdo, int canEsquerdo,int misDireito, int canDireito, int lado, No *no, int nivel, int pos);
int acaoValida(int misEsquerdo, int canEsquerdo, int misDireito, int canDireito);
void printEstadoObjeto(Estado *e);
void printListaEstados(No *no);
void printEstadoObjetoNotPointer(Estado e);
void adicionarNoArvore(Arvore *a,  No *pai, No *novo_no, Estado *filho, int nivel, int pos);
No *criarNo(Estado *e, Estado *vetor_estados, int num_estados, int id);
void printNodosFilhos(No *pai);


#endif // ARVORE_H_INCLUDED
