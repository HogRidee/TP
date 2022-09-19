

/* 
 * File:   main.cpp
 * Author: 20201216 Ivan Araoz
 *
 * Created on 19 de septiembre de 2022, 01:14 PM
 */

#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;

#include "Funciones.hpp"
/*
 * 
 */
int main(int argc, char** argv) {

    ifstream archMedicos("Medicos.txt", ios::in);
    if(not archMedicos.is_open()){
        cout << "ERROR: EL ARCHIVO Medicos.TXT NO PUDO ABRIRSE" << endl;
        exit(1);
    }
    ifstream archPacientes("Pacientes.txt", ios::in);
    if(not archPacientes.is_open()){
        cout << "ERROR: EL ARCHIVO Pacientes.TXT NO PUDO ABRIRSE" << endl;
        exit(1);
    }
    ifstream archCitas("Citas.txt", ios::in);
    if(not archCitas.is_open()){
        cout << "ERROR: EL ARCHIVO Citas.TXT NO PUDO ABRIRSE" << endl;
        exit(1);
    }
    ofstream archReporte("ReporteDeCitasPorPaciente.txt", ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: EL ARCHIVO ReporteDeCitasPorPaciente.TXT NO PUDO ABRIRSE" << endl;
        exit(1);
    }
    
    imprimirReporte(archMedicos, archPacientes, archCitas, archReporte);
    
    return 0;
}

