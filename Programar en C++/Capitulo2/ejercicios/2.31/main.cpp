/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 24 de agosto de 2022, 10:10
 */

#include <iostream>
#include <iomanip>

using namespace std;

/*
 * Este programa resuelve los ejercicios 2.31
 */
int main(int argc, char** argv) {
    
    int kmRecorridosDia = 0;
    int costoLitroGasolina = 0;
    int promedioKmDia = 0;
    int cuotasEstacionamientoDia = 0;
    int peajeDia = 0;
    
    cout << "Ingrese los kilometros recorridos por dia: ";
    cin  >> kmRecorridosDia;
    cout << "Ingrese el costo de gasolina por litro del dia: ";
    cin  >> costoLitroGasolina;
    cout << "Ingrese el promedio de kilometros por litro al dia: ";
    cin  >> promedioKmDia;
    cout << "Ingrese las cuotas de estacionamiento por dia: ";
    cin  >> cuotasEstacionamientoDia;
    cout << "Ingrese el peaje por dia: ";
    cin  >> peajeDia;
    
    //los valores exactos (double) se verán más adelante
    int costoDiario = 0;
    int litros = 0;
    int costoLitro = 0;
    
    litros = kmRecorridosDia / promedioKmDia;
    costoLitro = costoLitroGasolina * litros;
    costoDiario = costoLitro + peajeDia + cuotasEstacionamientoDia;
    
    return 0;
}

