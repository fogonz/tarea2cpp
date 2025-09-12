
#include "../include/prestamo.h"

struct rep_prestamo {
  TSocio prestamoSocio;
  TLibro prestamoLibro;
  TFecha fechaRetiro;
  TFecha fechaDevolucion;
};

TPrestamo crearTPrestamo(TSocio socio, TLibro libro, TFecha fechaRetiro){
  TPrestamo prestamoNuevo = new rep_prestamo;
  prestamoNuevo -> prestamoSocio = socio;
  prestamoNuevo -> prestamoLibro = libro;
  prestamoNuevo -> fechaRetiro = fechaRetiro;

  return prestamoNuevo;
}

void imprimirTPrestamo(TPrestamo prestamo){
  printf("Préstamo de libro %s a %s %s.\n", tituloTLibro(prestamo -> prestamoLibro), nombreTSocio(prestamo -> prestamoSocio), apellidoTSocio(prestamo -> prestamoSocio));
  imprimirTFecha(prestamo -> fechaRetiro);
  if (prestamo -> fechaDevolucion == NULL){
    printf("No retornado\n"); 
  } else {
    imprimirTFecha(prestamo -> fechaDevolucion);
  }
}

void liberarTPrestamo(TPrestamo &prestamo){
  if (prestamo != NULL) {
    liberarTSocio(prestamo->prestamoSocio);
    liberarTLibro(prestamo->prestamoLibro);
    liberarTFecha(prestamo->fechaRetiro);
    liberarTFecha(prestamo->fechaDevolucion);
    delete prestamo;
    prestamo = NULL;
  }
}

TSocio socioTPrestamo(TPrestamo prestamo){
  return prestamo -> prestamoSocio;
}
 
TFecha fechaRetiroTPrestamo(TPrestamo prestamo){
  return prestamo -> fechaRetiro;
}

TFecha fechaDevolucionTPrestamo(TPrestamo prestamo){
  return prestamo -> fechaDevolucion;
}

TLibro libroTPrestamo(TPrestamo prestamo){
  return prestamo -> prestamoLibro;
}

bool fueRetornadoTPrestamo(TPrestamo prestamo){
  if (prestamo -> fechaDevolucion != NULL){
    return true;
  } else {
    return false;
  }
}

void actualizarFechaDevolucionTPrestamo(TPrestamo prestamo, TFecha fechaDevolucion){
}

TPrestamo copiarTPrestamo(TPrestamo prestamo){
  TPrestamo copiaPrestamo = new rep_prestamo;
  copiaPrestamo->prestamoSocio = copiarTSocio(prestamo->prestamoSocio);
  copiaPrestamo->prestamoLibro = copiarTLibro(prestamo->prestamoLibro);
  copiaPrestamo->fechaRetiro = copiarTFecha(prestamo->fechaRetiro);
  if (prestamo->fechaDevolucion != NULL) {
    copiaPrestamo->fechaDevolucion = copiarTFecha(prestamo->fechaDevolucion);
  }
  
  return copiaPrestamo;
}