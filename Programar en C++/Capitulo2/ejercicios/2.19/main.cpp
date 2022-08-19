/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 19 de agosto de 2022, 10:11
 */

#include <iostream>

using namespace std;

/*
 * Este programa resuelve los ejercicios del 2.19
 */
int main(int argc, char** argv) {
    
    int a = 0; //primer entero a evaluar
    int b = 0; //primer entero a evaluar
    int c = 0; //primer entero a evaluar
    
    cout << "Introduzca tres enteros distintos ";
    cin  >> a >> b >> c;
    
    cout << "La suma es " << a + b + c << endl;
    cout << "El promedio es " << (a + b + c)/3 << endl;
    cout << "El producto es " << a * b * c << endl;
    
    if ( a < b and a < c)
        cout << "El menor es " << a << endl;
    if ( b < a and b < c)
        cout << "El menor es " << b << endl;
    if ( c < a and c < b)
        cout << "El menor es " << c << endl;
    
    if ( a > b and a > c)
        cout << "El mayor es " << a << endl;
    if ( b > a and b > c)
        cout << "El mayor es " << b << endl;
    if ( c > a and c > b)
        cout << "El mayor es " << c << endl;
    
    return 0;
}

