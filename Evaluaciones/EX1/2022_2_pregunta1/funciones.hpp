/* 
 * File  :   funciones.hpp
 * Autor :   Ivan Alexander Araoz Andrade
 * Codigo:   20201216
 *
 * Creado el 17 de octubre de 2022, 17:02
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#define TAMLINEA 80

using namespace std;

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

void imprimirLinea(char , int , ofstream &);
int convertirFecha(int , int , int );
void desconvertirFecha(int , int &, int &, int &);
void imprimirMejorTikTok(ofstream &, ifstream &, int , int, int);
void imprimirCadena(ofstream &, ifstream &);
void imprimirResumen(ofstream &, int , int , int , int , int , double &);
void imprimirPais(ofstream &, ifstream &, int );
void buscarUsuario(ofstream &, ifstream &, int , int , bool &);
void procesarComentarios(ofstream &, ifstream &, ifstream &, ifstream &, int &, 
        int &, int &, int &, int &, int &);
void imprimirComentariosResumen(ofstream &, ifstream &, ifstream &, ifstream &, 
        int , int, int, double &, int &, int &);
void imprimirCabecera(ofstream &, int );
void preguntarImprimirFechas(ofstream &, int &, int &);
void procesarReporte(ofstream &, ifstream &, ifstream &, ifstream &, ifstream &);

#endif /* FUNCIONES_HPP */

