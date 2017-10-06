#ifndef pilha_H
#define pilha_H

#include <stdio.h>
#include <stdlib.h>

typedef struct no_pilha *pointer;

typedef struct no_pilha {
    
    void *obj;
    pointer prev; 
}No_pilha;



typedef struct pile {
    
    pointer top;
    int size;
} Pile;

Pile *getPile();

int isEmpty(Pile *head);

void addPile(Pile *pile, void *obj);

void removePile(Pile *pile);

void printPile(Pile *pile);

void deletePile(Pile *pile);

#endif