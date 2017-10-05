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
    
    No_pilha *temp = malloc(sizeof(No_pilha));
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
    No_pilha *temp = pile->top;
    pile->top = pile->top->prev; 
    free(temp);
    pile->size--;
}

void printPile(Pile *pile){
    No_pilha *temp = pile->top;
    printf("PILHA DE RESULTADOS\n");
    while(temp != NULL){
        printf("%d\n",temp->obj);
        temp = temp->prev;
    }
    free(temp);
}

void deletePile(Pile *pile){
    No_pilha *temp = pile->top;
    
    while(temp != NULL){
        No_pilha *temp2 = temp;
        temp = temp->prev;
        free(temp2);
    }
    free(temp);
}