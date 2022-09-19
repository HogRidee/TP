/* 
 * File  :   Funciones.hpp
 * Autor :   Ivan Alexander Araoz Andrade
 * Codigo:   20201216
 *
 * Creado el 14 de septiembre de 2022, 14:53
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

void imprimirResumen(ofstream &, int , int , int , int ,int , int , int , int ,
        double, int, int, int);
int calcularTiempoLlovido(int , int , int , int , int , int );
void imprimirReporte(ifstream &, ofstream &);
char convertirMayuscula(char );
void imprimirFrase(ifstream &, ofstream &, char);
void imprimirCabecera(ifstream &, ofstream &, int );
void leerImprimirArchivos(ifstream &, ofstream &);


#endif /* FUNCIONES_HPP */

