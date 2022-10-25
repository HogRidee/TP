/* 
 * File  :   funciones.hpp
 * Autor :   Ivan Alexander Araoz Andrade
 * Codigo:   20201216
 *
 * Creado el 24 de octubre de 2022, 16:20
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#define TAMLINEA 340
#define MAXCAR 200

using namespace std;

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

void imprimirLinea(char , int , ofstream &);
void buscarUsuario(ifstream &, int , int , char *);
void imprimirAutor2(ofstream &, ifstream &, int , int );
void imprimirComentario2(ofstream &, char *);
void imprimirAutor1(ofstream &, ifstream &, int , int );
void imprimirComentario1(ofstream &, char *);
void leerComentarios(ofstream &, ifstream &, ifstream &);
void imprimirCabeceraTikTok(ofstream &, int , int , int );
void procesarComentarios(ofstream &, ifstream &, ifstream &);
void imprimirCabecera(ofstream &);
void procesarReporte();

#endif /* FUNCIONES_HPP */

