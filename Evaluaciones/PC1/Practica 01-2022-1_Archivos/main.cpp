/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 6 de septiembre de 2022, 19:04
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Funciones.hpp"

using namespace std;

/*
 * Este programa resuelve la PC1 del ciclo 2022-1
 */
int main(int argc, char** argv) {
    
    int productoConDescuento, codigoPaisConImpuestos;
    double descuentoA, descuentoB, descuentoC, descuentoProducto, impuestoPais;
    
    ifstream archVentas("Ventas.txt", ios::in);
    if(not archVentas.is_open()){
        cout << "ERROR: El archivo Ventas.txt no pudo abrirse" << endl;
        exit(1);
    }
    ofstream archReporte("IngresosPorVentasMarzo2022.txt", ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: El archivo IngresosPorVentasMarzo2022.txt no pudo abrirse" 
                << endl;
        exit(1);
    }
    
    //imprimimos la cabecera del reporte
    imprimirCabecera(archVentas, archReporte);
    //leemos los descuentos (por categoría), los impuestos por país y los imprimimos
    leerEImprimirDescuentos(archVentas, archReporte, descuentoA, descuentoB, 
            descuentoC, productoConDescuento, descuentoProducto, 
            codigoPaisConImpuestos, impuestoPais);
    //imprimimos el resto del reporte (lee todos los pedidos)
    imprimirReporte(archVentas, archReporte, descuentoA, descuentoB, 
            descuentoC, productoConDescuento, descuentoProducto, 
            codigoPaisConImpuestos, impuestoPais);
    
    return 0;
}

/*En el main.cpp
  Solo hay 3 bloques
 -Declaración de archivos
 -Llamada de lectura
 -Llamada de reporte*/

/*Máximo 30 líneas por procedimiento (función)*/
