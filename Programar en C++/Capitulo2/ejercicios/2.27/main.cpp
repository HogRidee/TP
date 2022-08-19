/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 19 de agosto de 2022, 12:03
 */

#include <iostream>

using namespace std;

/*
 * Este programa resuelve los ejercicios 2.27
 */
int main(int argc, char** argv) {
    
    char caracter = 0; //caracter a evaluar
    
    cout << "Ingrese un caracter: ";
    cin  >> caracter;
    
    cout << static_cast < int > (caracter) << endl;
    
    return 0;
}

