/* 
 * File  :   funciones.hpp
 * Autor :   Ivan Alexander Araoz Andrade
 * Codigo:   20201216
 *
 * Creado el 4 de noviembre de 2022, 12:52
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#define MAXAUTORES 200
#define MAXLIBROS 300

using namespace std;

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

void leerLibro(ifstream &, char **, char **, double &, int );
void procesarArchivoLibros(int *, char **, char **, double *, int &, int *, 
        double *, char **, char **, int &, char **, char **, int );
void leerArchivoAutores(char **, char **, int &);

#endif /* FUNCIONES_HPP */

