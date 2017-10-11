#include "pilha.h"

Pile *newPile(){
        
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
    
    temp = pile->top;
    int *vetor = malloc(pile->size*sizeof(int));
    int i=pile->size-1;
    if(i>0){
        printf("\nPILHA DE RESULTADOS\n");
        while(temp != NULL){
            vetor[i]=*((int*) temp->obj);
            i--;
            temp = temp->prev;
        }
    
        for(i=0;i<pile->size;i++){
            printE(criar_estado_de_hash(vetor[i]));
        }
    }else{
        printf("\nPILHA VAZIA!\n");
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