/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 19 de agosto de 2022, 9:46
 */

#include <iostream>

using namespace std;

/*
 * Este programa resuelve la pregunta 16 del capítulo 2 (2.16)
 */
int main(int argc, char** argv) {
    
    int a = 0; //es el primer número a evaluar
    int b = 0; //es el segundo número a evaluar
    int suma       = 0;
    int diferencia = 0;
    int producto   = 0;
    int cociente   = 0;
    
    cout << "Ingrese dos numeros enteros: ";
    cin  >> a >> b;
    
    suma       = a + b;
    diferencia = a - b;
    producto   = a * b;
    cociente   = a / b;
    
    cout << "La suma es: " << suma << endl;
    cout << "La diferencia es: " << diferencia << endl;
    cout << "El producto es: " << producto << endl;
    cout << "El cociente es: " << cociente << endl;
    
    return 0;
}

