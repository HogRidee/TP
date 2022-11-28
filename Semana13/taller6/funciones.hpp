/* 
 * File:   funciones.hpp
 * Author: Ivan
 *
 * Created on 23 de noviembre de 2022, 10:08
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Movimiento.hpp"
#include "Pokemon.hpp"

using namespace std;

#define TAMLINEA 60

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

void imprimirLinea(char , int , ofstream &);
void imprimirMovimientos(ofstream &, struct Pokemon );
int buscarPosicion(int , struct Pokemon *, bool);
void imprimirResumen(ofstream &, struct Pokemon *, struct Pokemon *, int, int);
void imprimirEquipos(ofstream &, struct Pokemon *, struct Pokemon *);
void imprimirCabecera(ofstream &);
void imprimirBatallaPokemon(struct Pokemon *, int );
void AsignarMovimiento(ifstream &, int , struct Pokemon &);
void asignarMovimientos(struct Pokemon *, int );
void leerLineaPokemon(ifstream &, struct Pokemon &);
void leerPokemones(struct Pokemon *, int &);

#endif /* FUNCIONES_HPP */

