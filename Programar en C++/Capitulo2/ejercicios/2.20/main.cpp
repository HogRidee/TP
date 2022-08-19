/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 19 de agosto de 2022, 10:21
 */

#include <iostream>
#define PI 3.14159

using namespace std;

/*
 * Este programa resuelve los ejercicios 2.20
 */
int main(int argc, char** argv) {
    
    int radio = 0; // radio del círculo a evaluar
    
    cout << "Ingrese el radio de un circulo: ";
    cin  >> radio;
    
    cout << "El diametro es: " << 2 * radio << endl;
    cout << "La circunferencia es: " << (2 * radio) * PI << endl;
    cout << "El area es: " << PI * (radio * radio) << endl;
    
    return 0;
}

