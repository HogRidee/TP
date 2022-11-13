/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   functions.hpp
 * Author: u_eeggcc
 *
 * Created on 11 de noviembre de 2022, 08:02 AM
 */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "pokemon.hpp"

using namespace std;

char * assignStr(const char*);
void read_line_pokemon(ifstream &, struct Pokemon &);
void readPokemons(const char *,const char *);

#endif /* FUNCTIONS_HPP */

