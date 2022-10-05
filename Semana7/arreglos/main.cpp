/* 
 * File:   main.cpp
 * Author: u_eeggcc
 *
 * Created on 23 de septiembre de 2022, 07:02 AM
 */

/*
 * 
 */

#define maxElements 20
#include "funciones.hpp"
int main(int argc, char** argv) {
    int arr_int[20];
    double arr_doubles[maxElements] = {};
    char arr_char[maxElements];
    bool arr_boolean[maxElements];
    
    int ndatos = 0;
    int cantidad_datos = 0;
  
    int arr_int_2[maxElements];
    double arr_double_2[maxElements];
  
    //lecturaArchivoInput(arr_int, arr_doubles, arr_char, arr_boolean, ndatos);
    lecturaArchivoSearch(arr_int_2, arr_double_2, cantidad_datos);
    procesarDatos(arr_int_2,arr_double_2,cantidad_datos);
    actualizarInformacion(arr_int_2,arr_double_2,cantidad_datos);
    imprimirordenado(arr_int_2, arr_double_2,cantidad_datos);
    actualizarInformacionEspecifica(arr_int_2,cantidad_datos,101010);
    //imprimirreporte(arr_int, arr_doubles, arr_char, arr_boolean, ndatos);
    imprimirordenado(arr_int_2, arr_double_2,cantidad_datos);
    return 0;
}

