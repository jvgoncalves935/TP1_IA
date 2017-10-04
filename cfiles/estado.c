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

/*
 * DEBUG
 */

void printE(Estado e){
	printf("[M%d,C%d]%c-%c[M%d,C%d]\n", e.esquerdo.mis, e.esquerdo.can,
										(e.canoa == ESQUERDO)?'>':' ', (e.canoa == DIREITO)?'<':' ',
										e.direito.mis, e.direito.can);
}
