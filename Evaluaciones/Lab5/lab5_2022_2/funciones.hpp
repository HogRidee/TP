/* 
 * File  :   funciones.hpp
 * Autor :   Ivan Alexander Araoz Andrade
 * Codigo:   20201216
 *
 * Creado el 8 de noviembre de 2022, 20:20
 */

#include "Docente.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#define MAXMIEMBROS 200
#define TAMLINEA 165

using namespace std;

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

void imprimirLinea(char, int, ofstream &);
void cambiarStr(char *&, char *&);
void cambiarD(double *, int, int);
void cambiarI(int *, int , int );
void imprimirResumen(ofstream &, double , double );
void imprimirDocentes(ofstream &, struct Docente *, int , char *, char **);
void imprimirCabeceraDocente(ofstream &);
void imprimirResumenAlumno(ofstream &, double );
void imprimirAlumnos(ofstream &, char *, int *, char **, char **, char **, 
        char **, int *, double *, double *, double *, int );
void imprimirCabeceraAlumno(ofstream &);
void ordenarAlumnos(char *, int *, char **, char **, char **, char **, int *, 
        double *, double *, double *, int );
double calcularEgresos(struct Docente *, char *, int );
double calcularIngresos(double *, char *, int );
void leerDocente(ifstream &, struct Docente *, int );
void leerAlumno(ifstream &, int *, char **, char **, char **, int *, double *, 
        double *, int );
void leerNombre(ifstream &, char **, int );

#endif /* FUNCIONES_HPP */

