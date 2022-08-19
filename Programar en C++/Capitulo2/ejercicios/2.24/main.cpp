/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 19 de agosto de 2022, 11:47
 */

#include <iostream>

using namespace std;

/*
 * Este programa resuelve los ejercicios 2.24
 */
int main(int argc, char** argv) {

    int numero = 0; //numero a evaluar
    
    cout << "Ingrese un numero para determinar si es par o impar: ";
    cin  >> numero;
    
    if ( numero % 2 == 0 ){
        cout << "El numero es par." << endl;
    }
    
    if ( numero % 2 != 0 ){
        cout << "El numero es impar." << endl;
    }
    
    return 0;
}

