#include "../include/libro.h"

struct rep_libro {
    int isbn;
    char titulo[MAX_TITULO];
    char nombreAutor[MAX_NOMBRE_AUTOR];
    char apellidoAutor[MAX_APELLIDO_AUTOR];
    char descripcion[MAX_DESCRIPCION];
    int idGeneroLibro;
    TFecha fechaEdicion;
};

// Crea y retorna un elemento de tipo TLibro con los valores dados
TLibro crearTLibro(int isbn, const char titulo[MAX_TITULO], const char nombreAutor[MAX_NOMBRE_AUTOR], const char apellidoAutor[MAX_APELLIDO_AUTOR], const char descripcion[MAX_DESCRIPCION], int idGeneroLibro, TFecha fechaEdicion){
    TLibro libro = new rep_libro;
    
    libro->isbn = isbn;
    strcpy(libro->titulo, titulo);
    strcpy(libro->nombreAutor, nombreAutor);
    strcpy(libro->apellidoAutor, apellidoAutor);
    strcpy(libro->descripcion, descripcion);
    libro->idGeneroLibro = idGeneroLibro;
    libro->fechaEdicion = fechaEdicion;

    return libro;
}

// Libera la memoria asignada para el libro 'l'
// Debe liberar también la memoria de la fecha asociada
void liberarTLibro(TLibro &l){
    if (l != NULL) {
        liberarTFecha(l->fechaEdicion);
        delete l;
        l = NULL;

    }
}

// Retorna el isbn del libro 'l'
int isbnTLibro(TLibro l){
        return l->isbn;
}

// Retorna el titulo del libro 'l'
// El titulo retornado comparte memoria con el parámetro. 
char* tituloTLibro(TLibro l){
    return l->titulo;
}


// Retorna la descripción del libro 'l'
// La descripción retornada comparte memoria con el parámetro. 
char* descripcionTLibro(TLibro l){
    return l->descripcion; 
}

// Retorna el nombre del autor del libro 'l'
// El nombre retornado comparte memoria con el parámetro. 
char* nombreAutorTLibro(TLibro l){
    return l->nombreAutor;
}

// Retorna el apellido del autor del libro 'l'
// El apellido retornado comparte memoria con el parámetro. 
char* apellidoAutorTLibro(TLibro l){
    return l->apellidoAutor;
}

// Retorna el id del género del libro 'l'
int idGeneroTLibro(TLibro l){
    return l->idGeneroLibro;
}

// Retorna la fecha de edición del libro 'l'.
// La fecha retornada comparte memoria con el parámetro. 
TFecha fechaEdicionTLibro(TLibro l){
    return l->fechaEdicion;
}

// Imprime la información del libro 'l' en el siguiente formato:
// Libro <isbn> 
// Título: <título>
// Autor: <nombre autor> <apellido autor>
// Descripción: <descripcion>
// Género: <id género>
// Fecha de edición: <fecha de edición>
void imprimirTLibro(TLibro l){
    printf("Libro %d\nTítulo: %s\nAutor: %s %s\nDescripción: %s\nGénero: %d\nFecha de edición: ", l->isbn, l->titulo, l->nombreAutor, l->apellidoAutor, l->descripcion, l->idGeneroLibro);
    imprimirTFecha(l->fechaEdicion);
}

// Retorna una copia del libro 'l' que no comparte memoria con el parámetro.
TLibro copiarTLibro(TLibro l){
    if (l == NULL) { 
        return NULL;
    } else {
        TLibro copia = new rep_libro;
        copia -> isbn = l -> isbn;
        strcpy(copia->titulo, l->titulo);
        strcpy(copia->nombreAutor, l->nombreAutor);
        strcpy(copia->apellidoAutor, l->apellidoAutor);
        strcpy(copia->descripcion, l->descripcion);
        copia -> idGeneroLibro = l -> idGeneroLibro;
        copia->fechaEdicion = copiarTFecha(l->fechaEdicion);
        
        return copia; 
    }
}

