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
    hash+=potencia_10(4)*estado.canoa;
    hash+=potencia_10(3)*estado.esquerdo.mis;
    hash+=potencia_10(2)*estado.esquerdo.can;
    hash+=potencia_10(1)*estado.direito.mis;
    hash+=potencia_10(0)*estado.direito.can;
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
