#include "../headers/Arvore.h"

#define MIS 3
#define CAN 3

int main(){
    Estado *e = iniciarEstado(MIS,CAN);
    //printEstado(e);
    aproximacao(e,MIS,CAN);
    return 0;
}
