#ifndef pilha_H
#define pilha_H

#include <stdio.h>
#include <stdlib.h>

typedef struct no *pointer;

typedef struct no {
    
    void *obj;
    pointer prev; 
}No;



typedef struct pile {
    
    pointer top;
    int size;
} Pile;

Pile *getPile();

int isEmpty(Pile *head);

void addPile(Pile *pile, void *obj);

void removePile(Pile *pile);

#endif