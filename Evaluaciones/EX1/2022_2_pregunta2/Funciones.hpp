/* 
 * File  :   Funciones.hpp
 * Autor :   Ivan Alexander Araoz Andrade
 * Codigo:   20201216
 *
 * Creado el 18 de octubre de 2022, 19:26
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#define MAXTIKTOKS 1000
#define MAXUSUARIOS 100
#define TAMLINEA 105
#define NOENCONTRADO -1

using namespace std;

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

int convertirFecha(int , int , int );
int buscarPosicion(int *, int , int);
int buscarUsuario(int *, int *, int , int , int );
void desconvertirFecha(int , int &, int &, int &);
void imprimirLinea(char , int , ofstream &);
void cambiarB(bool *, int, int);
void cambiarD(double *, int , int );
void cambiarI(int *, int , int );
void imprimirResumen(ofstream &, bool *, int );
void ordenarArreglos(int *, int *, int *, int *, double *, bool *, int *, int );
void imprimirDetallado(ofstream &, int *, int *, int *,int *, double *, bool *, 
        int *, int);
void imprimirCabecera(ofstream &, int , int );
void calcularViralidad(int *, int *, int *, double *, bool *, int , int *);
void procesarComentarios2(int *, int *, int *, int *, int *, bool *, int ,int , 
        ifstream &);
void procesarComentarios(int *, int *, int *, int *, int *, int *, bool *, int ,
        int );
void leerUsuarios(int *, int *, bool *, int &);
void verificarRepetidos(int *, int *, int ,int , int &);
void leerTikToks(int , int , int *, int *, int &);
void leerRangoFechas(int &, int &);

#endif /* FUNCIONES_HPP */

