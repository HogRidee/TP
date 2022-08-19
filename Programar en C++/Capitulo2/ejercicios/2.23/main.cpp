/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 19 de agosto de 2022, 11:36
 */

#include <iostream>

using namespace std;

/*
 * Este programa resuelve los ejercicios 2.23
 */
int main(int argc, char** argv) {

    int a = 0; //lista de enteros a evaluar 
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    
    cout << "Ingrese cinco enteros: ";
    cin  >> a >> b >> c >> d >> e;
    
    if ( a > b and a > c and a > d and a > e ){
        cout << "El numero mayor es " << a << endl;
    }
    if ( b > a and b > c and b > d and b > e ){
        cout << "El numero mayor es " << b << endl;
    }
    if ( c > a and c > b and c > d and c > e ){
        cout << "El numero mayor es " << c << endl;
    }
    if ( d > a and d > b and d > c and d > e ){
        cout << "El numero mayor es " << d << endl;
    }
    if ( e > a and e > b and e > c and e > d ){
        cout << "El numero mayor es " << e << endl;
    }
    
    if ( a < b and a < c and a < d and a < e ){
        cout << "El numero menor es " << a << endl;
    }
    if ( b < a and b < c and b < d and b < e ){
        cout << "El numero menor es " << b << endl;
    }
    if ( c < a and c < b and c < d and c < e ){
        cout << "El numero menor es " << c << endl;
    }
    if ( d < a and d < b and d < c and d < e ){
        cout << "El numero menor es " << d << endl;
    }
    if ( e < a and e < b and e < c and e < d ){
        cout << "El numero menor es " << e << endl;
    }
    
    return 0;
}

