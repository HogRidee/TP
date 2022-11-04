/* 
 * File:   auxiliares.hpp
 * Author: u_eeggcc
 *
 * Created on 21 de octubre de 2022, 07:48 AM
 */

#ifndef AUXILIARES_HPP
#define AUXILIARES_HPP
#define MAX_TAM_CADENA 100
#define MAX_TAM_ARTISTA 40
#define MAX_TAM_CANCION 40
#define MAX_DATOS 2500
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
void lectura_arch_canciones_csv(char **, char **, int *, double *, int &, const char *);
void  imprime_linea(ofstream &, char , int );
void lectura_canciones(ifstream &, ofstream &);
void lectura_impresion_reporte(ifstream &, ofstream &);
void procesar_arreglos_csv(char **, char **,int *,double *,int cantidad);
void emtir_reporte(char **, char **,int *,double *,int cantidad);
#endif /* AUXILIARES_HPP */

