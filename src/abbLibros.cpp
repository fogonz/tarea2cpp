
#include "../include/abbLibros.h"

struct rep_abbLibros {
    TLibro libro;
    rep_abbLibros *izq, *der;
};

// Función para crear un nuevo abb de libros vacío.
// Devuelve un nuevo árbol binario de búsqueda vacío.
/* Requisitos específicos de la implementación solicitada: */
// La funcion es O(1) peor caso.
TABBLibros crearTABBLibrosVacio(){
    TABBLibros arbol = NULL;
}

//test 1 y 2
void insertarLibroTABBLibros(TABBLibros &abbLibros, TLibro libro){
}

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