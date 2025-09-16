
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

// Función para imprimir los libros del árbol en orden, según su ISBN. La impresión
// de los libros se realiza con la función 'imprimirTLibro'.
/* Requisitos específicos de la implementación solicitada: */
// La función es O(n) peor caso, donde n es la cantidad de libros en el árbol.

//test 1 y 2
void imprimirTABBLibros(TABBLibros abbLibros){
    
}

//test 1 y 2
void liberarTABBLibros(TABBLibros &abbLibros){
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

TABBLibros filtradoPorGeneroTABBLibros(TABBLibros abbLibros, int genero) {
    return NULL;
}