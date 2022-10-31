/* 
 * File  :   funciones.hpp
 * Autor :   Ivan Alexander Araoz Andrade
 * Codigo:   20201216
 *
 * Creado el 30 de octubre de 2022, 17:23
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#define MAXDATOS 2500
#define TAMLINEA 50

using namespace std;

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

void imprimirLinea(char , int , ofstream &);
void imprimirResumenGeneros(ofstream &, char **, int );
void imprimirCanciones(ofstream &, char **, char **, int *, char **, double *, 
        int );
void cambiarStr(char *&, char *&);
void cambiarD(double *, int , int );
void cambiarI(int *, int , int );
void ordenarArreglos(char **, char **, int *, char **, double *, int );
void leerLinea(ifstream &, char *&, char *&, int &, char *&, double &);
void leerArchivoMusica(char **, char **, int *, char **, double *, int &, 
        const char *);

#endif /* FUNCIONES_HPP */

