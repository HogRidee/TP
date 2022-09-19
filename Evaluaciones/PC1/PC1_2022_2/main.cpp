/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 14 de septiembre de 2022, 14:51
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "Funciones.hpp"

using namespace std;

/*
 * ESTE PROGRAMA RESUELVE LA PC1 DEL 2022-2
 */
int main(int argc, char** argv) {
    
    ifstream archLectura("Precipitaciones.txt", ios::in);
    if(not archLectura.is_open()){
        cout << "ERROR: El archivo Precipitaciones.txt no pudo abrirse" << endl;
        exit(1);
    }
    ofstream archReporte("Reporte.txt", ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: El archivo Reporte.txt no pudo abrirse" << endl;
        exit(1);
    }
    
    leerImprimirArchivos(archLectura, archReporte);
    
    
    
    return 0;
}

