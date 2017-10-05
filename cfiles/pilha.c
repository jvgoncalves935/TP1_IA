#include "pilha.h"

Pile *getPile(){
        
    Pile *temp = malloc(sizeof(Pile));
    temp->size = 0;
    temp->top = NULL;
    return temp;
}

int isEmpty(Pile *head){
    
    if(head->size){
        
        return 0;
    }
    return 1;
}

void addPile(Pile *pile, void *obj){
    
    No *temp = malloc(sizeof(No));
    temp->obj = obj;
    if(isEmpty(pile)){
        
        temp->prev = NULL;
        pile->top = temp;        
        pile->size++;
        return;
    }
    temp->prev = pile->top;
    pile->top = temp;
    pile->size++;    
}

void removePile(Pile *pile){
    
    if(isEmpty(pile)){
        
        return;
    }
    No *temp = pile->top;
    pile->top = pile->top->prev; 
    free(temp);
    pile->size--;
}