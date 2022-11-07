/* 
 * File  :   funciones.hpp
 * Autor :   Ivan Alexander Araoz Andrade
 * Codigo:   20201216
 *
 * Creado el 4 de noviembre de 2022, 16:50
 */

#include "Cancion.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#define MAXCANCIONES 5000
#define TAMLINEA 130
#define MAXGENEROS 100

using namespace std;

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

void imprimirLinea(char , int , ofstream &);
void imprimirReporte(struct Cancion *, int , int *, char **, int );
int buscarGenero(char *, char **, int );
void contarGeneros(char *, int *, char **, int &);
void leerLinea(ifstream &, struct Cancion &);
void leerCanciones(struct Cancion *, int &, int *, char **, int &);

#endif /* FUNCIONES_HPP */

