/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 19 de agosto de 2022, 10:01
 */

#include <iostream>

using namespace std;

/*
 * Este programa resuelve los ejercicios 2.18
 */
int main(int argc, char** argv) {
    
    int a = 0; //primer número a evaluar
    int b = 0; //segundo número a evaluar
    
    cout << "Ingrese dos numeros enteros: ";
    cin  >> a >> b;
    
    if ( a < b ){
        cout << b << " es mas grande \n";
    }
    if ( b < a ){
        cout << a << " es mas grande \n";
    }
    if ( a == b ){
        cout << "Estos numeros son iguales \n";
    }
    
    return 0;
}

