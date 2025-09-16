#include "../include/fecha.h"

struct rep_fecha {
    /************ Parte 2.1 ************/
    /*Escriba el código a continuación */
    nat dia, mes, anio;
    /****** Fin de parte Parte 2.1 *****/
};

TFecha crearTFecha(nat dia, nat mes, nat anio) {
    TFecha nuevaFecha = NULL;
    /************ Parte 3.1 ************/
    /*Escriba el código a continuación */
    nuevaFecha = new rep_fecha;
    nuevaFecha -> dia = dia;
    nuevaFecha -> mes = mes;
    nuevaFecha -> anio = anio;
    /****** Fin de parte Parte 3.1 *****/
    return nuevaFecha;
}

void liberarTFecha(TFecha &fecha) {
    /************ Parte 3.3 ************/
    /*Escriba el código a continuación */
        if (fecha != NULL) {
        delete fecha;
        fecha = NULL;
    }
    /****** Fin de parte Parte 3.3 *****/
}
void imprimirTFecha(TFecha fecha) {
    /************ Parte 3.5 ************/
    /*Escriba el código a continuación */
    if (fecha != NULL) { 
        printf("%u/%u/%u\n", fecha->dia, fecha->mes, fecha->anio);
    }
    /****** Fin de parte Parte 3.5 *****/
    
}

TFecha copiarTFecha(TFecha fecha) {
    /************ Parte 3.9 ************/
    /*Escriba el código a continuación */
    /*Recuerde que las funciones auxiliares
     deben declararse antes de ser utilizadas*/
    TFecha copia = new rep_fecha;
    copia -> dia = fecha -> dia;
    copia -> mes = fecha -> mes;
    copia -> anio = fecha -> anio;
 
    return copia;
    /****** Fin de parte Parte 3.9 *****/
}

static nat diasMes(nat mes, nat anio){
    //Declaracion de array para asignar un numero especifico de dias a cada mes
    nat mesDias[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (anio % 4 == 0 ){
        if ((anio % 100 != 0) || (anio % 100 == 0 && anio % 400 == 0)){
            mesDias[1] = 29;
        }
    }
    nat dias = mesDias[mes-1];
    return dias;
}

void aumentarTFecha(TFecha &fecha, nat dias) {
    /************ Parte 3.10 ************/
    /*Escriba el código a continuación */
    fecha->dia += dias;
    while (fecha->dia > diasMes(fecha->mes, fecha->anio)) {
        fecha->dia -= diasMes(fecha->mes, fecha->anio);
        fecha->mes++;
        if (fecha->mes > 12) {
            fecha->mes = 1;
            fecha->anio++;
        }
    }
}
    /****** Fin de parte Parte 3.10 *****/

int compararTFechas(TFecha fecha1, TFecha fecha2) {
    int res = 0;
    /************ Parte 3.11 ************/
    /*Escriba el código a continuación */
    if (fecha1 -> anio > fecha2 -> anio) {
        res = 1;
    } else if (fecha1 -> anio < fecha2 -> anio) {
        res = -1;
    } else {
        if (fecha1 -> mes > fecha2 -> mes) {
            res = 1;
        } else if (fecha1 -> mes < fecha2 -> mes) {
            res = -1;
        } else {
            if (fecha1 -> dia > fecha2 -> dia) {
                res = 1;
            } else if (fecha1 -> dia < fecha2 -> dia) {
                res = -1;
            }
        }
    }
    /****** Fin de parte Parte 3.11 *****/
    return res;
}
