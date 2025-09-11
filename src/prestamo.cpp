
#include "../include/prestamo.h"

struct rep_prestamo {
  TSocio prestamoSocio;
  TLibro prestamoLibro;
  TFecha fechaRetiro;
  TFecha fechaDevolucion;
};

TPrestamo crearTPrestamo(TSocio socio, TLibro libro, TFecha fechaRetiro){
  return NULL;
}
 
void imprimirTPrestamo(TPrestamo prestamo){
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