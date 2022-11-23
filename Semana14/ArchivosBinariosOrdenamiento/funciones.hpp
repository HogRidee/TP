/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: erasmog
 *
 * Created on November 11, 2022, 1:39 AM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

char * assignStr(const char *);
void read_line_pokemon(ifstream &,struct Pokemon &);
void readPokemons(const char *, const char *);
void printPokemon(struct Pokemon);
void printPokemons(const char *);
void printPokemonByID(const char *, int);
void sortPokemon(const char *filename_in);

#endif /* FUNCIONES_HPP */

