#include "../include/socio.h"

struct generosFavoritos {
    int genero[MAX_GENEROS_FAVORITOS];
    int tope;
};

struct rep_socio {
    int ci;
    char nombre [MAX_NOMBRE_SOCIO];
    char apellido [MAX_APELLIDO_SOCIO];
    TFecha fechaAlta;
    generosFavoritos generos;
};

TSocio crearTSocio(int ci, const char nombre[MAX_NOMBRE_SOCIO], const char apellido[MAX_APELLIDO_SOCIO], nat diaAlta, nat mesAlta, nat anioAlta){
    TSocio nuevoSocio = new rep_socio;
    nuevoSocio->ci = ci;
    strcpy(nuevoSocio->nombre, nombre);
    strcpy(nuevoSocio->apellido, apellido);
    nuevoSocio->fechaAlta = crearTFecha(diaAlta, mesAlta, anioAlta);
    
    //inicialización de arreglo genero vacio
    for (int i = 0; i < MAX_GENEROS_FAVORITOS; i++)
        nuevoSocio->generos.genero[i] = 0;
    nuevoSocio->generos.tope = 0; 
    
    return nuevoSocio;
}

void imprimirTSocio(TSocio socio){
    if (socio != NULL) {
        printf("Socio %d: %s %s\nFecha de alta: ", socio->ci, socio->nombre, socio->apellido);
        imprimirTFecha(socio->fechaAlta);
        printf("Generos favoritos: \n");
        for (int i = 0; i < socio->generos.tope; i++)
            printf("%d", socio->generos.genero[i]);
    }
}

void liberarTSocio(TSocio &socio){
    if (socio != NULL) {
        liberarTFecha(socio->fechaAlta);
        delete socio;
        socio = NULL;
    }
}

int ciTSocio(TSocio socio){
    return socio->ci;
}

char* nombreTSocio(TSocio socio){
    return socio->nombre;
}

char* apellidoTSocio(TSocio socio){
    return socio->apellido;
}

TFecha fechaAltaTSocio(TSocio socio){
    return socio->fechaAlta;
}


void agregarGeneroFavoritoTSocio(TSocio &socio, int idGenero){
    if (socio->generos.tope < MAX_GENEROS_FAVORITOS) {
        socio->generos.genero[socio->generos.tope] = idGenero;
        socio->generos.tope++;
    }
}

bool tieneGeneroFavoritoTSocio(TSocio socio, int idGenero){
    int i = 0;
    while (socio->generos.tope > i && socio->generos.genero[i] != idGenero) {
        i++;
    }

    return (socio->generos.tope > i);
}

int cantidadGenerosFavoritosTSocio(TSocio socio){
    return socio->generos.tope;
}

TSocio copiarTSocio(TSocio socio){
    TSocio copiaSocio = new rep_socio;
    copiaSocio->ci = socio->ci;
    strcpy(copiaSocio->nombre, socio->nombre);
    strcpy(copiaSocio->apellido, socio->apellido);
    copiaSocio->fechaAlta = copiarTFecha(socio->fechaAlta);

    for (int i = 0; i < socio->generos.tope; i++) {
        copiaSocio->generos.genero[i] = socio->generos.genero[i];
    }
    copiaSocio->generos.tope = socio->generos.tope;

    return copiaSocio;
}

//sexooooooooooooo