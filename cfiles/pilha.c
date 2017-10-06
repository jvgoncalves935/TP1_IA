#include "pilha.h"
#include "estado.h"

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
    int cont=0;
    while(temp != NULL){
        cont++;
        temp = temp->prev;
    }
    
    temp = pile->top;
    int *vetor = malloc(cont*sizeof(int));
    int i=cont;
    if(cont){
        printf("\nPILHA DE RESULTADOS\n");
        while(temp != NULL){
            vetor[i]=*((int*) temp->obj);
            i--;
            temp = temp->prev;
        }
    
        for(i=1;i<=cont;i++){
            exibir_estado(vetor[i]);
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