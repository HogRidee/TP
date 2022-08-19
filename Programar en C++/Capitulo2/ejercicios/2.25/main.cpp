/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 19 de agosto de 2022, 11:52
 */

#include <iostream>

using namespace std;

/*
 * Este programa resuelve los ejercicios 2.25
 */
int main(int argc, char** argv) {

    int a = 0; //primer numero a evaluar
    int b = 0; //segundo numero a evaluar
    
    cout << "Ingrese 2 numeros para determinar si el primero es multiplo del ";
    cout << "segundo: ";
    cin  >> a >> b;
    
    if ( a % b == 0 ) {
        cout << "El primer numero es multiplo del segundo." << endl;
    }
    if ( a % b != 0 ) {
        cout << "El primer numero no es multiplo del segundo." << endl;
    }
    
    return 0;
}

