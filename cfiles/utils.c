#include "utils.h"

int potencia_10(int expoente){
    int i,soma=1;
    for(i=0;i<expoente;i++){
        soma = soma*10;
    }
    return soma;
}