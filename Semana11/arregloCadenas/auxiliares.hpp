/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   auxiliares.hpp
 * Author: erasmog
 *
 * Created on October 24, 2022, 2:43 AM
 */

#ifndef AUXILIARES_HPP
#define AUXILIARES_HPP
#define MAX_DATOS 3000
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
void pasar_minusculas(char* );
void imprime_linea(ofstream &,char , int);
void eliminar_guiones(char *);
void lectura_emision_reporte(ifstream &);
void leer_canciones_csv(char **, char**, int *,double *,int &,const char *);
void imprime_datos(char **, char**, int *,double *,int ,const char *);
void ordenar_arreglos(char **, char **, int *, double *, int);
#endif /* AUXILIARES_HPP */

