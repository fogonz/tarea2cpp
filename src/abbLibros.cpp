
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
    if (abbLibros == NULL) {
        return false;
    } 

    if (isbnTLibro(abbLibros->libro) < isbn) {
        return existeLibroTABBLibros(abbLibros->der, isbn);
    } else if (isbnTLibro(abbLibros->libro) > isbn) {
        return existeLibroTABBLibros(abbLibros->izq, isbn);
    } else {
        return true;
    }
}

TLibro obtenerLibroTABBLibros(TABBLibros abbLibros, int isbn){
    if (isbnTLibro(abbLibros->libro) == isbn) {
        return abbLibros->libro;
    } else {
        if (isbnTLibro(abbLibros->libro) < isbn) {
            return obtenerLibroTABBLibros(abbLibros->der, isbn);
        } else {
            return obtenerLibroTABBLibros(abbLibros->izq, isbn); 
        }
    }
}

nat alturaTABBLibros(TABBLibros abbLibros){
    if (abbLibros == NULL) {
        return 0;
    } else {
        nat alturaDer = alturaTABBLibros(abbLibros->der) + 1;
        nat alturaIzq = alturaTABBLibros(abbLibros->izq) + 1;

        if (alturaDer > alturaIzq){ 
            return alturaDer;
        } else {
            return alturaIzq;
        }
    }
}

TLibro maxISBNLibroTABBLibros(TABBLibros abbLibros){
    if (abbLibros->der == NULL) {
        return abbLibros->libro;
    } else {
        return maxISBNLibroTABBLibros(abbLibros->der);
    }
}

//funcion aux para encontrar el maximo nodo izquierdo
TABBLibros removerMaxNodoIzq(TABBLibros &l) {
    if (l->der == NULL) {
        TABBLibros maxNodo = l;
        l = l->izq;
        return maxNodo;
    } else {
        return removerMaxNodoIzq(l->der); 
    }
}

void removerLibroTABBLibros(TABBLibros &abbLibros, int isbn){
    if (isbnTLibro(abbLibros->libro) < isbn) {
        removerLibroTABBLibros(abbLibros->der, isbn);
    } else if (isbnTLibro(abbLibros->libro) > isbn) {
        removerLibroTABBLibros(abbLibros->izq, isbn);
    } else {
        //si entro a este else encontramos el isbn, toca ver que tipo de nodo es
        if (abbLibros->der == NULL) {
            //hay que borrar el grande
            TABBLibros aBorrar = abbLibros;
            abbLibros = abbLibros->izq;
            liberarTLibro(aBorrar->libro);
            delete aBorrar;
        } else if (abbLibros->izq == NULL){
            //hay que borrar el chico
            TABBLibros aBorrar = abbLibros;
            abbLibros = abbLibros->der;
            liberarTLibro(aBorrar->libro);
            delete aBorrar;
        } else {
            //caso en donde el nodo tiene los dos elementos con valores
            //debemos buscar el mayor del subarbol izquierdo (funcion aux)
            TABBLibros maxNodoIzq = removerMaxNodoIzq(abbLibros->izq);
            TLibro copia = copiarTLibro(maxNodoIzq->libro); 
            liberarTLibro(abbLibros->libro);               
            abbLibros->libro = copia;                     
            liberarTLibro(maxNodoIzq->libro);               
            delete maxNodoIzq; 
        }
    }
}

int cantidadTABBLibros(TABBLibros abbLibros){
    if (abbLibros == NULL) {
        return 0;
    } else {
        return 1 + cantidadTABBLibros(abbLibros->izq) + cantidadTABBLibros(abbLibros->der);
    }
}

// Aux para obtenerNesimoLibroTABBLibros
void obtenerNesimoLibroTABBLibrosAux(TABBLibros abbLibros, int n, int &k, TLibro &res){
    if (abbLibros == NULL) return;
    
    obtenerNesimoLibroTABBLibrosAux(abbLibros->izq, n, k, res);
    k++;

    if (k == n) res = abbLibros->libro;
        obtenerNesimoLibroTABBLibrosAux(abbLibros->der, n, k, res);
}

TLibro obtenerNesimoLibroTABBLibros(TABBLibros abbLibros, int n){
    int k = 0;
    TLibro res = NULL;
    obtenerNesimoLibroTABBLibrosAux(abbLibros, n, k, res);
    return res;
}

//funcion auxiliar para insertar filtrado
void insertarFiltrados(TABBLibros origen, TABBLibros &destino) {
    if (origen == NULL) return;
    insertarFiltrados(origen->izq, destino);
    TLibro copia = copiarTLibro(origen->libro);
    insertarLibroTABBLibros(destino, copia);
    insertarFiltrados(origen->der, destino);
}

TABBLibros filtradoPorGeneroTABBLibros(TABBLibros abbLibros, int genero) {
    if (abbLibros == NULL) return NULL;
    TABBLibros nuevo = crearTABBLibrosVacio();

    if (idGeneroTLibro(abbLibros->libro) == genero) {
        TLibro copia = copiarTLibro(abbLibros->libro);
        insertarLibroTABBLibros(nuevo, copia);
    }

    TABBLibros izq = filtradoPorGeneroTABBLibros(abbLibros->izq, genero);
    TABBLibros der = filtradoPorGeneroTABBLibros(abbLibros->der, genero);

    insertarFiltrados(izq, nuevo);
    insertarFiltrados(der, nuevo);

    liberarTABBLibros(izq);
    liberarTABBLibros(der);

    return nuevo;
}