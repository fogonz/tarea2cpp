
#include "../include/lseSocios.h"

struct rep_lseSocios {
	TSocio socio;
	rep_lseSocios *sig;
};

TLSESocios crearTLSESociosVacia(){
	TLSESocios tlseSocio = new rep_lseSocios;
	tlseSocio->sig = NULL;
    return tlseSocio;
}  

bool esVaciaTLSESocios(TLSESocios lseSocios){
	if (lseSocios == NULL) {
		return false;
	} else {
		return true;
	}
}

void imprimirTLSESocios(TLSESocios lseSocios){
	printf("Lista de Socios:\n");
	rep_lseSocios* actual = lseSocios;
	while (actual != NULL){
		imprimirTSocio(actual -> socio);
		actual = actual -> sig;
	}
}

// chequear <-----------------
void liberarTLSESocios(TLSESocios &lseSocios){
    if (lseSocios == NULL) return;

    rep_lseSocios* actual = lseSocios->sig;
    while (actual != NULL){
        actual = actual->sig;
        liberarTSocio(actual->socio);
    }

    delete lseSocios;
    lseSocios = NULL;
}

void insertarTLSESocios(TLSESocios &lseSocios, TSocio socio){
}

bool existeSocioTLSESocios(TLSESocios lseSocios, int ci){
	return false;
}

TSocio obtenerSocioTLSESocios(TLSESocios lseSocios, int ci){
    return NULL;
}

TSocio obtenerNesimoTLSESocios(TLSESocios lseSocios, int n){
	return NULL;
}

nat cantidadTLSESocios(TLSESocios lseSocios){
	return 0;
}

void removerSocioTLSESocios(TLSESocios &lseSocios, int ci){
}