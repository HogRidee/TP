/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 23 de agosto de 2022, 7:34
 */

#include <iostream>
#include <iomanip>
#include "funcionesMatematicas.h"

using namespace std;

/*
 * Este programa evalúa el factorial de un número ingresado por el usuario
 */
int main(int argc, char** argv) {
    
    //inicialización, numero a evaluar y su factorial respectivamente
    int num  = 0;
    int fact = 0;
    
    cout << "Ingrese el numero a evaluar (factorial): ";
    cin  >> num;
    
    fact = factorial(num);
    
    cout << "El factorial de " << num << " es " << fact << endl;
    
    return 0;
}

