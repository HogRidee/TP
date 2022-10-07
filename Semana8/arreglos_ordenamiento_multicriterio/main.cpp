
/* 
 * File:   main.cpp
 * Author: u_eeggcc
 *
 * Created on 7 de octubre de 2022, 07:04 AM
 */
#include "funciones.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
    int arr_fechas_profesores[MAX_FECHAS]={};
    int arr_cantidad_profesores[MAX_FECHAS]={};
    int arr_horas_profesores[MAX_FECHAS]={};
    double arr_sueldos_profesores[MAX_FECHAS]={};
    int cantidad_fechas = 0;
    leer_archivo_profesores(arr_fechas_profesores, 
                            arr_cantidad_profesores,
                            arr_horas_profesores,
                            arr_sueldos_profesores,
                            cantidad_fechas);
    ordenar_arreglos(arr_fechas_profesores, 
                     arr_cantidad_profesores,
                     arr_horas_profesores,
                     arr_sueldos_profesores,
                     cantidad_fechas);
    imprimir_reporte(arr_fechas_profesores, 
                     arr_cantidad_profesores,
                     arr_horas_profesores,
                     arr_sueldos_profesores,
                     cantidad_fechas);
    return 0;
}

