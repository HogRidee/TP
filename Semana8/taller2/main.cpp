/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 7 de octubre de 2022, 04:02 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

#include "Funciones.hpp"

/*
 * PREGUNTA 1 ARCHIVOS
 */
int main(int argc, char** argv) {

    ifstream archFechas("fechas.txt", ios::in);
    if(not archFechas.is_open()){
        cout << "ERROR: fechas.txt" << endl;
        exit(1);
    }
    ifstream archSueldos("sueldos.txt", ios::in);
    if(not archSueldos.is_open()){
        cout << "ERROR: sueldos.txt" << endl;
        exit(1);
    }
    ifstream archProfesores("profesores.txt", ios::in);
    if(not archProfesores.is_open()){
        cout << "ERROR: profesores.txt" << endl;
        exit(1);
    }
    ifstream archCursos("cursos.txt", ios::in);
    if(not archCursos.is_open()){
        cout << "ERROR: cursos.txt" << endl;
        exit(1);
    }
    ofstream archReporte("Reporte.txt", ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: Reporte.txt" << endl;
        exit(1);
    }
    
    procesarReporte(archFechas, archSueldos, archProfesores, archCursos, 
            archReporte);
    
    return 0;
}

