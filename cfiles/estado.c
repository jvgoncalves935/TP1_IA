#include "estado.h"

Estado criar_estado(Lado esquerdo, Canoa canoa){
    Estado estado;
    
    estado.esquerdo = esquerdo;
    estado.direito = calcula_lado_oposto(esquerdo);
    estado.canoa = canoa;
    
    return estado;
}

int lado_valido(Lado lado){
    if(lado.mis == 0){
        return 1;
    }
    if(lado.mis >= lado.can){
        return 1;
    }
    return 0;
}

int estado_valido(Estado estado){
    return lado_valido(estado.esquerdo) && lado_valido(estado.direito);
}

Lado calcula_lado_oposto(Lado lado){
    Lado oposto;
    
    oposto.can = MAX_C - lado.can;
    oposto.mis = MAX_M - lado.mis;
    
    return oposto;
}

int indice_hash(Estado estado){
    int hash=0;
	int r = 1;
	int *vet = (int *)&estado;
	int i;
	for(i=0; i<=4; i++){
		hash += (vet[i] * r);
		r *= 10;
	}
    return hash;
}

void exibir_estado(int indice_hash){
    int i,j,hash=indice_hash;
    int *vetor = malloc(5*sizeof(int));
    int coeficiente=4,aux=0,valor;
    
    for(i=0;i<5;i++){
        valor=1;
        for(j=0;j<coeficiente;j++){
            valor = valor*10;
        }
        //printf("valor:%d hash:%d ",valor,hash);
        while(hash>=valor){
            hash = hash - valor;
            aux++;
        }
        //printf("%d\n",hash);
        vetor[i]=aux;
        aux=0;
        coeficiente--;
    }
    
    if(!vetor[0]){
        printf("[Canoa: Esquerdo]\t");
    }else{
        printf("[Canoa: Direito]\t");
    }
    printf("Esq:[MIS:%d CAN:%d]\t\tDir:[MIS:%d CAN:%d]\n",vetor[1],vetor[2],vetor[3],vetor[4]);
    //printf("\n");
}

/*
 * DEBUG
 */

void printE(Estado e){
	printf("[M%d,C%d]%c-%c[M%d,C%d]\n", e.esquerdo.mis, e.esquerdo.can,
										(e.canoa == ESQUERDO)?'>':' ', (e.canoa == DIREITO)?'<':' ',
										e.direito.mis, e.direito.can);
}
