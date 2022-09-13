/* 
 * File  :   Funciones.hpp
 * Autor :   Ivan Alexander Araoz Andrade
 * Codigo:   20201216
 *
 * Creado el 6 de septiembre de 2022, 19:16
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

void imprimirLinea(char, int, ofstream &);
void imprimirCabecera(ifstream &, ofstream &);
int leerEntero(ifstream &, int );
void leerPedido(ifstream &, ofstream &);
void leerEImprimirDescuentos(ifstream &, ofstream &, double &, double &, double &,
        int &, double &, int &, double &);

#endif /* FUNCIONES_HPP */

