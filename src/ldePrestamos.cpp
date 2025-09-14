#include "../include/ldePrestamos.h"

struct nodoDoble{
    TPrestamo prestamo;
    nodoDoble *sig;
    nodoDoble *prev;
};

struct rep_ldePrestamos {
    nodoDoble *inicio;
    nodoDoble *fin;
};

TLDEPrestamos crearTLDEPrestamosVacia(){
    TLDEPrestamos nuevo = new rep_ldePrestamos;
    nuevo -> inicio = NULL;
    nuevo -> fin = NULL;

    return nuevo;
}

void insertarTLDEPrestamos(TLDEPrestamos &ldePrestamos, TPrestamo prestamo){
}

void liberarTLDEPrestamos(TLDEPrestamos &ldePrestamos){
    if (ldePrestamos == NULL){ return; }

    nodoDoble *actual = ldePrestamos->inicio;
    while (actual != NULL){
        nodoDoble *siguiente = actual->sig;
        liberarTPrestamo(actual->prestamo);
		delete(actual);
        actual = siguiente;
    }

    delete ldePrestamos;
    ldePrestamos = NULL;
}

void imprimirTLDEPrestamos(TLDEPrestamos ldePrestamos){
}

void imprimirInvertidoTLDEPrestamos(TLDEPrestamos ldePrestamos){
}

nat cantidadTLDEPrestamos(TLDEPrestamos ldePrestamos){
    return 0;
}

TPrestamo obtenerPrimeroTLDEPrestamos(TLDEPrestamos ldePrestamos){
    return NULL;
}

TPrestamo obtenerUltimoTLDEPrestamos(TLDEPrestamos ldePrestamos){
    return NULL;
}

TPrestamo obtenerNesimoTLDEPrestamos(TLDEPrestamos &ldePrestamos, int n){
    return NULL;
}

// criterio = 0 -> prestamos retornados
// criterio = 1 -> prestamos no retornados
TLDEPrestamos filtrarPrestamosTLDEPrestamos(TLDEPrestamos &ldePrestamos, int criterio){
    return NULL;
}


