/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 19 de agosto de 2022, 9:14
 */

#include <iostream>

using namespace std;

/*
 * Este es un programa que resuelve los ejercicios 4 del capítulo 2 (2.4)
 */
int main(int argc, char** argv) {
    
    // a)
    cout << "El siguiente programa calculara el producto de tres enteros. \n";
    // b)
    int x = 0;
    int y = 0;
    int z = 0;
    int resultado = 0;
    // c), d)
    cout << "Por favor, ingrese el primer entero: ";
    cin  >> x;
    cout << "Por favor, ingrese el segundo entero: ";
    cin  >> y;
    cout << "Por favor, ingrese el tercer entero: ";
    cin  >> z;
    // debió usarse cin >> x >> y >> z;
    // e)
    resultado = x * y * z;
    // f) 
    cout << "El producto es: " << resultado << endl;
    // g)
    return 0;
}

