/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   auxiliares.hpp
 * Author: erasmog
 *
 * Created on October 19, 2022, 2:18 PM
 */

#ifndef AUXILIARES_HPP
#define AUXILIARES_HPP
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
void imprime_linea(ofstream &, char, int);
void apertura_archivo(ifstream &);
void apertura_archivo(ofstream &);
void lectura_cadena_estatica(ifstream &, ofstream &);
void lectura_cadena_dinamica(ifstream &);
#endif /* AUXILIARES_HPP */

