#include "../headers/Arvore.h"

#define MIS 3
#define CAN 3

int main(){
    Estado *e = iniciarEstado(MIS,CAN);
    //printEstado(e);
    int *lado=0;
    aproximacao(e,MIS,CAN,lado);
    return 0;
}
