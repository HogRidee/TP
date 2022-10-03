/* 
 * File  :   Funciones.hpp
 * Autor :   Ivan Alexander Araoz Andrade
 * Codigo:   20201216
 *
 * Creado el 27 de septiembre de 2022, 12:39
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#define TAMLINEA 70

using namespace std;

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

void imprimirClientes(int *, int *, double *, int , ofstream &);
void ordenarProductos(int *, double *, double *, double *, int );
void imprimirProductos(int *, double *, double *, double *, int , ofstream &);
void imprimirLinea(char , int , ofstream& );
void ordenarClientesPorTotal(int *, int *, double *, int );
void imprimirCabecera(ofstream &);
void buscarCliente(double *, int *, int , int , double );
int comprobarRepetido(int *, int , int );
void leerProducto(int *, double *, double *, double *, double *, int *, int &, 
        int , int , double , double , int );
void leerPedidos(int *, double *, double *, double *, double *, int &, int *,
        int);
void cambiarD(double *, int , int );
void cambiarI(int *, int , int );
void ordenarClientes(int *, int *, int );
void leerClientes(int *, int *, int &);

#endif /* FUNCIONES_HPP */

