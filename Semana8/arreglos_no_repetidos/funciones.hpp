/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: erasmog
 *
 * Created on October 3, 2022, 1:00 AM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include <iostream>
#include <fstream>
#include <iomanip>
#define MAX_PROFESORES 50
#define NO_ENCONTRADO -1
using namespace std;
void cambiar_enteros(int *, int, int);
void procesar_ordenar_arreglos(int *, int *, int);
int busca_posicion_profesor(int *, int, int);
void pasa_palabra(ifstream &, char);
void leer_arch_profesores(int *, int *, int &);
void leer_insertar_profesor(int *,int *, int,int,int &);
void imprimir_reporte_profesores(int *, int *, int);

#endif /* FUNCIONES_HPP */

