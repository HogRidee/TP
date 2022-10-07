/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: u_eeggcc
 *
 * Created on 7 de octubre de 2022, 07:06 AM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#define MAX_FECHAS 100
#define NO_ENCONTRADO -1
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
void intercambiar_entero(double *,int, int);
void intercambiar_double(double *,int, int);
void insertar_datos(int *, int *, int*, double*, int, int , double, int &);
void pasa_palabra(ifstream &, char);
void leer_archivo_profesores(int *, int *, int*, double*, int&);
void ordenar_arreglos(int *, int *, int*, double*, int);
void imprimir_reporte(int *, int *, int*, double*, int);

#endif /* FUNCIONES_HPP */

