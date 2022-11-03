/* 
 * File  :   funciones.hpp
 * Autor :   Ivan Alexander Araoz Andrade
 * Codigo:   20201216
 *
 * Creado el 31 de octubre de 2022, 13:38
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#define MAXESCALAS 20
#define MAXCURSOS 50
#define TAMLINEA 120

using namespace std;

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

void imprimirLinea(char , int , ofstream &);
double buscarEscala(char **, double *, char *, int );
double buscarCreditos(char *, char **, double *, int );
double contarCreditos(ifstream &, char **, double *, int );
void imprimirCabeceraBoletas(ofstream &, int );
int calcularNumeroCuotas(char *);
void imprimirCabeceraAlumno(ofstream &, int , int , char *, char *);
void leerLineaMatricula(ifstream &, int *, char *&, char *&);
void imprimirCabecera(ofstream &);
void procesarMatricula(char **, double *, int , char **, double *, int );
void leerLineaCurso(ifstream &, char *&, double &);
void leerCursos(char **, double *, int &);
void leerLineaEscala(ifstream &, char *&, double &);
void leerEscalas(char **, double *, int &);

#endif /* FUNCIONES_HPP */

