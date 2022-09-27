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
void almacenar_datos(ifstream &, int *, double *, int &);
void imprimircabecera(ofstream &, int *);
void lecturacabecera(ifstream &, int *);
void lectura(ifstream &, int *, double *, char *, bool *, int &);
void imprimir(ofstream &, int *, double *, char *, bool *, int &);
#endif /* FUNCIONES_HPP */

