/* 
 * File:   main.cpp
 * Author: IVAN ALEXANDER ARAOZ ANDRADE 20201216
 *
 * Created on 3 de octubre de 2022, 01:03 PM
 */

#include <cstdlib>

using namespace std;

#include "Funciones.hpp"

#define MAXPACIENTES 100

/*
 * ESTE PROGRAMA RESUELVE EL LAB 3 DEL CICLO 2022-2
 */
int main(int argc, char** argv) {

    //declaracion
    int arrDni[MAXPACIENTES], arrCantCitas[MAXPACIENTES]= {0}, nPacientes = 0;           
    double arrTiempo[MAXPACIENTES]={0.0}, arrGasto[MAXPACIENTES]={0.0}, tarifaA, tarifaB, 
            tarifaC;
    //lectura
    leerCitas(tarifaA, tarifaB, tarifaC, nPacientes, arrDni, arrCantCitas, 
            arrTiempo, arrGasto);
    //procesamiento
    ordenarArreglos(arrDni, arrCantCitas, nPacientes, arrTiempo, arrGasto);
    //impresion
    imprimirReporte(arrDni, arrCantCitas, nPacientes, arrTiempo, arrGasto);
    
    return 0;
}

