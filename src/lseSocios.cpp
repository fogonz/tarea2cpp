
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

	rep_lseSocios* actual;
    while (lseSocios != NULL){
        actual = lseSocios;
		lseSocios = lseSocios->sig;
        liberarTSocio(actual->socio);
		delete(actual);
    }
}

void insertarTLSESocios(TLSESocios &lseSocios, TSocio socio){
}

bool existeSocioTLSESocios(TLSESocios lseSocios, int ci){
	rep_lseSocios* actual = lseSocios;
	while (actual != NULL && ciTSocio(actual->socio) != ci) {
		actual = actual->sig;
	}

	return actual != NULL;
}

TSocio obtenerSocioTLSESocios(TLSESocios lseSocios, int ci){
	if (existeSocioTLSESocios(lseSocios, ci) == true) {
		rep_lseSocios* actual = lseSocios;
		while (ciTSocio(actual->socio) != ci) {
			actual = actual->sig;
		}
    	return actual->socio;
	}
	return NULL;
}

TSocio obtenerNesimoTLSESocios(TLSESocios lseSocios, int n){
	if (n > 0 && (nat)n <= cantidadTLSESocios(lseSocios)) {
		int cont = 1;
		rep_lseSocios* actual = lseSocios;
		while (cont != n) {
			actual = actual->sig;
			cont++;
		}

		return actual->socio;
	}

	return NULL;
}

nat cantidadTLSESocios(TLSESocios lseSocios){
	nat cantidadSocios = 0;
	rep_lseSocios* actual = lseSocios;
	while (actual != NULL) {
		actual = actual->sig;
		cantidadSocios++;
	}

	return cantidadSocios;
}

void removerSocioTLSESocios(TLSESocios &lseSocios, int ci){
	if (existeSocioTLSESocios(lseSocios, ci) == true) {
		//si el primer nodo es el buscado, directamente lo borramos 
		if (ciTSocio(lseSocios->socio) == ci) {
			rep_lseSocios* actual = lseSocios;
			lseSocios = lseSocios->sig;
			liberarTSocio(actual->socio);
			delete actual;
		} else {
			//si no era el primero no queda de otra que buscarlo
			rep_lseSocios* busqueda = lseSocios->sig;
			rep_lseSocios* anterior = lseSocios;
			while (ciTSocio(busqueda->socio) != ci) {
				busqueda = busqueda->sig;
				anterior = anterior->sig;
			}
			anterior->sig = busqueda->sig;
			liberarTSocio(busqueda->socio);
			delete busqueda;
		}	
	}
}
