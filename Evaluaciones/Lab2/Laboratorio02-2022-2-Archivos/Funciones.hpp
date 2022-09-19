
/* 
 * File:   Funciones.hpp
 * Author: 20201216 IVAN ARAOZ
 *
 * Created on 19 de septiembre de 2022, 01:16 PM
 */

using namespace std;

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

void imprimirLinea(char , int , ofstream &);
void imprimirMedico(ifstream &, ofstream &, int , double &);
void imprimirCitas(ifstream &, ifstream &, ofstream &, int );
void imprimirPaciente(ifstream &, ofstream &, int );
void imprimirCabeceraPaciente(ofstream &);
void imprimirCabecera(ofstream &);
void imprimirReporte(ifstream &, ifstream &, ifstream &, ofstream &);


#endif /* FUNCIONES_HPP */

