
#include "../include/abbLibros.h"

struct rep_abbLibros {
    TLibro libro;
    rep_abbLibros *izq, *der;
};

TABBLibros crearTABBLibrosVacio(){
    return NULL;
}

void insertarLibroTABBLibros(TABBLibros &abbLibros, TLibro libro){
    //caso base: una vez que encontramos el lugar correcto lo insertamos
    //este caso base cubre que el arbol sea null de entrada no entra a la recursion de abajo, directamente crea el nodo y finaliza la funcion  
    if (abbLibros == NULL) {
        abbLibros = new rep_abbLibros;
        abbLibros->libro = libro;
        abbLibros->der = NULL;
        abbLibros->izq = NULL;
        return;
    } 

    //buscamos el lugar correcto para el nodo nuevo
    //si el isbn del libro del arbol es mayor debo buscar a la izquierda (a la izquierda estan siempre los mas chicos)
    if (isbnTLibro(abbLibros->libro) > isbnTLibro(libro)) {
        insertarLibroTABBLibros(abbLibros->izq, libro);
    //en caso contrario al ser mayor buscamos por la derecha (derecha estan los mas grandes)
    } else if (isbnTLibro(abbLibros->libro) < isbnTLibro(libro)) {
        insertarLibroTABBLibros(abbLibros->der, libro);
    }
}

void imprimirTABBLibros(TABBLibros abbLibros){
    if (abbLibros != NULL) {
        imprimirTABBLibros(abbLibros->izq); //imprime todo izquierda en orden
        imprimirTLibro(abbLibros->libro); //la raiz (nodo del medio)
        imprimirTABBLibros(abbLibros->der); //todo derecha en orden
    }
}

void liberarTABBLibros(TABBLibros &abbLibros){
    if (abbLibros != NULL) {
        liberarTABBLibros(abbLibros->izq); //libera toda la parte izquierda
        liberarTABBLibros(abbLibros->der); //libera toda la derecha
        liberarTLibro(abbLibros->libro); //por ultimo libera la raiz (si la eliminamos al principio perderiamos la memoria de todo el arbol)
        delete abbLibros; //borramos el arbol ahora si 
        abbLibros = NULL;
    }
}

bool existeLibroTABBLibros(TABBLibros abbLibros, int isbn){
    return false;
}

TLibro obtenerLibroTABBLibros(TABBLibros abbLibros, int isbn){
    return NULL;
}

nat alturaTABBLibros(TABBLibros abbLibros){
    return 0;
}

TLibro maxISBNLibroTABBLibros(TABBLibros abbLibros){
    return NULL;
}

void removerLibroTABBLibros(TABBLibros &abbLibros, int isbn){
}

int cantidadTABBLibros(TABBLibros abbLibros){
    return 0;
}

void obtenerNesimoLibroTABBLibrosAux(TABBLibros abbLibros, int n, int &k, TLibro &res){
}

TLibro obtenerNesimoLibroTABBLibros(TABBLibros abbLibros, int n){
    return NULL;
}

//se necesita funcion auxiliar
TABBLibros filtradoPorGeneroTABBLibros(TABBLibros abbLibros, int genero) {
    return NULL;
}