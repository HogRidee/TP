
/* 
 * File:   Funciones.hpp
 * Author: IVAN ALEXANDER ARAOZ ANDRADE 20201216
 *
 * Created on 3 de octubre de 2022, 01:05 PM
 */
using namespace std;

#include <iostream>
#include <fstream>
#include <iomanip>

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

void imprimirLinea(char , int , ofstream &);
void cambiarD(double *, int , int );
void cambiarI(int *, int , int );
void cambiarI(int *, int , int );
void ordenarArreglos(int *, int *, int , double *, double *);
void imprimirResumen(ofstream &, int *, double *, double *, int );
void imprimirArreglos(ofstream &, int *, int *, int , double *, double *);
void imprimirCabecera(ofstream &);
void imprimirReporte(int *, int *, int , double *, double *);
double calcularGasto(int , double , double , double );
int comprobarRepetido(int *, int , int );
void asignarArreglos(int *, int *, double *, double *, int &, double , double , 
        double , int , int , double );
double calcularTiempo(int , int , int , int , int , int );
void leerCitas(double &, double &, double &, int &, int *, int *, double *, double *);

#endif /* FUNCIONES_HPP */

