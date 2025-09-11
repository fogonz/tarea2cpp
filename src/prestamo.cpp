
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
  imprimirTFecha(prestamo -> fechaDevolucion);
}

void liberarTPrestamo(TPrestamo &prestamo){
}

TSocio socioTPrestamo(TPrestamo prestamo){
  return NULL;
}
 
TFecha fechaRetiroTPrestamo(TPrestamo prestamo){
  return NULL;
}

TFecha fechaDevolucionTPrestamo(TPrestamo prestamo){
  return NULL;
}

TLibro libroTPrestamo(TPrestamo prestamo){
  return NULL;
}

bool fueRetornadoTPrestamo(TPrestamo prestamo){
  return false;
}

void actualizarFechaDevolucionTPrestamo(TPrestamo prestamo, TFecha fechaDevolucion){
}

TPrestamo copiarTPrestamo(TPrestamo prestamo){
  return NULL;
}