#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#include "Tad.h"

void aproximacao(Arvore *a, No *pai, Estado *vetor_estados, int nivel);
int verificarEstado(int misEsquerdo, int canEsquerdo,int misDireito, int canDireito, int lado, No *no);
int acaoValida(int misEsquerdo, int canEsquerdo, int misDireito, int canDireito);
void printEstadoObjeto(Estado *e);
void printListaEstados(No *no);
void printEstadoObjetoNotPointer(Estado e);
void adicionarNoArvore(Arvore *a,  No *pai, No *novo_no, Estado filho, int nivel, int pos);
No *criarNo(Estado e, Estado *vetor_estados, int num_estados, int id);
void printStatus(No *pai);
void printNodosFilhos(No *pai);

#endif // ARVORE_H_INCLUDED
