/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 23 de agosto de 2022, 7:30
 */

#include <iostream>

using namespace std;

/*
 * Este programa resuelve operaciones básicas para dos enteros ingresados
 */
int main(int argc, char** argv) {
    
    int a = 0;
    int b = 0;
    
    cout << "Ingrese dos numeros enteros: ";
    cin  >> a >> b;
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    
    return 0;
}

