/* 
 * File  :  NumerosComplejos.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 31 de agosto de 2022, 12:41
 */

#include <iostream>
#include <iomanip>
#include "NumerosComplejos.hpp"

using namespace std;

void sumarComplejos(double &numReal, double &numImg, double numRealTemporal, 
        double numImgTemporal){
    numReal = numReal + numRealTemporal;
    numImg  = numImg  + numImgTemporal;
}

void restarComplejos(double &numReal, double &numImg, double numRealTemporal, 
        double numImgTemporal){
    numReal = numReal - numRealTemporal;
    numImg  = numImg  - numImgTemporal;
}

void multiplicarComplejos(double &numReal, double &numImg, double numRealTemporal, 
        double numImgTemporal){
    //almacenan los resultados para luego asignarlos
    double componente1 = 0.0;
    double componente2 = 0.0;
    
    componente1 = numReal * numRealTemporal + numImg * numImgTemporal;
    componente2 = numImg * numRealTemporal - numReal * numImgTemporal;
    
    numReal = componente1;
    numImg  = componente2;
}

void dividirComplejos(double &numReal, double &numImg, double numRealTemporal, 
        double numImgTemporal){
    
    double numerador1   = 0.0;
    double denominador = 0.0;
    double numerador2   = 0.0;
    
    numerador1   = numReal * numRealTemporal + numImg * numImgTemporal;
    denominador  = numRealTemporal * numRealTemporal + numImgTemporal * 
            numImgTemporal;
    
    numerador2 = numImg * numRealTemporal - numReal * numImgTemporal;
    
    numReal = numerador1/denominador;
    numImg  = numerador2/denominador;
}

void potenciarComplejo(double &numReal, double &numImg, int exponente){
    
    double numRealTemporal = numReal;
    double numImgTemporal  =  numImg;
    
    for (int contador = 1; contador < exponente; contador++){
        multiplicarComplejos(numReal, numImg, numRealTemporal, numImgTemporal);
    }
}