/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: alulab14
 *
 * Created on 21 de octubre de 2022, 04:09 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#define MAXCAR 100
#define TAMLINEA 52

using namespace std;

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

void imprimirLinea(char , int , ofstream &);
void imprimirResumen(ofstream &, int ,int);
void imprimirCabecera(ofstream &);
void procesarCadenas(ofstream &, char *, char *);
void procesarReporte();

#endif /* FUNCIONES_HPP */

