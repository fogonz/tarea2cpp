#include "../include/ldePrestamos.h"

struct nodoDoble{
    TPrestamo prestamo;
    nodoDoble *sig;
    nodoDoble *prev;
};

struct rep_ldePrestamos {
    nodoDoble *inicio;
    nodoDoble *fin;
    nat cantidad;
};

TLDEPrestamos crearTLDEPrestamosVacia(){
    TLDEPrestamos nuevo = new rep_ldePrestamos;
    nuevo -> inicio = NULL;
    nuevo -> fin = NULL;
    nuevo -> cantidad = 0;
    
    return nuevo;
};

void insertarTLDEPrestamos(TLDEPrestamos &ldePrestamos, TPrestamo prestamo){ 
    //creamos el nodo a insertar antes que todo para no tener que crearlo en cada if
    nodoDoble *nuevo = new nodoDoble;
    nuevo->prestamo = prestamo;
    nuevo->sig = NULL;
    nuevo->prev = NULL;

    //caso que la lista es vacia le agregamos el unico prestamo:
    //la lista pasa a apuntar al nodo nuevo y lo asignamos como primer y ultimo nodo
    if (ldePrestamos->inicio == NULL) {
        ldePrestamos->inicio = nuevo;
        ldePrestamos->fin = nuevo;
        ldePrestamos->cantidad++;

    //caso donde puede ir primero en la lista:
    //el nuevo nodo pasa a ser el inicio y enganchamos el de adelante con el nuevo
    } else if (compararTFechas(fechaRetiroTPrestamo(prestamo), fechaRetiroTPrestamo(ldePrestamos->inicio->prestamo)) < 0) {
        nuevo->sig = ldePrestamos->inicio;
        ldePrestamos->inicio->prev = nuevo;
        ldePrestamos->inicio = nuevo;
        ldePrestamos->cantidad++;
    
    //caso donde hay que buscarlo en la lista si es igual o mayor
    //tomar en cuenta que no solo puede haber uno repetido si no que varios (debe ir al final de ellos uwu)
    } else {
        nodoDoble* actual = ldePrestamos->inicio;
        while (actual->sig != NULL && compararTFechas(fechaRetiroTPrestamo(actual->sig->prestamo), fechaRetiroTPrestamo(prestamo)) <= 0) {
            actual = actual->sig;
        }

        nuevo->sig = actual->sig;
        nuevo->prev = actual;

        if (actual->sig != NULL) {
            actual->sig->prev = nuevo;
        } else {
            ldePrestamos->fin = nuevo; //como es null pasa a ser el ultimo de la lista
        }

        actual->sig = nuevo;
        ldePrestamos->cantidad++;
    }
};

void liberarTLDEPrestamos(TLDEPrestamos &ldePrestamos){
    if (ldePrestamos == NULL){ return; }

    nodoDoble *actual = ldePrestamos->inicio;
    while (actual != NULL){
        nodoDoble *siguiente = actual->sig;
        liberarTPrestamo(actual->prestamo);
		delete(actual);
        actual = siguiente;
    }

    ldePrestamos->cantidad = 0;
    delete ldePrestamos;
    ldePrestamos = NULL;
}

void imprimirTLDEPrestamos(TLDEPrestamos ldePrestamos){
    nodoDoble* actual = ldePrestamos->inicio;
    printf("LDE Prestamos:\n");
    while (actual != NULL) {
        imprimirTPrestamo(actual->prestamo);
        actual = actual->sig;
    }
}

void imprimirInvertidoTLDEPrestamos(TLDEPrestamos ldePrestamos){
    printf("LDE Préstamos:\n");
    nodoDoble* actual = ldePrestamos->fin;
    while (actual != NULL) {
        imprimirTPrestamo(actual->prestamo);
        actual = actual->prev;
    }
}

// SI HAY DIFERERENCIAS EN LAS SALIDAS, MIRAR ESTA FUNCIÓN.
nat cantidadTLDEPrestamos(TLDEPrestamos ldePrestamos){ 
    return ldePrestamos->cantidad;
}

TPrestamo obtenerPrimeroTLDEPrestamos(TLDEPrestamos ldePrestamos){
    if (ldePrestamos != NULL) {
        return ldePrestamos->inicio->prestamo;
    } else {
        return NULL;
    }
}

TPrestamo obtenerUltimoTLDEPrestamos(TLDEPrestamos ldePrestamos){
    if (ldePrestamos != NULL) {
        return ldePrestamos->fin->prestamo;
    } else {
        return NULL;
    }
    
}

TPrestamo obtenerNesimoTLDEPrestamos(TLDEPrestamos &ldePrestamos, int n){
    if (n > 0 && (nat)n <= ldePrestamos->cantidad) {
        int contador = 1;
        nodoDoble *actual = ldePrestamos->inicio; 
        while (contador != n){
            contador++;
            actual = actual->sig;
        }
        return actual->prestamo;
    } else {
        return NULL;
    }
}

// Función que retorna una nueva lista únicamente con los préstamos
// que cumplen el criterio pasado por parámetro.
// La lista filtrada no comparte memoria con la lista original
// Los préstamos retornados en la nueva lista son copias limpias
// de los que pertenecen a la lista parámetro.
// criterio = 0 -> préstamos retornados
// criterio = 1 -> préstamos no retornados
//
/* Requisitos específicos de la implementación solicitada: */
// La funcion es O(n) peor caso, siendo n la cantidad de préstamos en la lista árbol.
TLDEPrestamos filtrarPrestamosTLDEPrestamos(TLDEPrestamos &ldePrestamos, int criterio){
    TLDEPrestamos nueva = new rep_ldePrestamos;
    nueva -> inicio = NULL;
    nueva -> fin = NULL;
    nueva -> cantidad = 0;
    
    nodoDoble* actual = ldePrestamos->inicio;
    while (actual != NULL) {
        if ((criterio == 0 && fueRetornadoTPrestamo(actual->prestamo)) || (criterio == 1 && !fueRetornadoTPrestamo(actual->prestamo))) {
            TPrestamo copia = copiarTPrestamo(actual->prestamo);
            insertarTLDEPrestamos(nueva, copia);
        }
        actual = actual->sig;
    }

    return nueva;
}


