/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on October 18, 2022, 7:05 PM
 */

#include "funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    int arr_fecha_profesores[MAX_PROFESORES]={};
    int arr_cantidad_profesores[MAX_PROFESORES]={};
    int arr_horas_profesores[MAX_PROFESORES]={};
    double arr_sueldo_profesores[MAX_PROFESORES]={};
    int cantidad_fechas=0, elemento_buscar;
    //Vamos a usar el código del ejercicio de profesores
    leer_arch_profesores(arr_fecha_profesores, 
                         arr_cantidad_profesores, 
                         arr_horas_profesores, 
                         arr_sueldo_profesores,
                         cantidad_fechas);
    
    ordenar_arreglos(arr_fecha_profesores, 
                     arr_cantidad_profesores, 
                     arr_horas_profesores, 
                     arr_sueldo_profesores,
                     cantidad_fechas);
    
    imprimir_reporte(arr_fecha_profesores, 
                     arr_cantidad_profesores, 
                     arr_horas_profesores, 
                     arr_sueldo_profesores,
                     cantidad_fechas);
    //Hasta este momento los arreglos están ordenados por fecha y por sueldo.
    //Vamos a buscar un elemento, y obtener un resumen de lo que hemos encontrado.
    elemento_buscar = 20221010;
    imprimir_busqueda(arr_fecha_profesores, 
                     arr_cantidad_profesores, 
                     arr_horas_profesores, 
                     arr_sueldo_profesores,
                     elemento_buscar,
                     cantidad_fechas);
    return 0;
}

