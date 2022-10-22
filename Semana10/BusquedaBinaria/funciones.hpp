/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: erasmog
 *
 * Created on October 18, 2022, 7:06 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#define MAX_PROFESORES 100
#define NO_ENCONTRADO -1
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
int busqueda_binaria(int *, int, int);
int buscar_posicion(int *, int, int);
void intercambiar_entero(int *, int, int);
void intercambiar_double(double *, int, int);
void insertar_en_arreglos(int *, int *, int *, double *, int, int, double, int &);
void leer_arch_profesores(int *, int *, int *, double *, int &);
void ordenar_arreglos(int *, int *, int *, double *, int &);
void imprimir_reporte(int *, int *, int *, double *, int);
void imprimir_busqueda(int *, int *, int *, double *, int, int);


#endif /* FUNCIONES_HPP */

