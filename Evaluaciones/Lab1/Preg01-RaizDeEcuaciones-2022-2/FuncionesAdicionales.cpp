/* 
 * File  :  FuncionesAdicionales.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 5 de septiembre de 2022, 13:24
 */

#include "FuncionesAdicionales.hpp"

double calculaFuncion(double x, double co5, double co4, double co3, double co2,
        double co1, double co0) {
    double fx;
    fx = co5*potencia(x,5) + co4*potencia(x,4) + co3*potencia(x,3) +
            co2*potencia(x,2) + co1*x + co0;
    return fx;
}

double potencia(double x, int n){
    double p = 1.0;
    for(int i=0; i<n; i++)
        p *= x;
    return p;
}

