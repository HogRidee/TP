/* 
 * File:   funciones.hpp
 * Author: u_eeggcc
 *
 * Created on 23 de septiembre de 2022, 07:02 AM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP


#include <iostream>
#include <fstream>

using namespace std;
int buscar_posicion(int *, int, int);
double buscar_valor(int *, double *, int, int);
void ordenar_arreglos(int *,double *, int);
void procesarDatos(int *, double *, int);
void actualizarInformacionEspecifica(int *, int, int);
void actualizarInformacion(int *, double *, int);
void lecturaArchivoSearch(int *, double *, int &);
void imprimircabecera(ofstream &, int *);
void lecturacabecera(ifstream &, int *);
void lecturaArchivoInput(int *, double *, char *, bool *, int &);
void imprimirordenado(int *, double *, int);
void imprimirreporte(int *, double *, char *, bool *, int &);
#endif /* FUNCIONES_HPP */

