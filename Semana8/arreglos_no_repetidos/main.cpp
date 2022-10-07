/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on October 3, 2022, 12:59 AM
 */
#include "funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    int arr_codigo_profesores[MAX_PROFESORES]={};
    int arr_creditos_profesores[MAX_PROFESORES]={};
    int cant_profesores = 0;
    leer_arch_profesores(arr_codigo_profesores, arr_creditos_profesores, cant_profesores);
    procesar_ordenar_arreglos(arr_codigo_profesores, arr_creditos_profesores, cant_profesores);
    imprimir_reporte_profesores(arr_codigo_profesores, arr_creditos_profesores, cant_profesores);
    return 0;
}

