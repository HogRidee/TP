/* 
 * File  :  NumerosComplejos.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 29 de agosto de 2022, 17:01
 */

#include <iostream>
#include <iomanip>
#include "NumerosComplejos.hpp"

using namespace std;

void sumar(double a, double b, double c, double d, double &real, double 
&imaginario){
    //en c++ ya no necesitamos usar los parámetros por referencia con *
    real = a + c;
    imaginario = b + d;
}

void restar(double a, double b, double c, double d, double &real, double 
&imaginario){
    //en c++ ya no necesitamos usar los parámetros por referencia con *
    real = a - c;
    imaginario = b - d;
}

void multiplicar(double a, double b, double c, double d, double &real, double 
&imaginario){
    //en c++ ya no necesitamos usar los parámetros por referencia con *
    real = a * c - b * d;
    imaginario = a * d + b * c;
}

void dividir(double a, double b, double c, double d, double &numReal, double 
&numImg, double &denominador){
    //en c++ ya no necesitamos usar los parámetros por referencia con *
    denominador = c * c + d * d;
    numReal = (a * c + b * d)/denominador;
    numImg = (b * c - a * d)/denominador;
    
}

void potenciar(double a, double b, int n, double &real, double &imaginario){
    double resA = 0.0, resB = 0.0, c, d;
    int cont = n;
    c = a;
    d = b;
    while (cont > 1){
        multiplicar(a, b, c, d, resA, resB);
        c = resA;
        d = resB;
        cont--;
    }
    if (cont > 0){
        real = resA;
        imaginario = resB;
    }
    if (n == 1){
        real = a;
        imaginario = b;
    }
    if (n == 0){
        real = 1;
        imaginario = 0;
    }
}
