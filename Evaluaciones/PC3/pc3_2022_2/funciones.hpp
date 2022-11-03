/* 
 * File  :   funciones.hpp
 * Autor :   Ivan Alexander Araoz Andrade
 * Codigo:   20201216
 *
 * Creado el 3 de noviembre de 2022, 14:50
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#define MAXCOMENTARIOS 100000
#define MAXPAISES 200
#define MAXUSUARIOS 200
#define TAMLINEA 100

using namespace std;

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

void imprimirLinea(char , int , ofstream &);
int buscarUsuario(int , int , int *, int *, int );
int buscarPais(int , int *, int );
void cambiarI(int *, int , int );
void cambiarStr(char *&, char *&);
void imprimirResumen(ofstream &, int , int *, int );
void imprimirDetallado(ofstream &, int *, int *, char **, char **, char **, int );
void imprimirCabecera(ofstream &);
void ordenarArreglos(int *, int *, char **, char **, char **, int );
void leerComentario(ifstream &, char **, int );
void procesarComentarios(int *, char **, int , int *, int *,char **, int , int *,
        char **, char **, char **, int &, ifstream &, int, int *);
void procesarArchivoComentarios(int *, char **, int , int *, int *,char **, int , int *,
        int *, char **, char **, char **, int &);
void leerArchivoUsuarios(int *, int *, char **, int &);
void leerArchivoPaises(int *, char **, int &);

#endif /* FUNCIONES_HPP */

