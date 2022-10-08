/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.hpp
 * Author: alulab14
 *
 * Created on 7 de octubre de 2022, 04:02 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

using namespace std;
#include <iostream>
#include <fstream>
#include <iomanip>

void imprimirLinea(char , int , ofstream &);
void buscarMayorSueldo(ofstream &, ifstream &, int );
void imprimirResumenFecha(ofstream &, double , int );
double buscarCurso(ifstream &, int );
void buscarCursos(ofstream &, ifstream &, ifstream &);
void buscarImprimirProfesor(ofstream &, ifstream &, int , bool &);
void buscarSueldo(ifstream &, ifstream &, ifstream &, int , int , int, int &, double &, 
        int &);
void imprimirFecha(ofstream &, int , int , int , int , char );
void imprimirCabecera(ofstream &);
void procesarReporte(ifstream &, ifstream &, ifstream &, ifstream &, ofstream &);

#endif /* FUNCIONES_HPP */

