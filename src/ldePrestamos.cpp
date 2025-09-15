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

    //caso donde puede ir primero en la lista:
    //el nuevo nodo pasa a ser el inicio y enganchamos el de adelante con el nuevo
    } else if (compararTFechas(fechaRetiroTPrestamo(ldePrestamos->inicio->prestamo), fechaRetiroTPrestamo(prestamo)) < 0) {
        nuevo->sig = ldePrestamos->inicio;
        ldePrestamos->inicio->prev = nuevo;
        ldePrestamos->inicio = nuevo;
    
    //caso donde hay que buscarlo en la lista si es igual o mayor
    //tomar en cuenta que no solo puede haber uno repetido si no que varios (debe ir al final de ellos uwu)
    } else {

    }


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

//con recursion sale mas facil
void imprimirTLDEPrestamos(TLDEPrestamos ldePrestamos){

}

//con recursion sale mas facil
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


